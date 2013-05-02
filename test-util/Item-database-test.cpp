#include <iostream>
#include <iomanip>
#include <string>
#include "item-database.h"

#define MaxArray 3
int main()
{
    Item Test[MaxArray] =
    {
        // Items are listed in this order: Name, Description, Type (1 = Weapon, 2 = Armor, 3 = Usable, 4 = Other), ATK stat, DEF stat, MATK stat, MDEG stat, owned?, and use.
        Item("Novice's Staff", "One of the staffs from my home. It's not good quality, but it works fine as a practice staff.", 1, -1, 0, 2, 0, false, 0),
        Item("Dragonscale Armor", "A set of armor created from the scales of a dragon. It's much nicer than I thought it would be.", 2, 40, 0, 40, 0, false, 0),
        Item("Testing","Desc", 1, 2, 3, 4, 5, false, 0),
    };

    int x = 0;

    std::cout << "+--------------------+" << std::setw(100) << std::setfill('-') << "-" << "+-----+-----+-----+-----+-----+-----+-----+" << std::endl;
    std::cout << "|Name:               |Description:   " << std::setw(100-15) << std::setfill(' ') <<  " " << "|TYPE | ATK | DEF |MATK |MDEF | OWN |FUNC |" << std::endl;
    std::cout << "+--------------------+" << std::setw(100) << std::setfill('-') <<  "-" << "+-----+-----+-----+-----+-----+-----+-----+" << std::endl;

    for(x=0; x<MaxArray ; x++)
    {
        std::cout << std::left << std::setfill(' ') << "|" << std::setw(20) << Test[x].NAME() << "|" << std::setw(100) << Test[x].DESC() << "|" << std::setw(5) << Test[x].TYPE() << "|" << std::setw(5) << Test[x].ATK() << "|" << std::setw(5) << Test[x].DEF() << "|" << std::setw(5) << Test[x].MATK() << "|" << std::setw(5) << Test[x].MDEF() << "|" << std::setw(5) << Test[x].OWN() << "|" << std::setw(5) << Test[x].FUNC() << "|" << std::endl;
    }
    std::cout << "+--------------------+" << std::setw(100) << std::setfill('-') <<  "-" << "+-----+-----+-----+-----+-----+-----+-----+" << std::endl;


    return 0;
}
