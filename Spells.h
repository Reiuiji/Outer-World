#include <string>
class Spells
{
public:
    Spells();
    Spells(std::string NAME, std::string DESC, bool OFFENSIVE, int ELEMENT, int MP_LOSS, int DAMAGE,
          int ATK_GAIN, int DEF_GAIN, int MATK_GAIN, int MDEF_GAIN, int SPD_GAIN, int HEALTH_GAIN,
          int GET_LEARNED, int SET_LEARNED);

    std::string NAME();
    std::string DESC();
    bool OFFENSIVE();
    int ELEMENT();
    int MP_LOSS();
    int DAMAGE();

    int ATK_GAIN();
    int DEF_GAIN();
    int MATK_GAIN();
    int MDEF_GAIN();
    int SPD_GAIN();

    int HEALTH_GAIN();
    int GET_LEARNED();
    int SET_LEARNED();

private:
     std::string SpellName;
     std::string SpellDesc;
     bool Offensive;
     int Element;
     int ManaCost;
     int SpellDamage;

     int AtkGain;
     int DefGain;
     int MatkGain;
     int MdefGain;
     int SpdGain;

     int HealthGain;
     int Learned;
};
