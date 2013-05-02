#include <string>
class Bestiary
{
public:
    Bestiary();
    Bestiary(std::string NAME, int HP, int MP, int ATK, int DEF, int MATK, int MDEF, int SPD, int LUK, int WEAKNESSES, int RESISTANCES);

    std::string NAME();
    int HP();
    int MP();
    int ATK();
    int DEF();
    int MATK();
    int MDEF();
    int SPD();
    int LUK();
    int WEAKNESSES();
    int RESISTANCES();

private:
     std::string MonsterName;
     int MonsterHp;
     int MonsterMp;
     int MonsterAtk;
     int MonsterDef;
     int MonsterMatk;
     int MonsterMdef;
     int MonsterSpd;
     int MonsterLuk;
     int MonsterWeak;
     int MonsterResist;
    };
