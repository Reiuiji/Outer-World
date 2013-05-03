#include <iostream>
#include <iomanip>
#include <string>
#include "item-database.h"
#include <windows.h>

#define MaxArray 67
int main()
{
    Item Test[MaxArray] =
    {
        Item("Novice's Staff",            "One of the staffs from my home. It's not good quality, but it works fine as a practice staff.",                    1,  -1,   0,   2,   0,  0,     0, false, 1, false,  false),
        Item("Apprentice's Staff",        "A common staff from this world. It's not perfect, but it at least properly exerts my spells.",                     1,  -3,   0,   5,   0,  0,   500,  true, 0, false,  false),
        Item("Adept's Staff",             "This staff is quite similar to the one I wielded in my homeland. It is light, but useful.",                        1,  -7,   0,  11,   0,  0,  1000,  true, 0, false,  false),
        Item("Expert's Staff",            "A thick staff intended for those well versed in magic. It appears to be quite powerful.",                          1, -15,   0,  23,   0,  0,  3500,  true, 0, false,  false),
        Item("Master's Staff",            "A finely crafted staff. Its weight is perfect, and its charging capabilities are amazing.",                        1, -29,   0,  45,   0,  0,  7000,  true, 0, false,  false),
        Item("Staff of the Ancients",     "Quite possibly the greatest staff in the land. It is said that it was imbued with the abilities of the ancients.", 1, -35,   0,  60,   0,  0,     0, false, 0, false,  false),

        Item("Rusty Longsword",           "A rusted longsword. It's not professional, but professional isn't exactly what I'm aiming for.",                   1,   2,   0,  -1,   0,  0,   100,  true, 0, false, false),
        Item("Copper Longsword",          "A copper longsword. It's flimsy and its edges are quite dull.",                                                    1,   5,   0,  -3,   0,  0,   500,  true, 0, false, false),
        Item("Bronze Longsword",          "A bronze longsword. Not my weapon of choice, but it's useable.",                                                   1,  11,   0,  -7,   0,  0,  1000,  true, 0, false, false),
        Item("Iron Longsword",            "An iron longsword. Your run of the mill aim-stab-and-slash weapon.",                                               1,  23,   0, -15,   0,  0,  3500,  true, 0, false, false),
        Item("Steel Longsword",           "A steel longsword. A needed improvement over the iron ones. I feel like I could hurt someone with this thing.",    1,  23,   0, -15,   0,  0,  7000,  true, 0, false, false),
        Item("Excalibur",                 "I'm not entirely sure how I got this, nor how it's in this universe, but I'm not going to question it.",           1,  60,   0, -35,   0,  0,     0, false, 0, false, false),

        Item("Bronze Dagger",             "A bronze dagger. It allows me to remain armed whilst preparing my magic. It's better than nothing.",               1,   1,   0,   1,   0,  0,   200,  true, 0, false, false),
        Item("Iron Dagger",               "An iron dagger. Useful for opening letters, cutting dinner, and occasionally getting into a fight.",               1,   3,   0,   3,   0,  0,   700,  true, 0, false, false),
        Item("Steel Dagger",              "A steel dagger. I feel like whoever made this knew what they were doing, but they didn't do it right.",            1,   6,   0,   6,   0,  0,  1500,  true, 0, false, false),
        Item("Iron Shortsword",           "An iron shortsword. It's similar to the ones knights used to carry back in my homeland.",                          1,  12,   0,  12,   0,  0,  5000,  true, 0, false, false),
        Item("Steel Shortsword",          "A steel shortsword. It's similar to the ones the capable knights used to carry back in my homeland.",              1,  23,   0,  23,   0,  0,  8000,  true, 0, false, false),
        Item("Wakizashi",                 "Whomever made this weapon appears to have put great time and thought into their work.",                            1,  40,   0,  40,   0,  0,     0, false, 0, false, false),

        Item("Well-Worn Robes",           "My training robes. They've become tattered from years of use. All things considered, they are rather comfy.",      2,   0,  -1,   0,   3,  0,     0, false, 1, false, false),
        Item("Cloth Robes",               "Robes of a finer quality than my originals. The cloth is a bit scratchy but it provides more protection.",         2,   0,  -2,   0,   8,  0,   500,  true, 0, false, false),
        Item("Leather Robes",             "A set of leather robes crafted from some animal hide. It's a bit restrictive, but I think I can manage.",          2,   0,  -4,   0,  16,  0,  1000,  true, 0, false, false),
        Item("Studded Leather Robes",     "A hefty set of leather robes with studded bits of metal. It's much heavier than a normal set of leather robes.",   2,   0,  -7,   0,  28,  0,  3500,  true, 0, false, false),
        Item("Mithril Robes",             "A set of robes fit for a fine mage. Protects well from magic, but at the cost of physical risk.",                  2,   0, -12,   0,  45,  0,  7000,  true, 0, false, false),
        Item("Battle Robes",              "A set of robes which rivals the quality of my mentor's. I feel nearly invulnerable to magic attack in them.",      2,   0, -15,   0,  60,  0,     0, false, 0, false, false),

        Item("Leather Armor",             "A simplistic set of leather armor. It provides more protection than my shirt.",                                    2,   0,   1,   0,   1,  0,   100,  true, 0, false, false),
        Item("Heavy Leather Armor",       "A less simplistic set of leather armor. It restricts my movement in favor of defense.",                            2,   0,   3,   0,   3,  0,   500,  true, 0, false, false),
        Item("Iron Chainmail",            "A set of iron chainmail. The jingle of the armor is an appreciated partner in battle.",                            2,   0,   6,   0,   6,  0,  1000,  true, 0, false, false),
        Item("Steel Chainmail",           "A set of steel chainmail. Enemies will have a hard time piercing this.",                                           2,   0,  12,   0,  12,  0,  3500,  true, 0, false, false),
        Item("Knight's Chainmail",        "A set of chainmail that may have belonged to a knight. It seems nearly impenetrable.",                             2,   0,  23,   0,  23,  0,  7000,  true, 0, false, false),
        Item("Dragonscale Armor",         "A set of armor created from the scales of a dragon. It's much nicer than I thought it would be.",                  2,   0,  40,   0,  40,  0,     0, false, 0, false, false),

        Item("Squire's Armor",            "A shoddy set of armor, if one could call it such. At the very least it functions like armor.",                     2,   0,   3,   0,  -1,  0,   200,  true, 0, false, false),
        Item("Iron Plate Armor",          "An iron plate. It's armor that looks the part. It's a step up from a squire's armor.",                             2,   0,   8,   0,  -2,  0,   700,  true, 0, false, false),
        Item("Steel Plate Armor",         "A steel platebody. It softens blows and protects me from danger.",                                                 2,   0,  16,   0,  -4,  0,  1500,  true, 0, false, false),
        Item("Reinforced Steel Plate",    "A reinforced steel platebody. It's a step up from steel, with the heavier steel providing a thicker shell.",       2,   0,  28,   0,  -7,  0,  5000,  true, 0, false, false),
        Item("Knight's Armor",            "A platebody which may have belonged to a knight. It offers excellent protection.",                                 2,   0,  45,   0, -12,  0,  8000,  true, 0, false, false),
        Item("Diamond Embedded Plate",    "A gaudy but well-built platebody. It provides maximal protection to my body, despite hindering my magic.",         2,   0,  60,   0, -15,  0,     0, false, 0, false, false),

        Item("Potion of Lesser Healing",  "A potion of lesser healing. It smells horrible.",                                                                  3,   0,   0,   0,   0,  1,    50,  true, 0, false, false),
        Item("Potion of Minor Healing",   "A potion of minor healing. It smells odd.",                                                                        3,   0,   0,   0,   0,  2,   100,  true, 0, false, false),
        Item("Potion of Average Healing", "A potion of average healing. It does not seem to have an odor.",                                                   3,   0,   0,   0,   0,  3,   350,  true, 0, false, false),
        Item("Potion of Greater Healing", "A potion of greater healing. It smells of fine baked goods. I am not sure why.",                                   3,   0,   0,   0,   0,  4,  1500,  true, 0, false, false),
        Item("Potion of Major Healing",   "A potion of major healing. The scent is indescribable, albeit good.",                                              3,   0,   0,   0,   0,  5,  5000,  true, 0, false, false),
        Item("Elixir of Life",            "'The elixir of life.' It reeks of earthy scents.",                                                                 3,   0,   0,   0,   0,  6,  8000,  true, 0, false, false),

        Item("Potion of Minor Mana",      "A potion of minor mana. There are strange chunks floating in it.",                                                 3,   0,   0,   0,   0,  8,   100,  true, 0, false, false),
        Item("Potion of Lesser Mana",     "A potion of lesser mana. It looks improperly mixed.",                                                              3,   0,   0,   0,   0,  7,    50,  true, 0, false, false),
        Item("Potion of Average Mana",    "A potion of average mana. It appears to be properly mixed.",                                                       3,   0,   0,   0,   0,  9,   350,  true, 0, false, false),
        Item("Potion of Greater Mana",    "A potion of greater mana. The hue of the liquid is unnatural.",                                                    3,   0,   0,   0,   0, 10,  1500,  true, 0, false, false),
        Item("Potion of Major Mana",      "A potion of major mana. I have an odd feeling that the liquid is glowing.",                                        3,   0,   0,   0,   0, 11,  5000,  true, 0, false, false),
        Item("Ether of Magic",            "An ether of magic. My eyes hurt just looking at it.",                                                              3,   0,   0,   0,   0, 12,  8000,  true, 0, false, false),

        Item("Fiend Repellant",           "A flasked scent which causes fiends to ignore you. Does not work on all fiends.",                                  3,   0,   0,   0,   0, 13,   500,  true, 0, false, false),
        Item("Smoke Bomb",                "A smoke bomb. Useful for fleeing from fiends.",                                                                    3,   0,   0,   0,   0, 14,  1000,  true, 0, false, false),

        Item("Essence of Water",          "The Essence of Water. My hand feels wet while holding this.",                                                      4,   0,   0,   0,   0, 15,     0, false, 0, false, false),
        Item("Essence of Earth",          "The Essence of Earth. I feel at ease while holding this.",                                                         4,   0,   0,   0,   0, 15,     0, false, 0, false, false),
        Item("Essence of Fire",           "The Essence of Fire. My body feels warm while holding this.",                                                      4,   0,   0,   0,   0, 15,     0, false, 0, false, false),
        Item("Essence of Wind",           "The Essence of Wind. I can feel a faint breeze while holding this.",                                               4,   0,   0,   0,   0, 15,     0, false, 0, false, false),
        Item("Essence of Space",          "The Essence of Space. I feel small while holding this.",                                                           4,   0,   0,   0,   0, 15,     0, false, 0, false, false),
        Item("Essence of Time",           "The Essence of Time. I am unsure whether or not this affects me.",                                                 4,   0,   0,   0,   0, 15,     0, false, 0, false, false),
        Item("KEY A",                     "It's a key.'",                                                                                                     4,   0,   0,   0,   0, 16,     0, false, 0, false, false),
        Item("KEY B",                     "It's a key.",                                                                                                      4,   0,   0,   0,   0, 17,     0, false, 0, false, false),
        Item("KEY C",                     "It's a key.",                                                                                                      4,   0,   0,   0,   0, 18,     0, false, 0, false, false),
        Item("KEY D",                     "It's a key.",                                                                                                      4,   0,   0,   0,   0, 19,     0, false, 0, false, false),
        Item("KEY F",                     "It's a key.",                                                                                                      4,   0,   0,   0,   0, 20,     0, false, 0, false, false),
        Item("KEY G",                     "It's a key.",                                                                                                      4,   0,   0,   0,   0, 21,     0, false, 0, false, false),
        Item("SPI 1",                     "It's a special item.",                                                                                             4,   0,   0,   0,   0, 22,     0, false, 0, false, false),
        Item("SPI 2",                     "It's a special item.",                                                                                             4,   0,   0,   0,   0, 23,     0, false, 0, false, false),
        Item("SPI 3",                     "It's a special item.",                                                                                             4,   0,   0,   0,   0, 24,     0, false, 0, false, false),
        Item("BEST ENDING ITEM",          "It's the best ending item.",                                                                                       4,   0,   0,   0,   0, 25,     0, false, 0, false, false),
        Item("JOKE ENDING ITEM",          "It's the joke ending item.",                                                                                       4,   0,   0,   0,   0, 26,     0, false, 0, false, false),
    };

    int x = 0;
    int y = 0;
    int m = 0;
    int own[67] = {0};
    int owninc = 0;
    std::string z;

    std::cout << "+---+---------------------------+" << std::setw(125) << std::setfill('-') << "-" << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;
    std::cout << "|   |Name:                      |Description:   " << std::setw(125-15) << std::setfill(' ') <<  " " << "|TYPE | ATK | DEF |MATK |MDEF |FUNC |PRICE|BUYAB|OWNED|" << std::endl;
    std::cout << "+---+---------------------------+" << std::setw(125) << std::setfill('-') <<  "-" << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;

    for(x=0; x<MaxArray ; x++)
    {
        std::cout<< std::left << std::setfill(' ') << "|"
                  << std::setw(3) << x << "|"
                  << std::setw(27) << Test[x].NAME() << "|"
                  << std::setw(125) << Test[x].DESC() << "|"
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
    std::cout << "+---+---------------------------+" << std::setw(125) << std::setfill('-') <<  "-" << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;

    Sleep(2000);

// INVENTORY FUNCTION:

    std::cout << "\n Your inventory currently contains:" << std::endl;
    for(x=0; x<MaxArray; x++)
    {
        if(Test[x].NUM_OWNED() >= 1)
        {
           std::cout << Test[x].NUM_OWNED() << "x " << Test[x].NAME() << ": " << Test[x].DESC() << std::endl;
        }
    }


    Sleep(2000);
    std::cout << "\n========================================\n\n";

    /*
    std::cout << "\nThe Adept's Staff ownership is currently: " << Test[2].NUM_OWNED() << std::endl;
    std::cout << "This is me getting another Adept's Staff. " << std::endl; Test[2].BOUGHT();
    std::cout << "This is me getting another Adept's Staff. " << std::endl; Test[2].BOUGHT();
    std::cout << "This is me getting another Adept's Staff. " << std::endl; Test[2].BOUGHT();
    std::cout << "The ownership is now: " << Test[2].NUM_OWNED() << std::endl;
    */

    // buying function

errorbuysell:
    std::cout << "Would you like to buy or sell an item? ";
    std::cin >> z;
    if(z == "buy" || z == "Buy" || z == "BUY")
        goto another;
    else if(z == "sell" || z == "Sell" || z == "SELL")
        goto itemlisting;
    else if(z == "no" || z == "No" || z == "NO")
        goto broken;
    else
    {
        std::cout << "There was an error. ";
        goto errorbuysell;
    }

another:
    std::cout << "Please enter an item which you would like to buy (Please note that some are not for sale): ";
error:
    std::cin >> y;

    if(y >= 1 && y <= 44 && y != 5 && y != 11 && y != 16 && y != 17 && y != 21 && y != 26)
    {
        std::cout << "So you want the " << Test[y].NAME() << "? ";
error2:
        std::cin >> z;
        if((z == "y") || (z == "yes") || (z == "Y") || (z == "Yes") || (z == "YES"))
        {
            Test[y].BOUGHT();
            m = m - Test[y].PRICE();
            std::cout << "You have purchased the " << Test[y].NAME() << ". It cost you " << Test[y].PRICE() << " coins. You have " << m << " coins so far." << std::endl;
            std::cout << "You now own a total of " << Test[y].NUM_OWNED() << "x " << Test[y].NAME();
            goto finished;

        }
        else if((z == "n") || (z == "no") || (z == "N") || (z == "No") || (z == "NO"))
        {
            goto another;
        }
        else
        {
            std::cout << "I couldn't understand your accent. You wanted the " << Test[y].NAME() << "? ";
            goto error2;
        }

    }
    else if (y == -1)
    {
        goto broken;
    }
    else
    {
        std::cout << "There was an error. Are you sure that item is for sale? If so, please re enter the number: ";
        goto error;
    }

finished:
    std::cout << "\n\n Your inventory currently contains:" << std::endl;
    for(x=0; x<MaxArray; x++)
    {
        if(Test[x].NUM_OWNED() >= 1)
        {
           std::cout << Test[x].NUM_OWNED() << "x " << Test[x].NAME() << ": " << Test[x].DESC() << std::endl;
        }
    }

error3:
    std::cout << "\nWould you like to buy another item? ";
    std::cin >> z;
    if((z == "y") || (z == "yes") || (z == "Y") || (z == "Yes") || (z == "YES"))
    {
        goto another;
    }
    else if((z == "n") || (z == "no") || (z == "N") || (z == "No") || (z == "NO"))
    {
        goto sell;
    }
    else
    {
        std::cout << "There was an error. " << std::endl;
        goto error3;
    }


sell:
    std::cout << "Would you like to sell an item? ";
    std::cin >> z;
    if((z == "y") || (z == "yes") || (z == "Y") || (z == "Yes") || (z == "YES"))
    {
        goto itemlisting;
    }
    else if((z == "n") || (z == "no") || (z == "N") || (z == "No") || (z == "NO"))
    {
        goto broken;
    }
    else
    {
        std::cout << "There was an error. " << std::endl;
        goto sell;
    }

itemlisting:
    std::cout << "\n Your inventory currently contains: " << std::endl;
    for(x=0; x<MaxArray; x++)
    {
        if(Test[x].NUM_OWNED() >= 1)
        {
           own[owninc] = x;
           owninc ++;
           std::cout << owninc-1 << ": " << Test[x].NUM_OWNED() << "x " << Test[x].NAME() << ": " << Test[x].DESC() << std::endl;
        }
    }

anothers:
    std::cout << "Please enter an item which you would like to sell (Please note that some you cannot sell.): ";
error5:
    std::cin >> y;

    if(y >=0 && y<=owninc && own[y] >= 1 && own[y] <= 44 && own[y] != 5 && own[y] != 11
    && own[y] != 16 && own[y] != 17 && own[y] != 21 && x != 26)
    {
        std::cout << "So you want to sell " << Test[own[y]].NAME() << "? ";
error6:
        std::cin >> z;
        if((z == "y") || (z == "yes") || (z == "Y") || (z == "Yes") || (z == "YES"))
        {
            Test[own[y]].DISCARD();
            m = m + (0.5 * Test[own[y]].PRICE());
            std::cout << "You have sold the " << Test[own[y]].NAME() << ". You gained " << (0.5 * Test[own[y]].PRICE()) << " coins. You have " << m << " coins now." << std::endl;
            goto finished2;

        }
        else if((z == "n") || (z == "no") || (z == "N") || (z == "No") || (z == "NO"))
        {
            goto anothers;
        }
        else
        {
            std::cout << "I couldn't understand your accent. You wanted the " << Test[y].NAME() << "? ";
            goto error2;
        }
    }
    else if (y == -1)
    {
        goto broken;
    }
    else
    {
        std::cout << "There was an error. Are you sure you can sell that? If so, please re enter the number: ";
        goto error5;
    }

finished2:
    std::cout << "\n\n Your inventory currently contains:" << std::endl;
    for(x=0; x<MaxArray; x++)
    {
        if(Test[x].NUM_OWNED() >= 1)
        {
           std::cout << Test[x].NUM_OWNED() << "x " << Test[x].NAME() << ": " << Test[x].DESC() << std::endl;
        }
    }

error7:
    std::cout << "\nWould you like to sell another item? ";
    std::cin >> z;
    if((z == "y") || (z == "yes") || (z == "Y") || (z == "Yes") || (z == "YES"))
    {
        own[67] = {0};
        owninc = 0;
        goto itemlisting;
    }
    else if((z == "n") || (z == "no") || (z == "N") || (z == "No") || (z == "NO"))
    {
        goto buyagain;
        goto broken;
    }
    else
    {
        std::cout << "There was an error. " << std::endl;
        goto error3;
    }

buyagain:
    std::cout << "Would you like to buy an item? ";
    std::cin >> z;
    if((z == "y") || (z == "yes") || (z == "Y") || (z == "Yes") || (z == "YES"))
    {
    system("CLS");
    std::cout << "+---+---------------------------+" << std::setw(125) << std::setfill('-') << "-" << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;
    std::cout << "|   |Name:                      |Description:   " << std::setw(125-15) << std::setfill(' ') <<  " " << "|TYPE | ATK | DEF |MATK |MDEF |FUNC |PRICE|BUYAB|OWNED|" << std::endl;
    std::cout << "+---+---------------------------+" << std::setw(125) << std::setfill('-') <<  "-" << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;

    for(x=0; x<MaxArray ; x++)
    {
        std::cout<< std::left << std::setfill(' ') << "|"
                  << std::setw(3) << x << "|"
                  << std::setw(27) << Test[x].NAME() << "|"
                  << std::setw(125) << Test[x].DESC() << "|"
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
    std::cout << "+---+---------------------------+" << std::setw(125) << std::setfill('-') <<  "-" << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;
    goto another;
    }
    else if((z == "n") || (z == "no") || (z == "N") || (z == "No") || (z == "NO"))
    {
        goto broken;
    }
    else
    {
        std::cout << "There was an error. " << std::endl;
        goto buyagain;
    }


broken:
    return 0;
}
