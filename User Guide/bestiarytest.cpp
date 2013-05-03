
#include <iostream>
#include <iomanip>
#include <string>
#include "bestiary.h"

#define MaxArray 31
int main()
{
    Bestiary Test[MaxArray] =
    {
                 // Name, HP, MP, ATK, DEF, MATK, MDEF, SPD, LUK, WKN, RES
                 // For STR and WKN: Earth = 1, Water = 2, Wind = 3, Fire = 4.
                 Bestiary("Wind Elemental",  10, 20, 1, 2, 3, 1, 4, 1, 1, 2),
                 Bestiary("Bats",            15, 00, 2, 2, 4, 2, 3, 1, 1, 2),
                 Bestiary("Ghoul",           13, 20, 2, 1, 2, 3, 2, 1, 1, 2),
                 Bestiary("Gryphon",         17, 20, 2, 2, 2, 4, 1, 1, 1, 2),
                 Bestiary("Harpy",           20, 25, 3, 1, 1, 4, 4, 2, 1, 2),
                 Bestiary("Water Elemental", 10, 20, 1, 2, 3, 1, 4, 1, 3, 4),
                 Bestiary("Slime",           15, 00, 2, 2, 4, 2, 3, 1, 3, 4),
                 Bestiary("Siren",           13, 20, 2, 1, 2, 3, 2, 1, 3, 4),
                 Bestiary("Merfolk",         17, 20, 2, 2, 2, 4, 1, 1, 3, 4),
                 Bestiary("Kraken",          20, 25, 3, 1, 1, 4, 4, 2, 3, 4),
                 Bestiary("Fire Elemental",  10, 20, 1, 2, 3, 1, 4, 1, 2, 1),
                 Bestiary("Goblin",          15, 00, 2, 2, 4, 2, 3, 1, 2, 1),
                 Bestiary("Minotaur",        13, 20, 2, 1, 2, 3, 2, 1, 2, 1),
                 Bestiary("Dwarf",           17, 20, 2, 2, 2, 4, 1, 1, 2, 1),
                 Bestiary("Dragon",          20, 25, 3, 1, 1, 4, 4, 2, 2, 1),
                 Bestiary("Earth Elemental", 10, 20, 1, 2, 3, 1, 4, 1, 4, 3),
                 Bestiary("Golem",           15, 00, 2, 2, 4, 2, 3, 1, 4, 3),
                 Bestiary("Elf",             13, 20, 2, 1, 2, 3, 2, 1, 4, 3),
                 Bestiary("Centaur",         17, 20, 2, 2, 2, 4, 1, 1, 4, 3),
                 Bestiary("Giant Ent",       20, 25, 3, 1, 1, 4, 4, 2, 4, 3),
                 Bestiary("Wraith",          18, 23, 3, 2, 2, 4, 4, 2, 0, 0),
                 Bestiary("Abomination",     18, 23, 3, 2, 2, 4, 4, 2, 0, 0),
                 Bestiary("Undead",          18, 23, 3, 2, 2, 4, 4, 2, 0, 0),
                 Bestiary("Behemoth",        18, 23, 3, 2, 2, 4, 4, 2, 0, 0),
                 Bestiary("Historic Knight", 25, 10, 4, 2, 2, 4, 4, 3, 0, 0),
                 Bestiary("Galactic Knight", 25, 10, 4, 2, 2, 4, 4, 3, 0, 0),
                 Bestiary("Time Mage",       20, 30, 2, 4, 4, 4, 4, 3, 0, 0),
                 Bestiary("Spacial Mage",    20, 30, 2, 4, 4, 4, 4, 3, 0, 0),
                 Bestiary("Vampire",         20, 25, 3, 1, 1, 4, 4, 2, 0, 0),
                 Bestiary("Werewolf",        20, 25, 3, 1, 1, 4, 4, 2, 0, 0),
                 Bestiary("Mad Programmer",  20, 25, 3, 1, 1, 4, 4, 2, 0, 0),
    };

    int x = 0;
    int y = 0;

    std::cout << "+--------------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;
    std::cout << "|Name:               | H P | M P | ATK | DEF |M ATK|M DEF| SPD | LUK | WKN | RES |" << std::endl;
    std::cout << "+--------------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;

    for(x=0; x<MaxArray ; x++)
    {
        std::cout << std::left  << std::setfill(' ') << "|" << std::setw(20)
                  << Test[x].NAME()        << std::setw(4) << "|"
                  << Test[x].HP()          << std::setw(4) << "|"
                  << Test[x].MP()          << std::setw(5) << "|"
                  << Test[x].ATK()         << std::setw(5) << "|"
                  << Test[x].DEF()         << std::setw(5) << "|"
                  << Test[x].MATK()        << std::setw(5) << "|"
                  << Test[x].MDEF()        << std::setw(5) << "|"
                  << Test[x].SPD()         << std::setw(5) << "|"
                  << Test[x].LUK()         << std::setw(5) << "|"
                  << Test[x].WEAKNESSES()  << std::setw(5) << "|"
                  << Test[x].RESISTANCES() << "|" << std::endl;

        y = Test[x].RESISTANCES();
    }
    std::cout << "+--------------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;
    y=y*5;
    std::cout << y;
    return 0;

}
