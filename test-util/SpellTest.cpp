#include <iostream>
#include <iomanip>
#include <string>
#include "Spells.h"


// THIS TEST IS KIND OF SHITTY YOU MIGHT NEED TO REMAKE IT. THE FUNCTION WORKS FINE THOUGH.



#define MaxArray 3
int main()
{
    Spells Test[MaxArray] =
    {
        // Spells(std::string NAME, std::string DESC, bool OFFENSIVE, int ELEMENT, int MP_LOSS, int DAMAGE, int STAT_GAIN, int HEALTH_GAIN)
        Spells("Spell 1","Desc 1",false,1,10,4,6,2),
        Spells("Spell 2","Desc 2",false,2,20,5,6,7),
        Spells("Spell 3","Desc 3",false,3,30,5,7,3),
    };

int x = 0;

std::cout << "+--------------------+--------------------+-----+-----+-----+-----+-----+-----+" << std::endl;
std::cout << "|Name:               |Desc:               |BOOLE| ELE | M P | DAM | GAN |HPGAN|" << std::endl;
std::cout << "+--------------------+--------------------+-----+-----+-----+-----+-----+-----+" << std::endl;

for(x=0; x<MaxArray ; x++)
{
            std::cout << std::left  << std::setfill(' ') << "|" << std::setw(20)
            << Test[x].NAME()        << std::setw(15) << "|"
            << Test[x].DESC()        << std::setw(5) << "|"
            << Test[x].OFFENSIVE()   << std::setw(5) << "|"
            << Test[x].ELEMENT()     << std::setw(4) << "|"
            << Test[x].MP_LOSS()     << std::setw(5) << "|"
            << Test[x].DAMAGE()      << std::setw(5) << "|"
            << Test[x].STAT_GAIN()   << std::setw(5) << "|"
            << Test[x].HEALTH_GAIN() << std::setw(5) << "|" << std::endl;
}
std::cout << "+--------------------+--------------------+-----+-----+-----+-----+-----+-----+" << std::endl;

    return 0;

}
