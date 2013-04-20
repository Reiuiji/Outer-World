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
#include "Display.h"
//#include "Player.h"
#include "Game.h"
#include "Maps.h"
#include <curses.h>
#include <string.h>
#include <stdlib.h>

int Game()
{
    int x = 0;
    int y = 0;
    CDisplay game;
    while(play == true)
    {

        clear();
        game.init_StatusBar();
        game.Display(WinWidth,WinHeight,x,y,100,50,Map1);
        game.init_Border();
        game.DebugScreen(x,y,Map1);
        //game.Message("test");
        Move(x,y,100,50,Map1);
        refresh();
    }

    return 0;
}

void Move(int &x,int &y,int xcen, int ycen,char Map[][MapMax])
{
    switch(Input())
    {
    case KEY_UP:
    case 'w':
        if(MoveCheck(x,y,xcen,ycen,0,1,Map) == 0)
            y++;
        break;
    case KEY_DOWN:
    case 's':
        if(MoveCheck(x,y,xcen,ycen,0,-1,Map) == 0)
            y--;
        break;
    case KEY_LEFT:
    case 'a':
        if(MoveCheck(x,y,xcen,ycen,-1,0,Map) == 0)
            x--;
        break;
    case KEY_RIGHT:
    case 'd':
        if(MoveCheck(x,y,xcen,ycen,1,0,Map) == 0)
            x++;
        break;

    case 'q':
        if(MoveCheck(x,y,xcen,ycen,-1,+1,Map) == 0 && (MoveCheck(x,y,xcen,ycen,0,+1,Map) == 0 || MoveCheck(x,y,xcen,ycen,-1,0,Map) == 0))
        {
            x--;
            y++;
        }
        break;
    case 'e':
        if(MoveCheck(x,y,xcen,ycen,+1,+1,Map) == 0 && (MoveCheck(x,y,xcen,ycen,0,+1,Map) == 0 || MoveCheck(x,y,xcen,ycen,+1,0,Map) == 0))
        {
            x++;
            y++;
        }
        break;
    case 'z':
        if(MoveCheck(x,y,xcen,ycen,-1,-1,Map) == 0 && (MoveCheck(x,y,xcen,ycen,0,-1,Map) == 0 || MoveCheck(x,y,xcen,ycen,-1,0,Map) == 0))
        {
            x--;
            y--;
        }
        break;
    case 'c':
        if(MoveCheck(x,y,xcen,ycen,+1,-1,Map) == 0 && (MoveCheck(x,y,xcen,ycen,0,-1,Map) == 0 || MoveCheck(x,y,xcen,ycen,+1,0,Map) == 0))
        {
            x++;
            y--;
        }
        break;
    case '[':
        WinHeight--;
        break;
    case ']':
        WinHeight++;
        break;
    case ';':
        WinWidth--;
        break;
    case '\'':
        WinWidth++;
        break;
    case '0':
        play = false;
        break;
    case '`':
        if(debug == false)
            debug = true;
        else
            debug = false;
        break;
    default:
        break;
    }
}



bool MoveCheck(int &x,int &y,int xcen, int ycen, int xmove, int ymove, char Map[][MapMax])
{
    if(strncmp(&Map[ycen-y-ymove][x+xcen+xmove]," ",1) == 0 || strncmp(&Map[ycen-y-ymove][x+xcen+xmove],"#",1) == 0)
        return 0;
    else
        return 1;
}

int Input(void)
{
    int ch = getch();
    return ch;
}
