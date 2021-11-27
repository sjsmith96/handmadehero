#if !defined(HANDMADE_PLATFORM_H)
/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Casey Muratori $
   $Notice: (C) Copyright 2014 by Molly Rocket, Inc. All Rights Reserved. $
   ======================================================================== */
/* NOTE:

   HANDMADE_INTERNAL:
   0 - Build for public release
   1 - Build for developer only

   HANDMADE_SLOW
   0 - No slow code allowed
   1 - Slow code welcome
*/

#ifdef __cplusplus
extern "C" {
#endif

//
// NOTE: Compilers
//
#ifndef COMPILER_MSVC
#define COMPILER_MSVC 0
#endif

#ifndef COMPILER_LLVM
#define COMPILER_LLVM 0
#endif

#if !COMPILER_MSVC && !COMPILER_LLVM
#if _MSC_VER
#undef COMPILER_MSVC
#define COMPILER_MSVC 1
#else
// TODO: More compilers!!!
#undef COMPILER_LLVM
#define COMPILER_LLVM 1
#endif
#endif

#if COMPILER_MSVC
#include <intrin.h>
#endif
//
// NOTE: Types
//
#include <stdint.h>
#include <stddef.h>
    
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef int32 bool32;

typedef size_t memory_index;

typedef float real32;
typedef double real64;

    
#define internal static 
#define local_persist static
#define global_variable static

    
#define Pi32 3.14159265359f


#if HANDMADE_SLOW
// TODO: Complete assertion macro
#define Assert(Expression) if(!(Expression)) {*(int *)0 = 0;}
#else
#define Assert(Expression)
#endif

#define InvalidCodePath Assert(!"InvalidCodePath");

#define Kilobytes(Value) ((Value) * 1024LL)
#define Megabytes(Value) (Kilobytes(Value) * 1024LL)
#define Gigabytes(Value) (Megabytes(Value) * 1024LL)
#define Terabytes(Value) (Gigabytes(Value) * 1024LL)

//IMPORTANT: NEVER USE ARRAYCOUNT ON A STRING
#define ArrayCount(Array) sizeof(Array) / sizeof((Array)[0])
/* TODO: Swap min_, max_, ... macros??? */

inline uint32
SafeTruncateuInt64(uint64 Value)
{
    // TODO: Defines for Maximum values uInt32Max
    Assert(Value <= 0xFFFFFFFF);
    uint32 Result = (uint32)Value;
    return Result;
}


   
/*
  NOTE: Services that the platform layer provides to the game.
*/
#if HANDMADE_INTERNAL
/* IMPORTANT:

   These are NOT for doing anything in the shipping game - they are
   blocking and the write doesn't protect against lost data.
*/


typedef struct thread_context
{
    int Placeholder;
    
} thread_context;

typedef struct debug_read_file_result
{
    uint32 ContentsSize;
    void *Contents;
} debug_read_file_result;

#define DEBUG_PLATFORM_FREE_FILE_MEMORY(name) void name(thread_context *Thread, void *Memory)  /* define the function protoype */
    typedef DEBUG_PLATFORM_FREE_FILE_MEMORY(debug_platform_free_file_memory); /* typedef using the function signature macro we just made */


#define DEBUG_PLATFORM_READ_ENTIRE_FILE(name) debug_read_file_result name(thread_context *Thread, char *Filename)  /* define the function protoype */
    typedef DEBUG_PLATFORM_READ_ENTIRE_FILE(debug_platform_read_entire_file); /* typedef using the function signature macro we just made */


#define DEBUG_PLATFORM_WRITE_ENTIRE_FILE(name) bool32 name(thread_context *Thread, char *Filename, uint32 MemorySize, void* Memory)  /* define the function protoype */
    typedef DEBUG_PLATFORM_WRITE_ENTIRE_FILE(debug_platform_write_entire_file); /* typedef using the function signature macro we just made */



#endif


/*
  NOTE: Services that the game provides to the platform layer.
  (this may expand in the future - sound on seperate thread, etc.
*/

// FOUR THINGS - timer,  controller/keyboard input, bitmap buffer to use, sound buffer to use
// TODO : In the future, rendering specifically will become a three-tiered abstraction!!!

    typedef struct game_offscreen_buffer
    {
        // NOTE: Pixels are always 32-bits wide, Memory Order BB GG RR XX
        void *Memory;
        int Width;
        int Height;
        int Pitch;
    
        int BytesPerPixel;
    } game_offscreen_buffer;

    typedef struct game_sound_output_buffer
    {
        int SamplesPerSecond;
        int SampleCount;
        int16 *Samples;

    } game_sound_output_buffer;


    typedef struct game_button_state
    {
        int HalfTransitionCount;
        bool32 EndedDown;
    } game_button_state;

    typedef struct game_controller_input
    {
        bool32 IsConnected;
        bool32 IsAnalog;
        real32 StickAverageX;
        real32 StickAverageY;

        union
        {
            game_button_state Buttons[12];
            struct
            {
                game_button_state MoveUp;
                game_button_state MoveDown;
                game_button_state MoveLeft;
                game_button_state MoveRight;
            
                game_button_state ActionUp;
                game_button_state ActionDown;
                game_button_state ActionLeft;
                game_button_state ActionRight;
            
                game_button_state LeftShoulder;
                game_button_state RightShoulder;

                game_button_state Start;
                game_button_state Back;

                // NOTE: All buttons must be added above this line

                game_button_state Terminator;
            };
        };
    } game_controller_input;

    typedef struct game_input
    {

        game_button_state MouseButtons[5];
        int32 MouseX, MouseY, MouseZ;
    
        // TODO: Insert clock values here.

        real32 dtForFrame;
    
        game_controller_input Controllers[5];
    } game_input;


    typedef struct game_memory
    {
        bool32 IsInitialized;
    
        uint64 PermanentStorageSize;
        void *PermanentStorage; // NOTE: Required to be cleared to 0

        uint64 TransientStorageSize;
        void *TransientStorage; // NOTE: Required to be cleared to 0

        debug_platform_free_file_memory *DEBUGPlatformFreeFileMemory;
        debug_platform_read_entire_file *DEBUGPlatformReadEntireFile;
        debug_platform_write_entire_file *DEBUGPlatformWriteEntireFile;
    
    } game_memory;


#define GAME_UPDATE_AND_RENDER(name) void name(thread_context *Thread, game_memory *Memory, game_input *Input, game_offscreen_buffer *Buffer)  /* define the function protoype */
typedef GAME_UPDATE_AND_RENDER(game_update_and_render); /* typedef using the function signature macro we just made */


// NOTE: At the moment, this has to be a very fast function, it cannot be
// more than a millisecond or so.
// TODO: Reduce the pressure on this function's performance by measuring it
// or asking about it, etc.


#define GAME_GET_SOUND_SAMPLES(name) void name(thread_context *Thread, game_memory *Memory, game_sound_output_buffer *SoundBuffer)  /* define the function protoype */
typedef GAME_GET_SOUND_SAMPLES(game_get_sound_samples); /* typedef using the function signature macro we just made */

    
    
inline game_controller_input *GetController(game_input *Input, int ControllerIndex)
{
    Assert(ControllerIndex < ArrayCount(Input->Controllers));
    
    game_controller_input *Result = &Input->Controllers[ControllerIndex];
    return Result;

}


#ifdef __cplusplus
}
#endif

#define HANDMADE_PLATFORM_H
#endif
