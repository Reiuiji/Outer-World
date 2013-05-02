#include <string>
class Spells
{
public:
    Spells();
    Spells(std::string NAME, std::string DESC, bool OFFENSIVE, int ELEMENT, int MP_LOSS, int DAMAGE, int STAT_GAIN, int HEALTH_GAIN);

    std::string NAME();
    std::string DESC();
    bool OFFENSIVE();

    int ELEMENT();
    int MP_LOSS();
    int DAMAGE();
    int STAT_GAIN();
    int HEALTH_GAIN();

private:
     std::string SpellName;
     std::string SpellDesc;
     bool Offensive;
     int Element;
     int ManaCost;
     int SpellDamage;
     int StatGain;
     int HealthGain;
};
