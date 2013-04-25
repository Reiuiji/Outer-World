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
#include "Player.h"
#include "Game.h"
#include "Maps.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include "dependencies/curses.h"
#endif
#ifdef linux
#include <curses.h>
#endif


int Game()
{
    int x = 0;
    int y = 0;
    CDisplay GameDisplay;//sets up the display object for curses
    Player playerONE(1);
    //sets up time layout for 1 seconds
    // struct timespec tim,tim2;
    // tim.tv_sec = 0;
    // tim.tv_nsec = 50000000L;

    while(play == true)
    {

        clear();
        GameDisplay.init_StatusBar(playerONE);
        GameDisplay.Display(WinWidth,WinHeight,x,y,100,50,Map1);
        GameDisplay.DebugScreen(x,y,Map1);
        //GameDisplay.Message(WinWidth/6,(4*WinHeight)/5,(2*WinWidth)/3,WinHeight/5,"Hello young one, i am a traveler from a different land, please help me and I will give you a magic ball");
        //GameDisplay.Message(0,0,WinWidth,WinHeight,"abcdefghijklmnopqrstuvwxyz");
        GameDisplay.init_Border(Displaycenset);
        //GameDisplay.Message("test");
        Move(x,y,100,50,Map1);
        // nanosleep(&tim,&tim2);
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
    int  c=Input();
    eventListener(x,y,Map,c);
    switch(c)
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

    case KEY_EXIT:   //Exit the game display
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


bool CollisionCheck(int x, int y, char Map[][MapMax], char event)
{
    // Checks to see if there is a basic monster adjacent (whether or not it should call for a battle)
    if (    (Map[y+1][x] == event) || (Map[y][x+1] == event) // Checks the space to the immediate north of the player for enemies.
            ||  (Map[y-1][x] == event) || (Map[y][x-1] == event)
       ) // Checks the space to the immediate south of the player for enemies.
        return 0;
    else
        return 1;
}

bool CollisionRangeCheck(int x, int y, char *Map[][MapMax], char Start, char End)
{
    // Checks to see if there is a basic monster adjacent (whether or not it should call for a battle)
    if (    ((Map[y+1][x] >= &Start) && (Map[y+1][x] <= &End))
            ||  ((Map[y-1][x] >= &Start) && (Map[y-1][x] <= &End))
            ||  ((Map[y][x+1] >= &Start) && (Map[y][x+1] <= &End))
            ||  ((Map[y][x-1] >= &Start) && (Map[y][x-1] <= &End))
       )
        return 0;
    else
        return 1;
}

void eventListener(int x,int y, char Map[][MapMax], char input)
{
   // if(CollisionCheck(x,y,Map,'<') || CollisionCheck(x,y,Map,'>'))
        // Normal Battle;
    //if((CollisionRangeCheck(x,y,Map,'A','Z') && input == '\n'))
        // Speech Event
    //if((CollisionCheck(x,y,Map,'%') || CollisionCheck(x,y,Map,'$') || CollisionCheck(x,y,Map,'&')) && input == '\n')
        // Boss Battle. Maybe implement a feature to check the map.
    if(CollisionCheck(x,y,Map,'&') && input == '\n')
    {
        CDisplay display;
        int c=0;
    display.Message("you opened the chest... you found Nothing");
    refresh();
        bool leave = false;
        while(leave == false)
        {
            if(Input() == '\n')
            {
                leave = true;
            }
        }

    }
        // opens chest and gets idems, display etc.
}

//input function
int Input(void)
{
    int ch = getch();
    return ch;
}
