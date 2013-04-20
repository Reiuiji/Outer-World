/*
* ECE 264 Final Group Prject: Source Code
* Copyright (C) 2013 Daniel Noyes <Reiuiji@gmail.com>
*
* This file is part of the ECE 264 Final Group Prject
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "../Player.h"

int main()
{
    int lvl,exp,i,select = 1;
    double tmp;
    string fn,ln;

    Player test(0);

    while (select != 0)
    {
        cout << "\n\n\n  select the following to test"
             << "\n  1 name, 2 level, 3 exp, 4 health"
             << "\n  5 mana, 6 state, 7 inventory, 8 position"
             << "\n  -1 display player"
             << "\n  0 exit\n\n  ";
        cin >> select;
        cout << "\n\n";
        switch(select)
        {
        case 1:
            cout << "\n enter name: ";
            cin >> fn >> ln;
            test.Set_Name(fn,ln);
            cout << "  name: "<< test.FN() << " "<< test.LN() << endl;
            break;

        case 2:
            cout << "\n enter level: ";
            cin >> lvl;
            test.Set_LVL(lvl);
            cout << test.LVL() << endl;
            test.LVL_UP();
            cout << "  lvl up " << test.LVL() << endl;
            break;

        case 3:
            cout << "\n  enter current experience (-1 use current): ";
            cin >> exp;
            if(exp != -1)
            {
                test.Set_EXP(exp);
            }

            cout << "\n  enter how much exp u win: ";
            cin >> exp;
            test.Gain_EXP(exp);
            cout << "\n  current experience " << test.EXP();
            break;

        case 4:
            cout << "\n  enter current health (-1 use current): ";
            cin >> tmp;
            if(tmp != -1)
            {
                test.Set_Health(tmp);
            }

            cout << "\n  enter Max health (-1 use current): ";
            cin >> tmp;
            if(tmp != -1)
            {
                test.MAX_Health(tmp);
            }

            cout << "\n  enter how much health u gain: ";
            cin >> tmp;
            test.INC_Health(tmp);

            cout << "\n  enter how much health u lost: ";
            cin >> tmp;
            test.DEC_Health(tmp);

            cout << "\n  current Health " << test.H();
            break;

        case 5:
            cout << "\n  enter current mana (-1 use current): ";
            cin >> tmp;
            if(tmp != -1)
            {
                test.Set_Mana(tmp);
            }

            cout << "\n  enter Max mana (-1 use current): ";
            cin >> tmp;
            if(tmp != -1)
            {
                test.MAX_Mana(tmp);
            }

            cout << "\n  enter how much mana u gain: ";
            cin >> tmp;
            test.INC_Mana(tmp);

            cout << "\n  enter how much mana u lost: ";
            cin >> tmp;
            test.DEC_Mana(tmp);

            cout << "\n  current Mana " << test.M();
            break;

        case 6:
            cout << "\n Are you alive (0) or dead (1) (-1 current): ";
            cin >> i;
            if(i != -1)
            {
                test.Set_State(i);
            }
            cout << test.S() << endl;
            break;

        case 7:
            break;

        case 8:
            break;

        case -1:
            cout << "  name: " << test.FN() << " "<< test.LN()
                 << "\n  lvl: " << test.LVL()
                 << "\n  current experience " << test.EXP()
                 << "\n  current Health " << test.H()
                 << "\n  current Mana " << test.M()
                 << "\n  current State " << test.S();

        }

    }

    return 0;
}
