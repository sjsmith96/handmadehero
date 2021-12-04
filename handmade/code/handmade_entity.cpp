inline move_spec
DefaultMoveSpec(void)
{
    move_spec Result = {};
    
    bool32 UnitMaxAccelVector = false;
    real32 Speed = 1.0f;
    real32 Drag = 0.0f;

    return Result;
    
}

inline void
UpdateFamiliar(sim_region *SimRegion, sim_entity *Entity, real32 dt)
{
    sim_entity *ClosestHero = 0;
    real32 ClosestHeroDsq = Square(10.0f); // NOTE: 10 meter maximum search

    // TODO: Make spatial queries easy for things!
    sim_entity *TestEntity = SimRegion->Entities;
    for(uint32 TestEntityIndex = 0;
        TestEntityIndex < SimRegion->EntityCount;
        ++TestEntityIndex)
    {
        if(TestEntity->Type == EntityType_Hero)
        {
            real32 TestDsq = LengthSq(TestEntity->P - Entity->P);
            if(TestEntity->Type == EntityType_Hero)
            {
                TestDsq *= 0.75f;
            }
            if(ClosestHeroDsq > TestDsq)
            {
                ClosestHero = TestEntity;
                ClosestHeroDsq = TestDsq;
            }
        }
    }

    v2 ddP = {};
    if(ClosestHero && (ClosestHeroDsq > Square(3.0f)))
    {
        real32 Acceleration = 0.5f;
        real32 OneOverLength = Acceleration / SquareRoot(ClosestHeroDsq);
        ddP =  OneOverLength * (ClosestHero->P - Entity->P);
    }

    
    move_spec MoveSpec = DefaultMoveSpec();
    MoveSpec.UnitMaxAccelVector = true;
    MoveSpec.Speed = 50.0f;
    MoveSpec.Drag = 8.0f;

    MoveEntity(SimRegion, Entity, dt, &MoveSpec, ddP);
}


inline void
UpdateMonster(sim_region *SimRegion, sim_entity *Entity, real32 dt)
{
}


inline void
UpdateSword(sim_region *SimRegion, sim_entity *Entity, real32 dt)
{
        
    move_spec MoveSpec = DefaultMoveSpec();
    MoveSpec.UnitMaxAccelVector = false;
    MoveSpec.Speed = 0.0f;
    MoveSpec.Drag = 0.0f;

    v2 OldP = Entity->P;
    MoveEntity(SimRegion, Entity, dt, &MoveSpec, V2(0, 0));
    real32 DistanceTraveled = Length(Entity->P - OldP);

    Entity->DistanceRemaining -= DistanceTraveled;
    if(Entity->DistanceRemaining < 0.0f)
    {
        Assert(!"NEED TO MAKE ENTITIES BE ABLE TO NOT BE THERE!");
    }
}
