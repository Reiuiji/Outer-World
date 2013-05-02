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
#include <iostream>

//insert gen functions

//void DungeonGen(int FloorCount, int FloorSize, int LvlLow, int LvlHigh)
void Dungeon::StartDungeon(Player plyone,int DungeonLVL)
{
    int PlayerX = 9;
    int PlayerY = 10;

    CDisplay CDisp;

    refresh();


    while(DungeonMode == true)
    {
        clear();
        move(0,0);
        CDisp.init_StatusBar(0,plyone);
        if(AutoDisplay==true)
        {
            getmaxyx(stdscr,WinHeight,WinWidth);
        }
        Dungeon::DisplayRoom(DungeonRoom,DungeonMap1,PlayerY,PlayerX);
        GameDisplay.init_Border(Displaycenset);
        refresh();

    //Dungeon functions
        int  c=getch();
        if(c)
        {
            switch(c)
            {
            case KEY_DOWN:
                PlayerY ++;
                break;

            case KEY_UP:
                PlayerY --;
                break;

            case KEY_LEFT:
                PlayerX --;
                break;

            case KEY_RIGHT:
                PlayerX ++;
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

void Dungeon::DisplayRoom(const char Map[DungeonRoomNum][DungeonMapY][DungeonMapX],const int DungeonMap[DungeonMapLVL][DungeonMapLVL],int PlayerY, int PlayerX)
{
    move(Displaycenset,0);
    for(int Ly = 0 ; Ly < DungeonMapY; Ly ++)
    {
        for(int Lx = 0 ; Lx < DungeonMapX ; Lx++)
        {
            if(DungeonMap[PlayerY][PlayerX] > 0 && DungeonMap[PlayerY][PlayerX]  <5)
            {
                printw("%1c",Map[DungeonMap[PlayerY][PlayerX]-1][Ly][Lx]);
            }
            else
            {
                printw(" ");
            }
        }
        printw("\n");
    }
    printw("X: %d, Y: %d", PlayerX, PlayerY);
}

