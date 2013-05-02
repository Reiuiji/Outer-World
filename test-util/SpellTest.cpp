#include <iostream>
#include <iomanip>
#include <string>
#include "Spells.h"

#define MaxArray 10
int main()
{
    Spells Test[MaxArray] =
    {
        //                                      ELEMENT, MP_LOSS, DAMAGE, ATK, DEF, MATK, MDEF, SPD, HEALTH_GAIN)
        Spells("Whirlwind",      "Desc 1",   true, 1, 25, 50,  0,  0,  0,  0,  0,   0, 0, 0),
        Spells("Fleet of Foot",  "Desc 2",  false, 1, 25,  0,  0,  0,  0,  0,  3,   0, 0, 0),

        Spells("Wildfire",       "Desc 3",   true, 2, 25, 50,  0,  0,  0,  0,  0,   0, 0, 0),
        Spells("Blind Fury",     "Desc 1",  false, 2, 25,  0,  3,  0,  3,  0,  0,   0, 0, 0),

        Spells("Quake",          "Desc 2",   true, 3, 25, 50,  0,  0,  0,  0,  0,   0, 0, 0),
        Spells("Fortify",        "Desc 3",  false, 3, 25,  0,  0,  3,  0,  3,  0,   0, 0, 0),

        Spells("Tsunami",        "Desc 1",   true, 4, 25, 50,  0,  0,  0,  0,  0,   0, 0, 0),
        Spells("Purify",         "Desc 2",  false, 4, 25,  0,  0,  0,  0,  0,  0,  50, 0, 0),

        Spells("Ultima",         "Desc 3",   true, 5,200,500,  0,  0,  0,  0,  0,   0, 0, 0),
        Spells("Time Shift",     "Desc 3",  false, 6,200,  0, 10, 10, 10, 10, 10, 100, 0, 0),
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
            << Test[x].HEALTH_GAIN() << std::setw(5) << "|" << std::endl;
}
std::cout << "+--------------------+--------------------+-----+-----+-----+-----+-----+-----+" << std::endl;

std::cout << "This is the status of the Tsunami Spell (0 = unlearned, 1 = learned): " << Test[7].GET_LEARNED() << std::endl;
std::cout << "This is player learning Tsunami Spell." << std::endl; Test[7].SET_LEARNED();
std::cout << "This is the status of the Tsunami Spell (0 = unlearned, 1 = learned): " << Test[7].GET_LEARNED() << std::endl;
    return 0;
}


