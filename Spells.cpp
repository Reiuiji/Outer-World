#include "spells.h"
#include <string>



Spells::Spells(std::string NAME, std::string DESC, bool OFFENSIVE, int ELEMENT, int MP_LOSS, int DAMAGE,
          int ATK_GAIN, int DEF_GAIN, int MATK_GAIN, int MDEF_GAIN, int SPD_GAIN, int HEALTH_GAIN)
{

        SpellName = NAME;
        SpellDesc = DESC;
        Offensive = OFFENSIVE;
        Element = ELEMENT;
        ManaCost = MP_LOSS;
        SpellDamage = DAMAGE;

        AtkGain = ATK_GAIN;
        DefGain = ATK_GAIN;
        MatkGain = ATK_GAIN;
        MdefGain = ATK_GAIN;
        SpdGain = ATK_GAIN;

        HealthGain = HEALTH_GAIN;

};

std::string Spells::NAME()
{
    return SpellName;
};
std::string Spells::DESC()
{
    return SpellDesc;
};
bool Spells::OFFENSIVE()
{
    return Offensive;
};
int Spells::ELEMENT()
{
    return Element;
};
int Spells::MP_LOSS()
{
    return ManaCost;
};
int Spells::DAMAGE()
{
    return SpellDamage;
};
int Spells::ATK_GAIN()
{
    return AtkGain;
};
int Spells::DEF_GAIN()
{
    return DefGain;
};
int Spells::MATK_GAIN()
{
    return MatkGain;
};
int Spells::MDEF_GAIN()
{
    return MdefGain;
};
int Spells::SPD_GAIN()
{
    return SpdGain;
};
int Spells::HEALTH_GAIN()
{
    return HealthGain;
};
