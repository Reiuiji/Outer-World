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
#include "Definition.h"
#include <string.h>
#include <iostream>
#include <time.h>

#ifdef _WIN32
#include "dependencies/curses.h"
#include <windows.h>
#endif
#ifdef linux
#include <curses.h>
#endif

//temp array to display the status bar
//char StatusBar[5][102] =
//{
//    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
//    "X  Health                    /             equiped items               \\                     Mana   X",
//    "X  [                      ] || [j:  ] [k:  ] [j: ] [i: ]  [sword:    ] || [                      ]  X",
//    "X  ___%                      \\                                         /                     ___%   X",
//    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
//};

void CDisplay::wait(int milliseconds)
{
#ifdef _WIN32
    Sleep(milliseconds);
#endif
#ifdef linux
    struct timespec tim,tim2;
    tim.tv_sec = 0;
    tim.tv_nsec = milliseconds*1000;
    nanosleep(&tim,&tim2);
#endif
}


//curses display that will init the status bar
void CDisplay::init_StatusBar(int HightPos, Player P) //hight pos is where it is relevant to the main screen(note -5 for actal status height)
{
    move(0,0);
    attron(COLOR_PAIR(COLOR_WHITE));
    for(int y = HightPos; y<HightPos+Displaycenset; y++)
    {
        for(int x = 0; x<WinWidth; x++)
        {
            if(y == HightPos || y == HightPos+Displaycenset-1 || x ==0 || x == WinWidth-1)
            {
                mvprintw(y,x,"X");
            }
            else
            {
                mvprintw(y,x," ");
            }
        }
        printw("\n");
    }

//setup the displays
    attron(COLOR_PAIR(COLOR_RED));
    mvaddstr(HightPos+1,6,"Health");
    mvaddch(HightPos+2,6,'[');

//output the health bar
    for(int i=7; i< (P.H()/P.MH() % 10)*(WinWidth*0.25); i++)
    {
        mvaddch(HightPos+2,i,'|');
    }
    mvaddch(HightPos+2,WinWidth*0.25,']');

    mvprintw(HightPos+3,6,"( %4d / %4d )",P.H(), P.MH());

//sets up for MANA
    attron(COLOR_PAIR(COLOR_BLUE));
    mvaddstr(HightPos+1,WinWidth-10,"MANA");
    mvaddch(HightPos+2,WinWidth-7,']');

//output the health bar
    for(int i= ((P.M()/P.MM()) % 10)*(WinWidth-7)-1; i>WinWidth*0.75-1; i--)
    {
        mvaddch(HightPos+2,i,'|');
    }
    mvaddch(HightPos+2,WinWidth*0.75-1,'[');

    mvprintw(HightPos+3,WinWidth-21,"( %4d / %4d )",P.M(), P.MM());


    attron(COLOR_PAIR(COLOR_WHITE));

//                if(y == 1 && (x>0 && x<9))
//            {
//                attron(COLOR_PAIR(COLOR_RED));
//                mvprintw(y,x,"%c",StatusBar[y][x]);
//                attron(COLOR_PAIR(COLOR_WHITE));
//            }
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
//
//Sx: Set Width for the Screen
//Sy: Set Height for the Screen
//x: player x position
//y: player y position
//xcen: X center cordinates
//ycen: Y center cordingates
//map: map the display is working with
//
void CDisplay::Display(int Sx, int Sy, int x, int y,int xcen, int ycen, char Map[][MapMax]) //have to hard code for array, change to vector after test
{
    x = x+xcen; //center cords
    y = ycen-y;
    Sy-=Displaycenset;//fixed the cords based on the display offset from the status bar
    move(Displaycenset,0);
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
                    if(Ly < 26)
                    {
                        ColorMap(Map[Ly][Lx]);
                    }
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
    for(int y = Y; y < Y+Height-1; y++)
    {
        for(int x = X; x < X+Width; x++)
        {
            if(y == Y || y == Y+Height-2 || x == X || x == X+Width-1)
                mvaddstr(y,x,"\45");
            else
            {
                mvaddstr(y,x," ");
            }

        }
    }


    int i = 0,j=0,line=1;

    int CenWidthBox = (Width)/2;
    int Strlength = strlen(msg);
    int length = Strlength;
    while(length > CenWidthBox*1.5)
    {
        length -=CenWidthBox;
        line++;
    }

    if(Height>4)
        j=2;
    else
        j=1;
    //inputs the text into the window
    for(int y = Y+j; y < Height+Y; y++)
    {
        for(int x = X+CenWidthBox*0.25; x < X+CenWidthBox*1.75; x++)
        {
            if(i< length)
            {
                mvaddch(y,x,msg[i]);
                i++;
            }
            else
            {
                if(line > 1)
                {
                    length +=CenWidthBox;
                    line--;
                    mvaddch(y,x,msg[i]);
                    i++;
                }
            }
        }
    }
}

void CDisplay::Message(const char *msg)
{
    Message(WinWidth/6,(4*WinHeight)/5,(2*WinWidth)/3,WinHeight/5, msg);
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

    case 'Á':
        attron(COLOR_PAIR(COLOR_WHITE));
        printw("A");
        print = true;

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


void CDisplay::Battle(Player plyone, Enemy Mob)
{

    for(int y=0; y<=WinHeight-Displaycenset; y++)
    {
        for(int x=0; x<WinWidth; x++)
        {
            mvaddch(y-1,x,' ');
        }
        if(y>WinHeight/5)
        {
            Message(WinWidth/6,(1*WinHeight)/5,(2*WinWidth)/3,WinHeight/5, "Talk");
        }

        if(y>(2*WinHeight)/5)
        {
            Message(WinWidth/6,(2*WinHeight)/5,(2*WinWidth)/3,WinHeight/5, "Action");
        }

        if(y>(3*WinHeight)/5)
        {
            Message(WinWidth/6,(3*WinHeight)/5,(2*WinWidth)/3,WinHeight/5, "Selection");
        }
        if(y % (WinHeight/12) == 0)
        {

            init_StatusBar(y,plyone);
            wait(40000);

            refresh();
        }




    }
    wait(10000);

    refresh();


    while(BattleMode == true)
    {
        clear();
        move(0,0);
        Message(WinWidth/6,(3*WinHeight)/5,(2*WinWidth)/3,WinHeight/5, "Selection");
        Message(WinWidth/6,(2*WinHeight)/5,(2*WinWidth)/3,WinHeight/5, "Action");
        Message(WinWidth/6,(1*WinHeight)/5,(2*WinWidth)/3,WinHeight/5, "Talk");
        init_StatusBar(WinHeight-Displaycenset,plyone);
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

