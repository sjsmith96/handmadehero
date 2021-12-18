#if !defined(HANDMADE_H)
/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Casey Muratori $
   $Notice: (C) Copyright 2014 by Molly Rocket, Inc. All Rights Reserved. $
   ======================================================================== */

/*
  TODO:

  ARCHITECTURE EXPLORATION
  - Z!
    - Figure out how you go "up" and "down" and how is this rendered?

  - Collision detection?
    - Entry/exit?
    - What's the plan for robustness / shape definition?
  - Implement multiple sim regions per frame
    - Per-entity clocking
    - Sim region merging? For multiple players?

  - Debug code
    - Logging
    - Diagramming
    - (A LITTLE GUI, but only a little!) Switches / sliders / etc.
   
  - Audio
    - Sound effect triggers
    - Ambient sounds
    - Music
  - Asset streaming
      
  - Metagame / save game?
    - How do you enter a "save slot"?
    - Persistant unlocks/etc.
    - Do we allow saved games? Probably yes, just only for "pausing",
    * Continuous save for crash recovery?
  - Rudimentary world gen (no quality, just "what sorts of things" we do)
    - Placement of background things
    - Connectivity?
    - Non-overlapping?
      - Map display
        - Magnets - how they work?

            
  - AI
    - Rudimentary monster behaviour example
    * Pathfinding
    - AI "storage"

  * Animation - should probably lead into rendering
    - Particle Systems
    - Skeletal animation
     
 PRODUCTION
  - Rendering
  ->Game
    - Entity system
    - World generation

    
 */
#include "handmade_platform.h"


#define Minimum(A, B) ((A < B) ? (A) : (B))
#define Maximum(A, B) ((A > B) ? (A) : (B))

//
//
//


struct memory_arena
{
    memory_index Size;
    uint8 *Base;
    memory_index Used;

    int32 TempCount;
};

struct temporary_memory
{
    memory_arena *Arena;
    memory_index Used;
};

inline void
InitializeArena(memory_arena *Arena, memory_index Size, void *Base)
{
    Arena->Size = Size;
    Arena->Base = (uint8 *)Base;
    Arena->Used = 0;
    Arena->TempCount = 0;
}

#define PushStruct(Arena, type) (type *)PushSize_(Arena, sizeof(type))
#define PushArray(Arena, Count, type) (type *)PushSize_(Arena, (Count) * sizeof(type))
#define PushSize(Arena, Size) PushSize_(Arena, Size)
inline void *                
PushSize_(memory_arena *Arena, memory_index Size)
{

    Assert((Arena->Used + Size) <= Arena->Size);
    
    void *Result = Arena->Base + Arena->Used;
    Arena->Used += Size;
    
    return Result;
    
}

inline temporary_memory
BeginTemporaryMemory(memory_arena *Arena)
{
    temporary_memory Result = {};
    Result.Arena = Arena;
    Result.Used = Arena->Used;

    ++Arena->TempCount;
    return Result;
}

inline void
EndTemporaryMemory(temporary_memory TempMem)
{
    memory_arena *Arena = TempMem.Arena;
    Assert(Arena->Used >= TempMem.Used);
    Arena->Used = TempMem.Used;
    Assert(Arena->TempCount > 0);
    --Arena->TempCount;

}

inline void
CheckArena(memory_arena *Arena)
{
    Assert(Arena-> TempCount == 0);
}

#define ZeroStruct(Instance) ZeroSize(sizeof(Instance), &(Instance))
inline void
ZeroSize(memory_index Size, void *Ptr)
{
    // TODO: Check this guy for performance
    uint8 *Byte = (uint8 *) Ptr;
    while(Size--)
    {
        *Byte++ = 0;
    }
}

#include "handmade_intrinsics.h"
#include "handmade_math.h"
#include "handmade_world.h"
#include "handmade_sim_region.h"
#include "handmade_entity.h"
#include "handmade_render_group.h"

struct hero_bitmaps
{

    v2 Align;
    
    loaded_bitmap Head;
    loaded_bitmap Cape;
    loaded_bitmap Torso;
    
    
};

struct low_entity
{
    // TODO: It's kind of busted that Ps can be invalid and we still
    // need to set the non_spatial flag.
    world_position P;
    sim_entity Sim;
};

struct controlled_hero
{
    uint32 EntityIndex;
    // NOTE: These are controller requests for simulation.
    v2 ddP;
    v2 dSword;
    real32 dZ;
};

struct pairwise_collision_rule
{
    bool32 CanCollide;
    uint32 StorageIndexA;
    uint32 StorageIndexB;

    pairwise_collision_rule *NextInHash;
};

struct game_state;
internal void AddCollisionRule(game_state *GameState, uint32 StorageIndexA, uint32 StorageIndexB, bool32 ShouldCollide);
internal void ClearCollisionRulesFor(game_state *GameState, uint32 StorageIndex);

struct ground_buffer
{
    // NOTE: An invalid P tells us that this ground buffer has not been filled.
    world_position P; // NOTE: This is the center of the bitmap
    loaded_bitmap Bitmap;
};

struct game_state
{

    memory_arena WorldArena;
    world *World;

    real32 TypicalFloorHeight;

    // TODO: Should we allow split-screen?
    uint32 CameraFollowingEntityIndex;
    world_position CameraP;

    controlled_hero ControlledHeroes[ArrayCount(((game_input *)0)->Controllers)];
    
    // TODO: Change the name to "stored entity"
    uint32 LowEntityCount;
    low_entity LowEntities[100000];

    loaded_bitmap Grass[2];
    loaded_bitmap Stone[4];
    loaded_bitmap Tuft[3];
   
    loaded_bitmap Backdrop;
    loaded_bitmap Shadow;
    
    hero_bitmaps HeroBitmaps[4];

    loaded_bitmap Tree;
    loaded_bitmap TreeNormal;
    loaded_bitmap Sword;
    loaded_bitmap Stairwell;
    real32 MetersToPixels;
    real32 PixelsToMeters;

    // TODO: Must be power of two
    pairwise_collision_rule *CollisionRuleHash[256];
    pairwise_collision_rule *FirstFreeCollisionRule;

    sim_entity_collision_volume_group *NullCollision;
    sim_entity_collision_volume_group *SwordCollision;
    sim_entity_collision_volume_group *StairCollision;
    sim_entity_collision_volume_group *PlayerCollision;
    sim_entity_collision_volume_group *MonsterCollision;
    sim_entity_collision_volume_group *WallCollision;
    sim_entity_collision_volume_group *FamiliarCollision;
    sim_entity_collision_volume_group *StandardRoomCollision;

    real32 Time;

    loaded_bitmap TestDiffuse;
    loaded_bitmap TestNormal;
};

struct transient_state
{
    bool32 IsInitialized;
    memory_arena TranArena;    
    uint32 GroundBufferCount;
    ground_buffer *GroundBuffers;

    uint32 EnvMapWidth;
    uint32 EnvMapHeight;
    // NOTE: 0 is bottom, 1 is middle, 2 is top
    environment_map EnvMaps[3];
    
};


inline low_entity *
GetLowEntity(game_state *GameState, uint32 LowIndex)
{
    low_entity *Result = 0;
    
    if((LowIndex > 0) && (LowIndex < GameState->LowEntityCount))
    {
        Result = GameState->LowEntities + LowIndex;
    }
    
    return Result;
    
}


#define HANDMADE_H
#endif
