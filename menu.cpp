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
#define version "Test 0.01"
#include <curses.h>
#include <stdlib.h>
#include "Game.h"
#include "Display.h"
//#include "Player.h"

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
    int dotx = 8;
    int doty = 32;
    clear();
    while(select == true)
    {
        attron(A_BOLD);
        attron(COLOR_PAIR(COLOR_CYAN));
        CDisplay win;
        win.init_Border(0);
        mvaddstr(4,30, "Resolution :");
        move(6,34);
        printw("%d height, %d width",WinHeight,WinWidth);
        attron(COLOR_PAIR(COLOR_GREEN));
        mvaddstr(8, 34, "Enter custom height and width");
        mvaddstr(10, 34, "Auto Set the height and width");
        mvaddstr(12, 34, "Enable/Disable Auto:");
                if(AutoDisplay == false)
                {
                    mvaddstr(12,55, "Disables");
                }
                else
                {
                    mvaddstr(12,55, "Enable");
                }
        mvaddstr(14, 34, "Set height 20, width 40");
        mvaddstr(16, 34, "Set height 30, width 70");
        mvaddstr(18, 34, "Set height 40, width 100");
        mvaddstr(20, 34, "Exit");
        attron(COLOR_PAIR(COLOR_BLUE));
        mvaddch(dotx, doty, ACS_DIAMOND);
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
                clear();
                mvaddstr(8,34,  "Height:");
                mvaddch(8,32, ACS_DIAMOND);
                move(8,44);
                scanw("%d",&WinHeight);

                mvaddstr(10,34, "Width:");
                mvaddch(10,32, ACS_DIAMOND);
                move(10,44);
                scanw("%d",&WinWidth);

            };

            if(dotx == 10)
            {
                getmaxyx(stdscr,WinHeight,WinWidth);
            };

            if(dotx == 12)
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

            if(dotx == 14)
            {
                WinHeight=20;
                WinWidth=40;
            };

            if(dotx == 16)
            {
                WinHeight=40;
                WinWidth=60;
            };

            if(dotx == 18)
            {
                WinHeight=40;
                WinWidth=100;
            };


            if(dotx == 20)
            {
                select = false;
            };

            break;
        }
        clear();
        if(dotx > 20)
        {
            dotx = 8;
        }
        if(dotx < 8)
        {
            dotx = 20;
        }
        mvaddch(dotx, doty, ACS_DIAMOND);
    }
}


void optionsMenu()
{

    bool select = true;
    int dotx = 9;
    int doty = 34;
    clear();
    while(select == true)
    {
        attron(A_BOLD);
        attron(COLOR_PAIR(COLOR_CYAN));
        mvaddstr(6,34, "Options");
        attron(COLOR_PAIR(COLOR_YELLOW));
        mvaddstr(9, 36, "Change Resolution");
        mvaddstr(11, 36, "Back");
        attron(COLOR_PAIR(COLOR_BLUE));
        mvaddch(dotx, doty, ACS_DIAMOND);
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

            if(dotx == 9)
            {
                ResolutionMenu();
            };

            if(dotx == 11)
            {
                select = false;
            };


            break;
        }
        clear();
        if(dotx > 11)
        {
            dotx = 9;
        }
        if(dotx < 9)
        {
            dotx = 11;
        }
        mvaddch(dotx, doty, ACS_DIAMOND);
    }
};

void GameMenu()
{

    bool select = true;
    int dotx = 8;
    int doty = 32;
    clear();
    while(select == true)
    {
        attron(A_BOLD);
        attron(COLOR_PAIR(COLOR_CYAN));
        mvaddstr(4,30, "Game Mode");
        attron(COLOR_PAIR(COLOR_YELLOW));
        mvaddstr(8, 34, "Start Game");
        mvaddstr(10, 34, "Load Game");
        mvaddstr(12, 34, "Difficulty");
        mvaddstr(14, 34, "Exit");
        attron(COLOR_PAIR(COLOR_BLUE));
        mvaddch(dotx, doty, ACS_DIAMOND);
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
        mvaddch(dotx, doty, ACS_DIAMOND);
    }
};

void mainMenu()
{
    int dotx = 8;
    int doty = 32;
    init_col();

    while(1)
    {
        attron(COLOR_PAIR(COLOR_BLUE));
        attron(A_BOLD);
        mvaddstr(4,30,version);
        attron(COLOR_PAIR(COLOR_GREEN));
        mvaddch(dotx, doty, ACS_DIAMOND);
        attron(COLOR_PAIR(COLOR_RED));
        mvaddstr(8, 34, "Play");
        mvaddstr(10, 34, "Options");
        mvaddstr(12, 34, "Quit");
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
        clear();
        if(dotx > 12)
        {
            dotx = 8;
        }
        if(dotx < 8)
        {
            dotx = 12;
        }
        mvaddch(dotx, doty, ACS_DIAMOND);
    }

}

