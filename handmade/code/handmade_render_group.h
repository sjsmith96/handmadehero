#if !defined(HANDMADE_RENDER_GROUP_H)

struct render_basis
{
    v3 P;
};

struct entity_visible_piece
{
    render_basis *Basis;
    loaded_bitmap *Bitmap;
    v2 Offset;
    real32 OffsetZ;
    real32 EntityZC;
    
    real32 R, G, B, A;
    v2 Dim;
};

struct render_group
{
    render_basis *DefaultBasis;
    real32 MetersToPixels;
    uint32 PieceCount;

    uint32 PushBufferSize;
    uint32 MaxPushBufferSize;
    uint8 *PushBufferBase;
};

inline void *
PushRenderElement(render_group *Group, uint32 Size)
{
    void *Result = 0;

    if((Group->PushBufferSize + Size) < Group->MaxPushBufferSize)
    {
        Result = (Group->PushBufferBase + Group->PushBufferSize);
        Group->PushBufferSize += Size;
    }
    else
    {
        InvalidCodePath;
    }

    return Result;
}

inline void
PushPiece(render_group *Group, loaded_bitmap *Bitmap,
          v2 Offset, real32 OffsetZ, v2 Align, v2 Dim, v4 Color, real32 EntityZC)
{

    entity_visible_piece *Piece = (entity_visible_piece *)PushRenderElement(Group, sizeof(entity_visible_piece));
    Piece->Basis = Group->DefaultBasis;
    Piece->Bitmap = Bitmap;
    Piece->Offset = Group->MetersToPixels * V2(Offset.X, - Offset.Y) - Align;
    Piece->OffsetZ = OffsetZ;
    Piece->EntityZC = EntityZC;
    Piece->R = Color.R;
    Piece->G = Color.G;
    Piece->B = Color.B;
    Piece->A = Color.A;
    Piece->Dim = Dim;
}

inline void
PushBitmap(render_group *Group, loaded_bitmap *Bitmap,
           v2 Offset, real32 OffsetZ, v2 Align, real32 Alpha = 1.0f, real32 EntityZC = 1.0f)
{
    PushPiece(Group, Bitmap, Offset, OffsetZ, Align, V2(0, 0), V4(1.0f, 1.0f, 1.0f, Alpha), EntityZC);
}


inline void
PushRect(render_group *Group, v2 Offset, real32 OffsetZ,
         v2 Dim, v4 Color, real32 EntityZC = 1.0f)
{
    PushPiece(Group, 0, Offset, OffsetZ, V2(0, 0), Dim, Color, EntityZC);
}



#define HANDMADE_RENDER_GROUP_H
#endif
