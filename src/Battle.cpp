/*
* ECE 264 Final Group Prject: Source Code
* Copyright (C) 2013 Daniel Noyes <Reiuiji@gmail.com> and Benjamin Doiron <ALEDelric@gmail.com>
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
#include "Definition.h"
#include "Player.h"
#include "Enemy.h"
#include "Display.h"
#include "Battle.h"
#include <string.h>
#ifdef _WIN32
#include "..\..\ECE264FinalProject\dependencies\curses.h"
#endif
#ifdef linux
#include <curses.h>
#endif

void Battle::StartBattle(Player plyone, Enemy Mob)
{
    CDisplay Disp;

    for(int y=0; y<=WinHeight-Displaycenset; y++)
    {
        for(int x=0; x<WinWidth; x++)
        {
            mvaddch(y-1,x,' ');
        }
        if(y>WinHeight/5)
        {
            Disp.Message(WinWidth/6,(1*WinHeight)/5,(2*WinWidth)/3,WinHeight/5, "Descrition");
        }

        if(y>(2*WinHeight)/5)
        {
            Disp.Message(WinWidth/6,(2*WinHeight)/5,(2*WinWidth)/3,WinHeight/5, "Action");
        }

        if(y>(3*WinHeight)/5)
        {
            Disp.Message(WinWidth/6,(3*WinHeight)/5,(2*WinWidth)/3,WinHeight/5, "Selection");
        }
        if(y % (WinHeight/12) == 0)
        {

            Disp.init_StatusBar(y,plyone);
            Disp.wait(40000);

            refresh();
        }




    }
    Disp.wait(10000);

    refresh();


    while(BattleMode == true)
    {
        clear();
        move(0,0);
        Disp.Message(WinWidth/6,(3*WinHeight)/5,(2*WinWidth)/3,WinHeight/5, "Selection");
        Disp.Message(WinWidth/6,(2*WinHeight)/5,(2*WinWidth)/3,WinHeight/5, "Action");
        Disp.Message(WinWidth/6,(1*WinHeight)/5,(2*WinWidth)/3,WinHeight/5, "Talk");
        Disp.init_StatusBar(WinHeight-Displaycenset,plyone);
        if(AutoDisplay==true)
        {
            getmaxyx(stdscr,WinHeight,WinWidth);
        }
        refresh();

//battle functions
        int  c=getch();
        if(c)
        {
            switch(c)
            {
            case KEY_DOWN:
                dotx += 2;
                break;

            case KEY_UP:
                dotx -= 2;
                break;

            case KEY_LEFT:
                doty -= 2;
                break;

            case KEY_RIGHT:
                doty += 2;
                break;

            case '\n':

                break;

            case '0':
                BattleMode = false;
                break;

            }
        }
    }

}
