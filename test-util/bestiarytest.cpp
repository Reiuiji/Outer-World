
#include <iostream>
#include <iomanip>
#include <string>
#include "bestiary.h"

#define MaxArray 3
int main()
{
    Bestiary Test[MaxArray] =
    {
        // Bestiary(std::string NAME, int LVL, int HP, int MP, int ATK, int DEF, int MATK, int MDEF, int SPD, int LUK, int WEAKNESSES, int RESISTANCES)
        Bestiary("Monster 1",1,2,3,4,5,6,7,8,9,0,0),
        Bestiary("Monster 2",2,4,6,2,4,6,2,4,6,1,0),
        Bestiary("Monster 3",3,5,7,3,5,7,3,5,7,2,0),
    };

int x = 0;

std::cout << "+--------------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;
std::cout << "|Name:               | LVL | H P | M P | ATK | DEF |M ATK|M DEF| SPD | LUK | WKN | RES |" << std::endl;
std::cout << "+--------------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;

for(x=0; x<MaxArray ; x++)
{
            std::cout << std::left  << std::setfill(' ') << "|" << std::setw(20)
            << Test[x].NAME()        << std::setw(5) << "|"
            << Test[x].LVL()         << std::setw(5) << "|"
            << Test[x].HP()          << std::setw(5) << "|"
            << Test[x].MP()          << std::setw(5) << "|"
            << Test[x].ATK()         << std::setw(5) << "|"
            << Test[x].DEF()         << std::setw(5) << "|"
            << Test[x].MATK()        << std::setw(5) << "|"
            << Test[x].MDEF()        << std::setw(5) << "|"
            << Test[x].SPD()         << std::setw(5) << "|"
            << Test[x].LUK()         << std::setw(5) << "|"
            << Test[x].WEAKNESSES()  << std::setw(5) << "|"
            << Test[x].RESISTANCES() << "|" << std::endl;
}
std::cout << "+--------------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;

    return 0;

}
