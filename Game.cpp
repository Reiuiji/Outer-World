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
#include <time.h>

int Game()
{
    int x = 0;
    int y = 0;
    CDisplay GameDisplay;//sets up the display object for curses

    //sets up time layout for 1 seconds
    struct timespec tim,tim2;
    tim.tv_sec = 0;
    tim.tv_nsec = 50000000L;

    while(play == true)
    {

        clear();
        GameDisplay.init_StatusBar();
        GameDisplay.Display(WinWidth,WinHeight,x,y,100,50,Map1);
        GameDisplay.DebugScreen(x,y,Map1);
        GameDisplay.Message(0,(4*WinHeight)/5,WinWidth,WinHeight,"test");
        GameDisplay.init_Border(Displaycenset);
        //GameDisplay.Message("test");
        Move(x,y,100,50,Map1);
        nanosleep(&tim,&tim2);
        if(AutoDisplay==true)
        {
            getmaxyx(stdscr,WinHeight,WinWidth);
        }
        refresh();//refreshes the screen
    }

    return 0;
}

//player move function
//check if player can move to that location, if so whey yay they can move
void Move(int &x,int &y,int xcen, int ycen,char Map[][MapMax])
{
    switch(Input())
    {
    case KEY_UP:
    case 'w':
        if(MoveCheck(x,y,xcen,ycen,0,1,Map) == 0)   //check if you can move to the next pos up
            y++;
        break;
    case KEY_DOWN:
    case 's':
        if(MoveCheck(x,y,xcen,ycen,0,-1,Map) == 0)  //checks move down
            y--;
        break;
    case KEY_LEFT:
    case 'a':
        if(MoveCheck(x,y,xcen,ycen,-1,0,Map) == 0)  //checks move left
            x--;
        break;
    case KEY_RIGHT:
    case 'd':
        if(MoveCheck(x,y,xcen,ycen,1,0,Map) == 0)   //checks move right
            x++;
        break;

    case 'q':
        if(MoveCheck(x,y,xcen,ycen,-1,+1,Map) == 0 && (MoveCheck(x,y,xcen,ycen,0,+1,Map) == 0 || MoveCheck(x,y,xcen,ycen,-1,0,Map) == 0))   //check move NW
        {
            x--;
            y++;
        }
        break;
    case 'e':
        if(MoveCheck(x,y,xcen,ycen,+1,+1,Map) == 0 && (MoveCheck(x,y,xcen,ycen,0,+1,Map) == 0 || MoveCheck(x,y,xcen,ycen,+1,0,Map) == 0))   //check move NE
        {
            x++;
            y++;
        }
        break;
    case 'z':
        if(MoveCheck(x,y,xcen,ycen,-1,-1,Map) == 0 && (MoveCheck(x,y,xcen,ycen,0,-1,Map) == 0 || MoveCheck(x,y,xcen,ycen,-1,0,Map) == 0))   //check move SW
        {
            x--;
            y--;
        }
        break;
    case 'c':
        if(MoveCheck(x,y,xcen,ycen,+1,-1,Map) == 0 && (MoveCheck(x,y,xcen,ycen,0,-1,Map) == 0 || MoveCheck(x,y,xcen,ycen,+1,0,Map) == 0))   //check move SE
        {
            x++;
            y--;
        }
        break;
    case '[':   //decrease window height
        WinHeight--;
        break;
    case ']':   //increase window height
        WinHeight++;
        break;
    case ';':   //decrease window width
        WinWidth--;
        break;
    case '\'':  //increase window width
        WinWidth++;
        break;
    case '0':   //Exit the game display
        play = false;
        break;
    case '`':   //enable debug utility
        if(debug == false)
            debug = true;
        else
            debug = false;
        break;
    default:
        break;
    }
}


//checks if the player can move to that specific location
bool MoveCheck(int &x,int &y,int xcen, int ycen, int xmove, int ymove, char Map[][MapMax])
{
    if(strncmp(&Map[ycen-y-ymove][x+xcen+xmove]," ",1) == 0 || strncmp(&Map[ycen-y-ymove][x+xcen+xmove],"#",1) == 0)
        return 0;
    else
        return 1;
}

//input function
int Input(void)
{
    int ch = getch();
    return ch;
}
