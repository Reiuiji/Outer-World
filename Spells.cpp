#include "spells.h"
#include <string>



Spells::Spells(std::string NAME, std::string DESC, bool OFFENSIVE, int ELEMENT, int MP_LOSS, int DAMAGE, int STAT_GAIN, int HEALTH_GAIN)
{

        SpellName = NAME;
        SpellDesc = DESC;
        Offensive = OFFENSIVE;
        Element = ELEMENT;
        ManaCost = MP_LOSS;
        SpellDamage = DAMAGE;
        StatGain = STAT_GAIN;
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
int Spells::STAT_GAIN()
{
    return StatGain;
};
int Spells::HEALTH_GAIN()
{
    return HealthGain;
};
