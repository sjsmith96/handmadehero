/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Casey Muratori $
   $Notice: (C) Copyright 2014 by Molly Rocket, Inc. All Rights Reserved. $
   ======================================================================== */

// TODO: Think about what the real safe margin is
#define TILE_CHUNK_SAFE_MARGIN (INT32_MAX/64)
#define TILE_CHUNK_UNINITIALIZED INT32_MAX

#define TILES_PER_CHUNK 16

inline bool32
IsCanonical(world *World, real32 TileRel)
{
    bool32 Result = ((TileRel >= -0.5f * World->ChunkSideInMeters) &&
                     (TileRel <= 0.5f * World->ChunkSideInMeters));
                      
    // TODO: Fix floating point math
    return Result;
}
        
inline bool32
IsCanonical(world *World, v2 Offset)
{
    bool32 Result = (IsCanonical(World, Offset.X) && IsCanonical(World, Offset.Y));
                      
    // TODO: Fix floating point math
    return Result;
}

inline bool32
AreInSameChunk(world *World, world_position *A, world_position *B)
{
    Assert(IsCanonical(World, A->Offset_));
    Assert(IsCanonical(World, B->Offset_));
    
    bool32 Result = ((A->ChunkX == B->ChunkX) &&
                     (A->ChunkY == B->ChunkY) &&
                     (A->ChunkZ == B->ChunkZ));
    
    return Result;
}


inline world_chunk *
GetWorldChunk(world *World, int32 ChunkX, int32 ChunkY, int32 ChunkZ,
             memory_arena *Arena = 0)
{
    Assert(ChunkX > -TILE_CHUNK_SAFE_MARGIN);
    Assert(ChunkY > -TILE_CHUNK_SAFE_MARGIN);
    Assert(ChunkZ > -TILE_CHUNK_SAFE_MARGIN);
    Assert(ChunkX < TILE_CHUNK_SAFE_MARGIN);
    Assert(ChunkY < TILE_CHUNK_SAFE_MARGIN);
    Assert(ChunkZ < TILE_CHUNK_SAFE_MARGIN);
    
    // TODO: BETTER HASH FUNCTION?????
    uint32 HashValue = 19*ChunkX + 7*ChunkY + 3*ChunkZ;
    uint32 HashSlot = HashValue & (ArrayCount(World->ChunkHash) - 1); // Get rid of all the extra bits in the hash value to make it value that will fit inside our hash table
    Assert(HashSlot < ArrayCount(World->ChunkHash));
    

    world_chunk *Chunk = World->ChunkHash + HashSlot;
    do 
    {
        
        if((ChunkX == Chunk->ChunkX) &&
           (ChunkY == Chunk->ChunkY) &&
           (ChunkZ == Chunk->ChunkZ))
        {
            
            break;
        }

        // We're supposed to allocate and this hash slot is occupied by a different chunk 
        if(Arena && (Chunk->ChunkX != TILE_CHUNK_UNINITIALIZED) && (!Chunk->NextInHash))
        {
            Chunk->NextInHash = PushStruct(Arena, world_chunk);
            Chunk = Chunk->NextInHash;
            Chunk->ChunkX = TILE_CHUNK_UNINITIALIZED;
        }
        
        // We're supposed to allocate and the hash slot is empty
        if(Arena && (Chunk->ChunkX == TILE_CHUNK_UNINITIALIZED))
        {
            Chunk->ChunkX = ChunkX;
            Chunk->ChunkY = ChunkY;
            Chunk->ChunkZ = ChunkZ;
          
            Chunk->NextInHash = 0;
            
            break;
        }
        
        Chunk = Chunk->NextInHash;
        
    }  while(Chunk);
    
    return Chunk;
}

internal void
InitializeWorld(world *World, real32 TileSideInMeters)
{

    World->TileSideInMeters = TileSideInMeters;
    World->ChunkSideInMeters = (real32)TILES_PER_CHUNK * TileSideInMeters;
    World->FirstFree = 0;

    for(uint32 ChunkIndex = 0;
        ChunkIndex < ArrayCount(World->ChunkHash);
        ++ChunkIndex)
    {
        World->ChunkHash[ChunkIndex].ChunkX = TILE_CHUNK_UNINITIALIZED;
        World->ChunkHash[ChunkIndex].FirstBlock.EntityCount = 0;
    }    

}


inline void
RecanonicalizeCoord(world *World, int32 *Tile, real32 *TileRel)
{
    // TODO: Need to do something that doesn't use the divide/multiply method
    // for recanonicalizing because this can end up rounding back on to the tile
    // you just came from.


    int32 Offset = RoundReal32ToInt32(*TileRel / World->ChunkSideInMeters);
    
    *Tile +=  Offset;
    *TileRel -= Offset * World->ChunkSideInMeters;

    Assert(IsCanonical(World, *TileRel));    

}

inline world_position
ChunkPositionFromTilePositon(world *World, int32 AbsTileX, int32 AbsTileY, int32 AbsTileZ)
{
    world_position Result = {};

    
    Result.ChunkX = AbsTileX / TILES_PER_CHUNK;
    Result.ChunkY = AbsTileY / TILES_PER_CHUNK;
    Result.ChunkZ = AbsTileZ / TILES_PER_CHUNK;

    // TODO: Decide on Tile alignment in Chunks!
    Result.Offset_.X = (real32)(AbsTileX - (Result.ChunkX*TILES_PER_CHUNK)) * World->TileSideInMeters;
    Result.Offset_.Y = (real32)(AbsTileY - (Result.ChunkY*TILES_PER_CHUNK)) * World->TileSideInMeters;
    // TODO: Move to 3D Z!

    return Result;
    
}

inline world_position
MapIntoChunkSpace(world *World, world_position BasePos, v2 Offset)
{

    world_position Result = BasePos;

    Result.Offset_ += Offset;
    RecanonicalizeCoord(World, &Result.ChunkX, &Result.Offset_.X);
    RecanonicalizeCoord(World, &Result.ChunkY, &Result.Offset_.Y);

    return Result;

}


inline world_difference
Subtract(world *World, world_position *A, world_position *B)
{
    world_difference Result = {};

    v2 dTileXY = {(real32)A->ChunkX - (real32)B->ChunkX,
        (real32)A->ChunkY - (real32)B->ChunkY};
    
    real32 dTileZ = (real32)A->ChunkZ - (real32)B->ChunkZ;

    Result.dXY = (World->ChunkSideInMeters * dTileXY) + (A->Offset_ - B->Offset_);
    

    //TODO: Think about what we want to do about Z
    Result.dZ = (World->ChunkSideInMeters * dTileZ) + 0.0f;

    return Result;
    
}

inline world_position
CenteredChunkPoint(uint32 ChunkX, uint32 ChunkY, uint32 ChunkZ)
{
    world_position Result = {};

    Result.ChunkX = ChunkX;
    Result.ChunkY = ChunkY;
    Result.ChunkZ = ChunkZ;

    return Result;
}

inline void
ChangeEntityLocation(memory_arena *Arena, world *World, uint32 LowEntityIndex,
                     world_position *OldP, world_position *NewP)
{
    if(OldP && AreInSameChunk(World, OldP, NewP))
    {
        // NOTE: We don't need to do anything here, its already in the same chunk
    }
    else
    {
        if(OldP)
        {
            // NOTE: Pull the entity out of its old entity block
            world_chunk *Chunk = GetWorldChunk(World, OldP->ChunkX, OldP->ChunkY, OldP->ChunkZ);
            Assert(Chunk); // NOTE: Someone called with a bogus position
            if(Chunk)
            {
                bool32 NotFound = true;
                world_entity_block *FirstBlock = &Chunk->FirstBlock;
                for(world_entity_block *Block = &Chunk->FirstBlock; 
                    Block && NotFound;
                    Block = Block->Next)
                {

                    for(uint32 Index = 0;
                        (Index < Block->EntityCount) && NotFound;
                        ++Index)
                    {
                        if(Block->LowEntityIndex[Index] == LowEntityIndex)
                        {
                                
                            Block->LowEntityIndex[Index] =
                                FirstBlock->LowEntityIndex[--FirstBlock->EntityCount];
                            // NOTE: There's only one block
                            if(FirstBlock->EntityCount == 0)
                            {
                                // NOTE: If removing this entity would remove the block entirely
                                if(FirstBlock->Next)
                                {
                                    world_entity_block *NextBlock = FirstBlock->Next;
                                    // This block becomes the next block (get rid of it)
                                    *FirstBlock = *NextBlock;
                                    
                                    NextBlock->Next = World->FirstFree;
                                    World->FirstFree = NextBlock;
                                }
                                        
                            }

                            NotFound = false;
                                
                        }
                    }
                }
            }
        }
            
    

        // NOTE: Insert the entity into its new entity block
        
        world_chunk *Chunk = GetWorldChunk(World, NewP->ChunkX, NewP->ChunkY, NewP->ChunkZ, Arena);
        world_entity_block *Block = &Chunk->FirstBlock;
        if(Block->EntityCount == ArrayCount(Block->LowEntityIndex))
        {
            // NOTE: We're out of room, get a new block!
            world_entity_block *OldBlock = World->FirstFree;
            if(OldBlock)
            {
                World->FirstFree = OldBlock->Next;
            }
            else
            {
                OldBlock = PushStruct(Arena, world_entity_block);
            }
                
            *OldBlock = *Block;
            Block->Next = OldBlock;
            Block->EntityCount = 0;
        }

        Assert(Block->EntityCount < ArrayCount(Block->LowEntityIndex));
        Block->LowEntityIndex[Block->EntityCount++] = LowEntityIndex;
            
            
            
    }
    
}
