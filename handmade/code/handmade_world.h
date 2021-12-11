#if !defined(HANDMADE_WORLD_H)
/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Casey Muratori $
   $Notice: (C) Copyright 2014 by Molly Rocket, Inc. All Rights Reserved. $
   ======================================================================== */


struct world_position
{
    // TODO: It seems like we have to store ChunkX/Y/Z with each
    // entity because even though the sim region gather doesn't need
    // it at first and we could get by without it, the entity
    // references pull in entities WITHOUT going through their
    // world_chunk, and thus still need to know the ChunkX/Y/Z.

    int32 ChunkX;
    int32 ChunkY;
    int32 ChunkZ;

    // NOTE: These are the offsets from the chunk center
    v3 Offset_;
    
};


// TODO: COuld make this just tile_chunk and allow multiple tile chunks per x/y/z
struct world_entity_block
{
    uint32 EntityCount;
    uint32 LowEntityIndex[16];
    world_entity_block *Next;
};

struct world_chunk
{
    int32 ChunkX;
    int32 ChunkY;
    int32 ChunkZ;

    // TODO: Profile this and determine if a pointer would be better here!
    // NOTE: Singly linked list
    world_entity_block FirstBlock;
    
    world_chunk *NextInHash;
};

struct world
{

    v3 ChunkDimInMeters;

    // TODO: WorldChunkHash should probably switch to pointers IF
    // tile entity blocks continue to be stored en masse directly in the tile chunk
    // NOTE: At the moment, this must be a power of 2.
    
    world_chunk ChunkHash[4096];

    world_entity_block *FirstFree;

};

#define HANDMADE_WORLD_H
#endif
