#include <iostream>
#include <iomanip>
#include <string>
#include "item-database.h"

#define MaxArray 3
int main()
{
    Item Test[MaxArray] =
    {   //    NAME,            DESC,                                                                                              TYPE, ATK, DEF, MATK, MDEF, FUNC, PRICE, BUYABLE, NUM_OWNED, BOUGHT)
        Item("Novice's Staff", "One of the staffs from my home. It's not good quality, but it works fine as a practice staff.",      1,  -1,   0,    2,    0,    0,     0,  false,         0,  false),
        Item("Dragonscale Armor", "A set of armor created from the scales of a dragon. It's much nicer than I thought it would be.", 2,  40,   0,   40,    0,    0,     0,  false,         0,  false),
        Item("Rusty Longsword","A rusted longsword. It's not professional, but professional isn't exactly what I'm aiming for.",     1,   2,   0,   -1,    0,    0,   100,   true,         0,  false),
    };

    int x = 0;

    std::cout << "+--------------------+" << std::setw(100) << std::setfill('-') << "-" << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;
    std::cout << "|Name:               |Description:   " << std::setw(100-15) << std::setfill(' ') <<  " " << "|TYPE | ATK | DEF |MATK |MDEF |FUNC |PRICE|BUYAB|OWNED|" << std::endl;
    std::cout << "+--------------------+" << std::setw(100) << std::setfill('-') <<  "-" << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;

    for(x=0; x<MaxArray ; x++)
    {
        std::cout << std::left << std::setfill(' ') << "|"
        << std::setw(20) << Test[x].NAME() << "|"
        << std::setw(100) << Test[x].DESC() << "|"
        << std::setw(5) << Test[x].TYPE() << "|"
        << std::setw(5) << Test[x].ATK() << "|"
        << std::setw(5) << Test[x].DEF() << "|"
        << std::setw(5) << Test[x].MATK() << "|"
        << std::setw(5) << Test[x].MDEF() << "|"
        << std::setw(5) << Test[x].FUNC() << "|"
        << std::setw(5) << Test[x].PRICE() << "|"
        << std::setw(5) << Test[x].BUYABLE() << "|"
        << std::setw(5) << Test[x].NUM_OWNED() << "|"
        << std::endl;
    }
    std::cout << "+--------------------+" << std::setw(100) << std::setfill('-') <<  "-" << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;

    std::cout << "\nThe Rusty Longsword's ownership is currently: " << Test[2].NUM_OWNED() << std::endl;
    std::cout << "This is me buying the Rusty Longsword: " << Test[2].BOUGHT() << std::endl;
    std::cout << "This is me buying the Rusty Longsword: " << Test[2].BOUGHT() << std::endl;
    std::cout << "This is me buying the Rusty Longsword: " << Test[2].BOUGHT() << std::endl;
    std::cout << "The ownership is now: " << Test[2].NUM_OWNED() << "\n";

    return 0;
}
