/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Casey Muratori $
   $Notice: (C) Copyright 2014 by Molly Rocket, Inc. All Rights Reserved. $
   ======================================================================== */

#if 0
/*
inline uint32
GetTileValueUnchecked(tile_map *TileMap, tile_chunk *TileChunk, int32 TileX, int32 TileY)
{
    Assert(TileChunk);
    Assert(TileX < TileMap->ChunkDim);
    Assert(TileY < TileMap->ChunkDim);
           
    
    uint32 TileChunkValue = TileChunk->Tiles[TileY*TileMap->ChunkDim + TileX];
    return TileChunkValue;
}

inline void
SetTileValueUnchecked(tile_map *TileMap, tile_chunk *TileChunk, int32 TileX, int32 TileY,
                      uint32 TileValue)
{
    Assert(TileChunk);
    Assert(TileX < TileMap->ChunkDim);
    Assert(TileY < TileMap->ChunkDim);
           
    
    TileChunk->Tiles[TileY*TileMap->ChunkDim + TileX] = TileValue;
}


inline uint32
GetTileValue(tile_map *TileMap, tile_chunk *TileChunk,
             uint32 TestTileX, uint32 TestTileY)
{
    uint32 TileChunkValue = 0;

    if(TileChunk && TileChunk->Tiles)
    {
        TileChunkValue = GetTileValueUnchecked(TileMap, TileChunk, TestTileX, TestTileY);
        
    }

    return TileChunkValue;
   
}

inline void
SetTileValue(tile_map *TileMap, tile_chunk *TileChunk,
             uint32 TestTileX, uint32 TestTileY,
             uint32 TileValue)
{
    if(TileChunk && TileChunk->Tiles)
    {
        SetTileValueUnchecked(TileMap, TileChunk, TestTileX, TestTileY, TileValue);
        
    }

}


inline uint32
GetTileValue(tile_map *TileMap, uint32 AbsTileX, uint32 AbsTileY, uint32 AbsTileZ)
{

    tile_chunk_position ChunkPos = GetChunkPosition(TileMap, AbsTileX, AbsTileY, AbsTileZ);
    tile_chunk *TileChunk = GetTileChunk(TileMap, ChunkPos.TileChunkX, ChunkPos.TileChunkY, ChunkPos.TileChunkZ);
    uint32 TileChunkValue = GetTileValue(TileMap, TileChunk, ChunkPos.RelTileX, ChunkPos.RelTileY);
    
    return TileChunkValue;
   
}

inline uint32
GetTileValue(tile_map *TileMap, tile_map_position Pos)
{

    uint32 TileChunkValue = GetTileValue(TileMap, Pos.AbsTileX, Pos.AbsTileY, Pos.AbsTileZ);

    return TileChunkValue;
   
}

internal void
SetTileValue(memory_arena *Arena, tile_map *TileMap,
             uint32 AbsTileX, uint32 AbsTileY, uint32 AbsTileZ,
             uint32 TileValue)
{
        
    tile_chunk_position ChunkPos = GetChunkPosition(TileMap, AbsTileX, AbsTileY, AbsTileZ);
    tile_chunk *TileChunk = GetTileChunk(TileMap, ChunkPos.TileChunkX, ChunkPos.TileChunkY, ChunkPos.TileChunkZ, Arena);

            
}

internal bool32
IsTileValueEmpty(uint32 TileValue)
{
    bool32 Empty = ((TileValue == 1) ||
                    (TileValue == 3) ||
                    (TileValue == 4));

    return Empty;
}


internal bool32
IsTileMapPointEmpty(tile_map *TileMap, tile_map_position Pos)
{
    uint32 TileChunkValue = GetTileValue(TileMap, Pos.AbsTileX, Pos.AbsTileY, Pos.AbsTileZ);    
    bool32 Empty = IsTileValueEmpty(TileChunkValue);
    

    return Empty;
   
}

*/
#endif

