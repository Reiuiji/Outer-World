typedef struct room
{
    int             Room_Type;  //0=default;1=start; 2=end
    void*           ITEM_ptr;
    void*           MOB_ptr;
    void*           Event_ptr;
    struct room*    North;
    struct room*    East;
    struct room*    South;
    struct room*    West ;
    struct room*    NextFloor;
    struct room*    PrevFloor;
} ROOM;

typedef struct Dungeon
{
    char            Dungeon_Name;
    int             FLOOR_NUM;
    void*           MOB_RATE;
    void*           ITEM_RATE;
    struct room*    Entrance;
    struct room*    BOSS;
} DUNGEON;

class Generator
{
public:
    Dungeon DungeonGen();
    void MobGen();
    void ItemGen();
};
