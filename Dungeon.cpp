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
#include "string.h"

//insert gen functions

bool Dungeon::MoveCheck(int &x,int &y,int xcen, int ycen, int xmove, int ymove, const char Map[][DungeonMapX])
{
    if(strncmp(&Map[ycen-y-ymove][x+xcen+xmove]," ",1) == 0 || strncmp(&Map[ycen-y-ymove][x+xcen+xmove],"#",1) == 0)
        return 0;
    else
        return 1;
}

//void DungeonGen(int FloorCount, int FloorSize, int LvlLow, int LvlHigh)
void Dungeon::StartDungeon(Player plyone,int DungeonLVL)
{
    int DungeonX = 9;
    int DungeonY = 10;
    int PlayerX = 5;
    int PlayerY = 5;

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
        Dungeon::DisplayRoom(DungeonRoom,DungeonMap1,PlayerY,PlayerX, DungeonY, DungeonX);
        CDisp.init_Border(Displaycenset);
        refresh();

        //Dungeon functions
        int  c=getch();
        if(c)
        {
            switch(c)
            {
            case KEY_DOWN:
                if(MoveCheck(PlayerX,PlayerY,10,10,0,-1,DungeonRoom[DungeonMap1[PlayerY][PlayerX]]) == 0)
                    PlayerY ++;
                break;

            case KEY_UP:
                if(MoveCheck(PlayerX,PlayerY,10,10,0,1,DungeonRoom[DungeonMap1[PlayerY][PlayerX]]) == 0)
                    PlayerY --;
                break;

            case KEY_LEFT:
                if(MoveCheck(PlayerX,PlayerY,10,10,-1,0,DungeonRoom[DungeonMap1[PlayerY][PlayerX]]) == 0)
                    PlayerX --;
                break;

            case KEY_RIGHT:
                if(MoveCheck(PlayerX,PlayerY,10,10,1,0,DungeonRoom[DungeonMap1[PlayerY][PlayerX]]) == 0)
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

void Dungeon::DisplayRoom(const char Map[DungeonRoomNum][DungeonMapY][DungeonMapX],const int DungeonMap[DungeonMapLVL][DungeonMapLVL],int PlayerY, int PlayerX, int DungeonY, int DungeonX)
{
    Dungeon::Display(WinWidth,WinHeight,PlayerX,PlayerY,DungeonMapX/2,DungeonMapY/2,Map[DungeonMap[DungeonY][DungeonX]]);


    if(DungeonMap[DungeonY--][DungeonX] != 0)
    {

    }

    //check if you can move east
    if(DungeonMap[DungeonY][DungeonX++] != 0)
    {

    }

    //check if you can move south
    if(DungeonMap[DungeonY++][DungeonX] != 0)
    {

    }

    //check if you can move west
    if(DungeonMap[DungeonY][DungeonX--] != 0)
    {

    }





    printw("X: %d, Y: %d", PlayerX, PlayerY);
}

void Dungeon::Display(int Sx, int Sy, int x, int y,int xcen, int ycen,const char Map[][DungeonMapX]) //have to hard code for array, change to vector after Dungeone
{
    x = x+xcen; //center cords
    y = ycen-y;
    Sy-=Displaycenset;//fixed the cords based on the display offset from the status bar
    move(Displaycenset,0);
    for(int Ly = (y-Sy/2) ; Ly < (y+Sy/2 + Sy%2 -1); Ly ++)
    {
        for(int Lx = (x - Sx/2) ; Lx < (x + Sx/2 +(Sx%2) -1) ; Lx++)
        {
            if( Ly >= 0 && Ly < DungeonMapX && Lx >= 0 && Lx < DungeonMapX)
            {
                if(Lx == x && Ly == y)
                {
                    attron(COLOR_PAIR(COLOR_CYAN));
                    printw("@");
                }
                else
                {
                    printw("%1c",Map[Ly][Lx]);
                }
            }
            else
            {
                printw(" ");
            }
        }
        printw("\n");
    }
}
