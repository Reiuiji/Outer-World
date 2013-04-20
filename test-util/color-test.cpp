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
#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//color setup
#define COLOR_BLACK	    0
#define COLOR_RED	    1
#define COLOR_GREEN	    2
#define COLOR_YELLOW	3
#define COLOR_BLUE	    4
#define COLOR_MAGENTA	5
#define COLOR_CYAN	    6
#define COLOR_WHITE	    7
#define COLOR_BROWN     8
#define ENV_WATER       9
#define ENV_WFALL       10//water fall
#define ENV_PATH        11
#define ENV_TREE        12

void color_test(int Xpos, int Ypos, int Width, int Height, int ColorAStart, int ColorAEnd);
void init_col();
void init_col_2(short AStart, short AEnd);

int main()
{
#ifdef PDCURSES
    PDC_set_title(version);
#endif

//---------Initialize Curses---------

    keypad(initscr(), 1);
    keypad(stdscr, TRUE);
    curs_set(0);
    attron(COLOR_PAIR(COLOR_BLUE));
    init_col_2(0,40);
    while(1)
    {
        clear();
        //test color
        init_col();
        attron(COLOR_PAIR(COLOR_BLUE));
        mvaddstr(0,0, "Press q to exit");
        color_test(0,1,30,20,0,40);

        int c = getch();
        if(c == 'q')
        {
            exit(1);
        }

    }

    return 0;
}

void color_test(int Xpos, int Ypos, int Width, int Height, int ColorAStart, int ColorAEnd)
{
    int x,y;
    int A = ColorAStart;
    for(y=Ypos; y<Height; y++)
    {
        for(x=Xpos; x<Width; x++)
        {
            attron(COLOR_PAIR(A));
            mvaddstr(y,x,"#");
            A++;
            if(A>ColorAEnd)
            {
                A=ColorAStart;
            }
        }
    }

}

void init_col()
{
    start_color();
    init_pair(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
    init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_color(COLOR_BROWN,800,520,245);
    init_pair(ENV_WATER, COLOR_BLUE,COLOR_BLUE);
    init_pair(COLOR_BROWN, COLOR_BROWN,COLOR_BLACK);
    attron(COLOR_PAIR(COLOR_BLUE));
};

void init_col_2(short AStart, short AEnd)
{
    short A=0,B=0,C=0,D=0;
    for(A=AStart;A<=AEnd;A++)
    {
        B=(A/AEnd)*1000;
        init_color(A,B,C,D);
    }

}
