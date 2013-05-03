#include "Bestiary.h"
#include <string>

Bestiary::Bestiary(std::string NAME, int HP, int MP, int ATK, int DEF, int MATK, int MDEF, int SPD, int LUK, int WEAKNESSES, int RESISTANCES)
{
    MonsterName   = NAME;
    MonsterHp     = HP;
    MonsterMp     = MP;
    MonsterAtk    = ATK;
    MonsterDef    = DEF;
    MonsterMatk   = MATK;
    MonsterMdef   = MDEF;
    MonsterSpd    = SPD;
    MonsterLuk    = LUK;
    MonsterWeak   = WEAKNESSES;
    MonsterResist = RESISTANCES;
};

std::string Bestiary::NAME()
{
    return MonsterName;
};

int Bestiary::HP()
{
    return MonsterHp;
};

int Bestiary::MP()
{
    return MonsterMp;
};

int Bestiary::ATK()
{
    return MonsterAtk;
};

int Bestiary::DEF()
{
    return MonsterDef;
};
int Bestiary::MATK()
{
    return MonsterMatk;
};
int Bestiary::MDEF()
{
    return MonsterMdef;
};
int Bestiary::SPD()
{
    return MonsterSpd;
};

int Bestiary::LUK()
{
    return MonsterLuk;
};

int Bestiary::WEAKNESSES()
{
    return MonsterWeak;
};

int Bestiary::RESISTANCES()
{
    return MonsterResist;
};
