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
#include "EventHandler.h"
#include "Display.h"
#include "Player.h"
#include "Enemy.h"
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
    Enemy EnemyONE(1);
    //sets up time layout for 1 seconds
    // struct timespec tim,tim2;
    // tim.tv_sec = 0;
    // tim.tv_nsec = 50000000L;

    while(play == true)
    {

        clear();
        GameDisplay.init_StatusBar(0,playerONE);
        GameDisplay.Display(WinWidth,WinHeight,x,y,26,13,Map[maplocation]);
        //GameDisplay.DebugScreen(x,y,Map1);
        //GameDisplay.Message(WinWidth/6,(4*WinHeight)/5,(2*WinWidth)/3,WinHeight/5,"Hello young one, i am a traveler from a different land, please help me and I will give you a magic ball");
        //GameDisplay.Message(0,0,WinWidth,WinHeight,"abcdefghijklmnopqrstuvwxyz");
        GameDisplay.init_Border(Displaycenset);
        //GameDisplay.Message("test");
        Move(x,y,26,13,Map[maplocation]);
        // nanosleep(&tim,&tim2);

        if(BattleMode == true)
        {
            GameDisplay.Battle(playerONE,EnemyONE);
        }

        if(AutoDisplay==true)
        {
            getmaxyx(stdscr,WinHeight,WinWidth);
        }
        refresh();//refreshes the screen
        //GameDisplay.wait(10000);
    }

    return 0;
}

//player move function
//check if player can move to that location, if so whey yay they can move
void Move(int &x,int &y,int xcen, int ycen,char Map[][MapMax])
{
    int  c=Input();
    eventListener(x,y,xcen,ycen,Map,c);
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

    case 'b':   //Test Enter the Battle mode
        BattleMode = true;
        break;

    case '`':   //Exit the game display
        play = false;
        break;

    case '~':   //enable debug utility
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

bool CollisionCheck(int x, int y, int xcen, int ycen, char Map[][MapMax], char event)
{
    // Checks to see if there is a basic monster adjacent (whether or not it should call for a battle)
    if (        (Map[ycen-y+1][x+xcen] == event) || (Map[ycen-y][x+xcen+1] == event) // Checks the space to the immediate north of the player for enemies.
            ||  (Map[ycen-y-1][x+xcen] == event) || (Map[ycen-y][x+xcen-1] == event)
       ) // Checks the space to the immediate south of the player for enemies.
        return 1;
    else
        return 0;
}

bool clearevent(int x, int y, int xcen, int ycen, char Map[][MapMax], char read, char write)
{
if (Map[ycen-y+1][x+xcen] == read)
          {
          Map[ycen-y+1][x+xcen] = write;
          return 1;
          }
else if (Map[ycen-y][x+xcen+1] == read)
          {
          Map[ycen-y][x+xcen+1] = write;
          return 1;
          }
else if (Map[ycen-y-1][x+xcen] == read)
          {
          Map[ycen-y-1][x+xcen] = write;
          return 1;
          }
else if (Map[ycen-y][x+xcen-1] == read)
          {
          Map[ycen-y][x+xcen-1] = write;
          return 1;
          }
else return 0;
}

void eventListener(int x, int y, int xcen,int ycen, char Map[][MapMax], char input)
{
// Collision Check for Enemies


if(CollisionCheck(x,y,xcen,ycen,Map,',') && input == '\n')
    {
    if(maplocation == 0)
       maplocation = 1;
    else if(maplocation == 1)
        maplocation = 0;
    }

else if(CollisionCheck(x,y,xcen,ycen,Map,'<') || CollisionCheck(x,y,xcen,ycen,Map,'>'))
    {
    CDisplay display;
    display.Message("If the battle system was implemented, you would be fighting.");
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

// Collision Check for Chests
else if(CollisionCheck(x,y,xcen,ycen,Map,'&') && input == '\n')
    {
    CDisplay display;
    display.Message("You opened the chest. There was nothing inside!");
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

// Collision Check for Person A
else if(CollisionCheck(x,y,xcen,ycen,Map,'A') && input == '\n')
    {
    CDisplay display;
    display.Message("Oh, you're awake. Welcome to the city of Seaview. Yes, I know it's a terrible name. Blame the mayor.You washed up in our lake, so we placed you in our");
    refresh();
        bool leave1 = false;
        while(leave1 == false)
        {
            if(Input() == '\n')
            {
                leave1 = true;
            }
        }
    display.Message("inn to heal. And by inn, I suppose I mean guest   bedroom, considering the size of our town. Anyway,enough of that. Your clothes tell me you're not");
    refresh();
        bool leave2 = false;
        while(leave2 == false)
        {
            if(Input() == '\n')
            {
                leave2 = true;
            }
        }
    display.Message("from around here. Let me guess, you messed up     casting some sort of interdimensional spell and   landed in our lake. ");
    refresh();
        bool leave3 = false;
        while(leave3 == false)
        {
            if(Input() == '\n')
            {
                leave3 = true;
            }
        }
    display.Message("It figures. Truth be told, you're the fourth this year. I don't know why but our town seems to be a popular hotspot for this kind of stuff.");
    refresh();
        bool leave4 = false;
        while(leave4 == false)
        {
            if(Input() == '\n')
            {
                leave4 = true;
            }
        }
    display.Message("My name's Aryn. It's nice to meet you.");
    refresh();
        bool leave5 = false;
        while(leave5 == false)
        {
            if(Input() == '\n')
            {
                leave5 = true;
            }
        }
    clearevent(x,y,xcen,ycen,Map,'A','Á');
    refresh();
    }

// Collision Check for Person Á
else if(CollisionCheck(x,y,xcen,ycen,Map,'Á') && input == '\n')
    {
    CDisplay display;
    display.Message("Nothing new to report here.");
    refresh();
        bool leave1 = false;
        while(leave1 == false)
        {
            if(Input() == '\n')
            {
                leave1 = true;
            }
        }
    }

// Collision Check for Person B
else if(CollisionCheck(x,y,xcen,ycen,Map,'B') && input == '\n')
    {
    CDisplay display;
    if(Event[0] == 0)
    {
    display.Message("I apologize, but my shop is currently closed.");
    refresh();
        bool leave1 = false;
        while(leave1 == false)
        {
            if(Input() == '\n')
            {
                leave1 = true;
            }
        Event[0] = 1;
        }
    }

    else if(Event[0] == 1)
    {
    display.Message("Please come back at a later time.");
    refresh();
        bool leave2 = false;
        while(leave2 == false)
        {
            if(Input() == '\n')
            {
                leave2 = true;
            }
        }
    }
    }

// Collision Check for Person M
else if(CollisionCheck(x,y,xcen,ycen,Map,'M') && input == '\n')
    {
    CDisplay display;
// if(Event[0] == 1)
// {
        display.Message("Hm? Some person is locked out of their house?");
        refresh();
            bool leave1 = false;
            while(leave1 == false)
            {
                if(Input() == '\n')
                {
                    leave1 = true;
                }
            }
        display.Message("Well, I may have known you for all of two seconds, but here, take the town keys.");
        refresh();
            bool leave2 = false;
            while(leave2 == false)
            {
                if(Input() == '\n')
                {
                    leave2 = true;
                }
//            event[1] = 1;
            }
//    }
//    else
//    {
        display.Message("I'm busy at the moment.");
        refresh();
            bool leave3 = false;
            while(leave3 == false)
            {
                if(Input() == '\n')
                {
                    leave3 = true;
                }
            }

        display.Message("I'm busy at the moment.");
        refresh();
            bool leave4 = false;
            while(leave4 == false)
            {
                if(Input() == '\n')
                {
                    leave4 = true;
                }
            }
        }
//    }

// Collision Check for Person H
else if(CollisionCheck(x,y,xcen,ycen,Map,'H') && input == '\n')
    {
    CDisplay display;
    display.Message("For whatever reason the mayor has decided to lock the passageway to my house.");
    refresh();
        bool leave1 = false;
        while(leave1 == false)
        {
            if(Input() == '\n')
            {
                leave1 = true;
            }
        }
    }

// Collision Check for Doors
else if(CollisionCheck(x,y,xcen,ycen,Map,'!') && input == '\n')
    {
//        if(event[1] = 1)
            clearevent(x,y,xcen,ycen,Map,'!','#');
    }

//Collision Check for Trees
else if((CollisionCheck(x,y,xcen,ycen,Map,'[') || CollisionCheck(x,y,xcen,ycen,Map,']') || CollisionCheck(x,y,xcen,ycen,Map,'/') || CollisionCheck(x,y,xcen,ycen,Map,'v'))  && input == '\n')
    {
    CDisplay display;
    display.Message("It's a tree. Fascinating.");
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

// Collision Check for Bosses
else if(CollisionCheck(x,y,xcen,ycen,Map,'$') && input == '\n')
    {
    CDisplay display;
    display.Message("This would be a boss battle.");
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

}

//input function
int Input(void)
{
    int ch = getch();
    return ch;
}
