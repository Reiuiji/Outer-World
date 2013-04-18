/* ECE 264 Group Prject: Display.cpp
 *
 * This software is licensed under the terms of the MIT-License
 * See COPYING for further information.
 * ---
 * Copyright (C) 2013 Daniel Noyes <Reiuiji@gmail.com>
 */
#include "Display.h"
#include "Definition.h"
#include <string.h>
#include <curses.h>

char StatusBar[5][102] =
{
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    "X  Health                    /             equiped items               \\                     Mana   X",
    "X  [                      ] || [j:  ] [k:  ] [j: ] [i: ]  [sword:    ] || [                      ]  X",
    "X  ___%                      \\                                         /                     ___%   X",
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};

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

void CDisplay::init_Border()
{
    move(Displaycenset+1,0);
    attron(COLOR_PAIR(COLOR_WHITE));
    for(int y = 0; y<=WinHeight; y++)
    {
        for(int x = 0; x<=WinWidth; x++)
        {
            if((y == 0 || y == WinHeight) & !(x == 0 || x == WinWidth))
            {
                mvaddch(Displaycenset+y,x,'\45');
            }
            else if((x == 0 || x == WinWidth) & !(y == 0 || y == WinHeight))
            {
                mvaddch(Displaycenset+y,x,'\124');
            }
            else if(y == 0 || y == WinHeight || x == 0 || x == WinWidth)
            {
                mvaddch(Displaycenset+y,x,'X');
            }
        }

    }
}

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

void CDisplay::Display(int Sx, int Sy, int x, int y,int xcen, int ycen, char Map[][MapMax]) //have to hard code for array, change to vector after test
{
    x = x+xcen; //center cords
    y = ycen-y;
    move(Displaycenset,1);
    for(int Ly = (y-Sy/2) ; Ly < (y+Sy/2 + Sy%2); Ly ++)
    {
        for(int Lx = (x - Sx/2) ; Lx < (x + Sx/2 +(Sx%2)) ; Lx++)
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

void CDisplay::Message(const char *msg)
{
    move(XCenter-msg_X_Width/2,YCenter);
    int place = 0;
    for(int y = YCenter; y <= msg_Y_Width; y++)
    {
        for(int x = XCenter-msg_X_Width/2; x <= msg_X_Width; x++)
        {
            if(y == YCenter || y == msg_Y_Width || x == XCenter-msg_X_Width/2 || x == msg_X_Width)
                printw("x");
            else
            {
                mvaddstr(y,x,"0");
                place++;
            }

        }
    }
}

void CDisplay::ColorMap(char var)
{
    bool print = false;
    switch(var)
    {
    case 'f':
        attron(COLOR_PAIR(COLOR_CYAN));
        break;

    case 'v':
        attron(COLOR_PAIR(COLOR_GREEN));
        printw("\\");
        print = true;
        break;

    case 'm':
        attron(COLOR_PAIR(COLOR_YELLOW));
        break;

    case 'w':
        attron(COLOR_PAIR(ENV_WATER));
        break;

    case 'X':
        attron(COLOR_PAIR(COLOR_BLACK));
        break;

    case '#':
        attron(COLOR_PAIR(COLOR_MAGENTA));
        break;

    case '[':
    case ']':
        attron(COLOR_PAIR(COLOR_BROWN));
        break;

    case '/':
        attron(COLOR_PAIR(COLOR_GREEN));
        break;

    default:
        attron(COLOR_PAIR(COLOR_WHITE));
        break;
    }
    if(!print)
    {
        printw("%1c",var);
    }
}

