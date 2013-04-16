/* ECE 264 Group Prject: menu.cpp
 *
 * This software is licensed under the terms of the MIT-License
 * See COPYING for further information.
 * ---
 * Copyright (C) 2013 Daniel Noyes <Reiuiji@gmail.com>
 */

//tmp to test
#define version "Test 0.01"
#include <curses.h>
#include <stdlib.h>
#include "Game.h"
#include "Display.h"


void init_col()
{
    start_color();
    init_pair(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
    init_pair(12, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(54, COLOR_BLACK, COLOR_BLUE);
    init_pair(53, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(52, COLOR_BLACK, COLOR_WHITE);
    init_pair(51, COLOR_CYAN, COLOR_WHITE);
    init_pair(50, COLOR_BLUE, COLOR_WHITE);
    init_pair(49, COLOR_RED, COLOR_YELLOW);
    init_pair(48, COLOR_MAGENTA, COLOR_YELLOW);
    init_pair(60, COLOR_BLUE,COLOR_BLUE);
    init_color(COLOR_BROWN,800,520,245);
    init_pair(ENV_WATER, COLOR_BLUE,COLOR_BLUE);
    init_pair(COLOR_BROWN, COLOR_BROWN,COLOR_BLACK);
    attron(COLOR_PAIR(COLOR_BLACK));
};

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
        win.init_Border();
        mvaddstr(4,30, "Resolution :");
        move(6,34);
        printw("%d height, %d width",WinHeight,WinWidth);
        attron(COLOR_PAIR(COLOR_GREEN));
        mvaddstr(8, 34, "Set height 20, width 40");
        mvaddstr(10, 34, "Set height 40, width 40");
        mvaddstr(12, 34, "Set height 60, width 40");
        mvaddstr(14, 34, "Set height 20, width 40");
        mvaddstr(16, 34, "Set height 40, width 60");
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
                WinHeight=20;
                WinWidth=40;
            };

            if(dotx == 10)
            {
                WinHeight=40;
                WinWidth=40;
            };

            if(dotx == 12)
            {
                WinHeight=60;
                WinWidth=40;
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
                play=true;
                Game();
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

