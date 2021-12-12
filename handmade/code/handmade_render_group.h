#if !defined(HANDMADE_RENDER_GROUP_H)

struct render_basis
{
    v3 P;
};

struct render_entity_basis
{
    render_basis *Basis;
    v2 Offset;
    real32 OffsetZ;
    real32 EntityZC;
};

// NOTE: Render group entry is compact a discriminated union!
enum render_group_entry_type
{
    RenderGroupEntry_render_entry_clear,
    RenderGroupEntry_render_entry_bitmap,
    RenderGroupEntry_render_entry_rectangle,
    RenderGroupEntry_render_entry_coordinate_system,
};

// TODO: Remove the header
struct render_group_entry_header
{
    render_group_entry_type Type;
};

struct render_entry_clear
{
    render_group_entry_header Header;
    v4 Color;
};

struct render_entry_coordinate_system
{
    render_group_entry_header Header;
    v2 Origin;
    v2 XAxis;
    v2 YAxis;
    v4 Color;

    v2 Points[16];
};

struct render_entry_bitmap
{
    render_group_entry_header Header;
    render_entity_basis EntityBasis;
    loaded_bitmap *Bitmap;
    real32 R, G, B, A;

};

struct render_entry_rectangle
{
    render_group_entry_header Header;    
    render_entity_basis EntityBasis;
    real32 R, G, B, A;
    v2 Dim;

};

struct render_group
{
    render_basis *DefaultBasis;
    real32 MetersToPixels;

    uint32 PushBufferSize;
    uint32 MaxPushBufferSize;
    uint8 *PushBufferBase;
};


#define HANDMADE_RENDER_GROUP_H
#endif
