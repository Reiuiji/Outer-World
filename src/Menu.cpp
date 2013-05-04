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

//tmp to test
#define version "OuterW@rld InDev-Build V.83"
#include <stdlib.h>
#include "Game.h"
#include "Display.h"
#include "Menu.h"
//#include "Player.h"

#ifdef _WIN32
#include "..\..\ECE264FinalProject\dependencies\curses.h"
#endif
#ifdef linux
#include <curses.h>
#endif

//initilize the colors for the terminal
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
    attron(COLOR_PAIR(COLOR_BLACK));
};

//menu that will manage the specific resolution
void ResolutionMenu()
{
    bool select = true;
    UpdateScreen();
    int dotx = 4;
    clear();
    while(select == true)
    {
        CDisplay win;

        attron(A_BOLD);
        attron(COLOR_PAIR(COLOR_RED));
        mvaddstr(MenuX,MenuY, "Resolution :");
        move(MenuX+2,MenuY+4);
        printw("%d height, %d width",WinHeight,WinWidth);
        attron(COLOR_PAIR(COLOR_GREEN));
        mvaddstr(MenuX+4,MenuY+4, "Enter custom height and width");
        mvaddstr(MenuX+6,MenuY+4, "Auto Set the height and width");
        mvaddstr(MenuX+8,MenuY+4, "Enable/Disable Auto:");
        if(AutoDisplay == false)
        {
            mvaddstr(MenuX+8,MenuY+25, "Disables");
        }
        else
        {
            mvaddstr(MenuX+8,MenuY+25, "Enable");
        }
        mvaddstr(MenuX+10, MenuY+4, "Set height 20, width 40");
        mvaddstr(MenuX+12, MenuY+4, "Set height 30, width 70");
        mvaddstr(MenuX+14, MenuY+4, "Set height 40, width 100");
        mvaddstr(MenuX+16, MenuY+4, "Exit");
        win.init_Border(0);
        attron(COLOR_PAIR(COLOR_BLUE));
        mvaddch(dotx+MenuX, doty, ACS_DIAMOND);
        int c = getch();
        switch(c)
        {
        case KEY_DOWN:
            dotx += 2;
            break;

        case KEY_UP:
            dotx -= 2;
            break;

        case '\n':

            if(dotx == 4)
            {
                clear();
                mvaddstr(MenuX+8,MenuY+4,  "Height:");
                mvaddch(MenuX+8,MenuY+2, ACS_DIAMOND);
                move(MenuX+8,MenuY+14);
                scanw("%d",&WinHeight);

                mvaddstr(MenuX+10,MenuY+4, "Width:");
                mvaddch(MenuX+10,MenuY+2, ACS_DIAMOND);
                move(MenuX+10,MenuY+14);
                scanw("%d",&WinWidth);

            };

            if(dotx == 6)
            {
                getmaxyx(stdscr,WinHeight,WinWidth);
            };

            if(dotx == 8)
            {
                if(AutoDisplay == false)
                {
                    AutoDisplay = true;
                }
                else
                {
                    AutoDisplay = false;
                }
            };

            if(dotx == 10)
            {
                WinHeight=20;
                WinWidth=40;
            };

            if(dotx == 12)
            {
                WinHeight=40;
                WinWidth=60;
            };

            if(dotx == 14)
            {
                WinHeight=40;
                WinWidth=100;
            };


            if(dotx == 16)
            {
                select = false;
            };

            break;
        }
        UpdateScreen();
        clear();
        if(dotx > 16)
        {
            dotx = 4;
        }
        if(dotx < 4)
        {
            dotx = 16;
        }
    }
}


void optionsMenu()
{

    bool select = true;
    UpdateScreen();
    int dotx = 10;
    clear();
    while(select == true)
    {
        attron(A_BOLD);
        attron(COLOR_PAIR(COLOR_CYAN));
        mvaddstr(MenuX+4,MenuY, "Options");
        attron(COLOR_PAIR(COLOR_YELLOW));
        mvaddstr(MenuX+10, MenuY+4, "Change Resolution");
        mvaddstr(MenuX+12, MenuY+4, "Back");
        attron(COLOR_PAIR(COLOR_BLUE));
        mvaddch(dotx+MenuX, doty, ACS_DIAMOND);
        int c = getch();
        switch(c)
        {
        case KEY_DOWN:
            dotx += 2;
            break;

        case KEY_UP:
            dotx -= 2;
            break;

        case '\n':

            if(dotx == 10)
            {
                ResolutionMenu();
            };

            if(dotx == 12)
            {
                select = false;
            };


            break;
        }
        UpdateScreen();
        clear();
        if(dotx > 12)
        {
            dotx = 10;
        }
        if(dotx < 10)
        {
            dotx = 12;
        }
    }
};

void GameMenu()
{
    UpdateScreen();
    bool select = true;
    int dotx = 8;
    clear();
    while(select == true)
    {
        attron(A_BOLD);
        attron(COLOR_PAIR(COLOR_CYAN));
        mvaddstr(MenuX+4,MenuY, "Game Mode");
        attron(COLOR_PAIR(COLOR_YELLOW));
        mvaddstr(MenuX+8, MenuY+4, "Start Game");
        mvaddstr(MenuX+10, MenuY+4, "Load Game");
        mvaddstr(MenuX+12, MenuY+4, "Difficulty");
        mvaddstr(MenuX+14, MenuY+4, "Exit");
        attron(COLOR_PAIR(COLOR_BLUE));
        mvaddch(dotx+MenuX, doty, ACS_DIAMOND);
        int c = getch();
        switch(c)
        {
        case KEY_DOWN:
            dotx += 2;
            break;

        case KEY_UP:
            dotx -= 2;
            break;

        case '\n':

            if(dotx == 8)
            {
                //Player User(1);
                play=true;
                Game(/*User*/);
            };

            if(dotx == 10)
            {

            };

            if(dotx == 12)
            {

            };


            if(dotx == 14)
            {
                select = false;
            };

            break;
        }
        clear();
        if(dotx > 14)
        {
            dotx = 8;
        }
        if(dotx < 8)
        {
            dotx = 14;
        }
        mvaddch(dotx+MenuX, doty, ACS_DIAMOND);
    }
};

void mainMenu()
{
    UpdateScreen();
    int dotx = 8;
    init_col();

    while(1)
    {
        attron(COLOR_PAIR(COLOR_BLUE));
        attron(A_BOLD);
        mvaddstr(MenuX+4,MenuY,version);
        attron(COLOR_PAIR(COLOR_GREEN));
        mvaddch(dotx+MenuX, doty, ACS_DIAMOND);
        attron(COLOR_PAIR(COLOR_RED));
        mvaddstr(MenuX+8, MenuY+4, "Play");
        mvaddstr(MenuX+10, MenuY+4, "Options");
        mvaddstr(MenuX+12, MenuY+4, "Quit");
        attroff(A_BOLD);
        int c = getch();
        switch(c)
        {
        case KEY_DOWN:
            dotx += 2;
            break;

        case KEY_UP:
            dotx -= 2;
            break;

        case '\n':
            if(dotx == 8)
            {
                GameMenu();
            };

            if(dotx == 10)
            {
                optionsMenu();
            };

            if(dotx == 12)
            {
                endwin();
                exit(1);
            };
            break;
        }
        UpdateScreen();
        clear();
        if(dotx > (12))
        {
            dotx = 8;
        }
        if(dotx < 8)
        {
            dotx = 12;
        }
        mvaddch(dotx+MenuX, doty, ACS_DIAMOND);
    }

}

void UpdateScreen()
{
    if(debug == true)
    {
        mvprintw(0,0,"M(X,Y): (%d,%d)", MenuX,MenuY);
        mvprintw(1,0,"P(X,Y): (%d,%d)", dotx,doty);
    }
    if(AutoDisplay==true)
    {
        getmaxyx(stdscr,WinHeight,WinWidth);
    }
    MenuX = WinHeight/8;
    MenuY = WinWidth/3;
    doty = MenuY-2;
}
