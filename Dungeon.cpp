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
#include "Player.h"
#include "Display.h"
#include "Dungeon.h"
#include <curses.h>

//insert gen functions

//void DungeonGen(int FloorCount, int FloorSize, int LvlLow, int LvlHigh)
void Dungeon::StartDungeon(Player plyone,int DungeonLVL)
{
    int PlayerX = 9;
    int PlayerY = 10;
    bool leave = false;

    CDisplay CDisp;

    refresh();


    while(leave == false)
    {
        clear();
        move(0,0);

        CDisp.init_StatusBar(0,plyone);
        if(AutoDisplay==true)
        {
            getmaxyx(stdscr,WinHeight,WinWidth);
        }
        refresh();

//Dungeon functions
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
                DungeonMode = false;
                break;

            }
        }
    }

}

void Dungeon::DisplayRoom(char Map[DungeonRoomNum][DungeonMapY][DungeonMapX], int RNum)
{

}
