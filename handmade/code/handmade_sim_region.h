#if !defined(HANDMADE_SIM_REGION_H)

struct move_spec
{
    bool32 UnitMaxAccelVector;
    real32 Speed;
    real32 Drag;
};

enum entity_type
{
    EntityType_Null,
    
    EntityType_Hero,
    EntityType_Wall,
    EntityType_Familiar,
    EntityType_Monster,
    EntityType_Sword,
    EntityType_Stairwell,
    
};

#define HIT_POINT_SUB_COUNT 4
struct hit_point
{
    // TODO: Bake this down into one variable
    uint8 Flags;
    uint8 FilledAmount;
};

// TODO: Rename sim_entity to entity
struct sim_entity;
union entity_reference
{
    sim_entity *Ptr;
    uint32 Index;
};

enum sim_entity_flags
{
    EntityFlag_Collides = (1 << 0),
    EntityFlag_Nonspatial = (1 << 1),
    EntityFlag_Moveable = (1 << 2),
    EntityFlag_ZSupported = (1 << 4),
    
    EntityFlag_Simming = (1 << 30),
};

struct sim_entity
{
    // NOTE: These are only for the sim region
    world_chunk *FromChunk;
    uint32 StorageIndex;
    bool32 Updatable;

    entity_type Type;
    uint32 Flags;
    
    v3 P;
    v3 dP;

    real32 DistanceLimit;

    v3 Dim;

    uint32 FacingDirection;
    real32 tBob;

    // NOTE: This is for "stairs"
    int32 dAbsTileZ;

    // TODO: Should hitpoints themselves be entities?
    uint32 HitPointMax;
    hit_point HitPoint[16];

    entity_reference Sword;

    // TODO: Only for stairwells!
    real32 WalkableHeight;

    // TODO: Generation index so we know how up to date this entity
    // is.
};

struct sim_entity_hash
{
    sim_entity *Ptr;
    uint32 Index;
};

struct sim_region
{

    // TODO: Need a hash table here to map stored entity indeces to
    // sim entities!
    
    world *World;
    real32 MaxEntityRadius;
    real32 MaxEntityVelocity;
    
    world_position Origin;
    rectangle3 Bounds;
    rectangle3 UpdatableBounds;
    
    uint32 MaxEntityCount;
    uint32 EntityCount;
    sim_entity *Entities;

;
    
    // TODO: Do I really want a hash for this?
    // NOTE: Must be a power of 2
    sim_entity_hash Hash[4096];
    
};


#define HANDMADE_SIM_REGION_H
#endif
