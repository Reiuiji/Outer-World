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
#include "Definition.h"
#include <string.h>
#include <curses.h>

//temp array to display the status bar
char StatusBar[5][102] =
{
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    "X  Health                    /             equiped items               \\                     Mana   X",
    "X  [                      ] || [j:  ] [k:  ] [j: ] [i: ]  [sword:    ] || [                      ]  X",
    "X  ___%                      \\                                         /                     ___%   X",
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};

//curses display that will init the status bar
void CDisplay::init_StatusBar()
{
    move(0,0);
    attron(COLOR_PAIR(COLOR_WHITE));
    for(int i = 0; i<5; i++)
    {
        for(int j = 0; j<=100; j++)
            printw("%c",StatusBar[i][j]);
        printw("\n");
    }
}

//curses: outputs the border of the screen
//checks the limits of the border and output a border tag
void CDisplay::init_Border(int offset)
{
    move(offset+1,0);
    attron(COLOR_PAIR(COLOR_WHITE));
    for(int y = 0; y<WinHeight-offset; y++)
    {
        for(int x = 0; x<WinWidth; x++)
        {
            if((y == 0 || y == (WinHeight-offset-1)) & !(x == 0 || x == WinWidth-1))
            {
                mvaddch(offset+y,x,'\45');
            }
            else if((x == 0 || x == WinWidth-1) & !(y == 0 || y == (WinHeight-offset-1)))
            {
                mvaddch(offset+y,x,'\45');
            }
            else if(y == 0 || y == (WinHeight-offset-1) || x == 0 || x == WinWidth-1)
            {
                mvaddch(offset+y,x,'\45');
            }
        }

    }
}

//Curses: Debug screen
void CDisplay::DebugScreen(int x, int y, char Map[][MapMax])
{
    move(Displaycenset+WinHeight+1,0);
    if(debug == true)
    {
        printw("X: %d\n",x);
        printw("Y: %d\n",y);
        printw("MapMax: %d\n",MapMax);
        printw("WinHeight: %d\n",WinHeight);
        printw("MaxWidth: %d\n",WinWidth);
        printw("LX: min: %d    max: %d\n",(x-WinWidth/2),(x+WinWidth/2) );
        printw("LY: min: %d    max: %d\n",(y-WinHeight/2),(y+WinHeight/2) );
    }
    else
    {
        for(int i = 0 ; i<7; i++)
        {
            for(int j = 0; j<40; j++)
                printw(" ");
            printw("\n");
        }
    }
}

//curses: output the current map to the screen
void CDisplay::Display(int Sx, int Sy, int x, int y,int xcen, int ycen, char Map[][MapMax]) //have to hard code for array, change to vector after test
{
    x = x+xcen; //center cords
    y = ycen-y;
    Sy-=Displaycenset;//fixed the cords based on the display offset from the status bar
    move(Displaycenset,1);
    for(int Ly = (y-Sy/2) ; Ly < (y+Sy/2 + Sy%2 -1); Ly ++)
    {
        for(int Lx = (x - Sx/2) ; Lx < (x + Sx/2 +(Sx%2) -1) ; Lx++)
        {
            if( Ly >= 0 && Ly < MapMax && Lx >= 0 && Lx < MapMax)
            {
                if(Lx == x && Ly == y)
                {
                    attron(COLOR_PAIR(COLOR_CYAN));
                    printw("@");
                }
                else
                {
                    ColorMap(Map[Ly][Lx]);
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

//curses message display
void CDisplay::Message(int X,int Y, int Width, int Height, const char *msg)
{
    attron(COLOR_PAIR(COLOR_WHITE));
    //sets up the blank window
    for(int y = Y; y < Height; y++)
    {
        for(int x = X; x < Width; x++)
        {
            if(y == Y || y == Height || x == X || x == Width)
                mvaddstr(y,x,"\45");
            else
            {
                mvaddstr(y,x," ");
            }

        }
    }

    //inputs the text into the window
    for(int y = Y+2; y < Height-2; y++)
    {
        for(int x = X+3; x < Width-3; x++)
        {
                mvaddstr(y,x,"#");

        }
    }
}

//curses: main color map, output the specific color on the screen
void CDisplay::ColorMap(char var)
{
    bool print = false;
    switch(var)
    {
    case 'f'://Water Fall
        attron(COLOR_PAIR(COLOR_CYAN));
        break;

    case 'v'://tree slant "\"
        attron(COLOR_PAIR(COLOR_GREEN));
        printw("\\");
        print = true;
        break;

    case 'm'://mountain
        attron(COLOR_PAIR(COLOR_YELLOW));
        break;

    case 'w'://water
        attron(COLOR_PAIR(ENV_WATER));
        break;

    case 'X'://abyss/entrance
        attron(COLOR_PAIR(COLOR_BLACK));
        break;

    case '#'://pathway
        attron(COLOR_PAIR(COLOR_MAGENTA));
        break;

    case '['://tree stump
    case ']'://tree stump
        attron(COLOR_PAIR(COLOR_BROWN));
        break;

    case '/'://tree slant "/"
        attron(COLOR_PAIR(COLOR_GREEN));
        break;

    default://if not display then it is clear
        attron(COLOR_PAIR(COLOR_WHITE));
        break;
    }
    if(!print)
    {
        printw("%1c",var);//output to the screen the character
    }
}

