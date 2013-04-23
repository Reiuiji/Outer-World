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

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <curses.h>
#include <string.h>


#include "menu.h"
#include "Definition.h"
#include "Display.h"

using namespace std;

const char *copyrigth = "Copyright (C) 2013 Daniel Noyes <Reiuiji@gmail.com>\n";
static char const * revision= "$Rev: 12 $";
char const load_name[] = "test.Dat";

void Verion()
{
    cout << GameName << "  (compiled: " << __DATE__ << ")";
    cout << " Ver." << string(revision).substr(string(revision).find(" "), string(revision).rfind("$") - string(revision).find(" ")) //trick learned from EPIPHANY e-server, thank for the idea
         << endl;

    cout << copyrigth << GameName << " Created for ECE264 Group Project(Spring 2013)\n";
    cout << "\n\033[4mPlease report bugs to:\033[0m \033[1m<reiuiji@gmail.com>\033[0m" << endl;
} //\033 set default text and \033[1m makes it bold and \033[0m change back
void Usage()
{
    cout << "\033[4mUsage:\033[0m" << endl;
    cout << endl;

    cout << GameName << " [--load <data-file>] [--debug] [--version] [--help]" << endl;
    cout << endl;

    cout << "\033[4mProgram options:\033[0m" << endl;
    cout << endl;

    cout << " \033[1m--load   \033[0m" << "\t\tLoad a save file to the game" << endl;

    cout << " \033[1m--debug  \033[0m" << "\t\tEnables Debug mode" << endl;

    cout << " \033[1m--version\033[0m" << "\t\tDisplay the version number and copyrights" << endl;

    cout << " \033[1m--help  \033[0m" << "\t\tDisplays the Help screen(you looking at it ;D)" << endl;

    cout << endl;
    cout << "This program is covered by the GNU General Public License. See COPYING for" << endl;
    cout << "further information." << endl;
}

int main(int argc, char *argv[])
{
    //WINDOW *MainWindow;
    debug = false;
    //char *load_file = getenv(load_name);
    for (int n = 1; n < argc; n++)
    {
        if (!strcmp(argv[n], ""))
        {
            return 1;
        }
        if (!strcmp(argv[n], "--load"))
        {
            //load feature
//            n += 1;
//            if (n >= argc)
//            {
//                Usage();
//                return 3;
//            }
//            else
//            {
//                if (load_file)
//                {
//                    cerr << "Warning: Load Var <" << load_name << "> is overwritten by command line option." << endl;
//                }
//                load_file = argv[n];
//            }
            return 1;
        }
        if (!strcmp(argv[n], "--debug"))
        {
            debug = true;
            return 1;
        }
        if (!strcmp(argv[n], "--version"))
        {
            Verion();
            return 1;
        }
        if ((!strcmp(argv[n], "--help")) || (!strcmp(argv[n], "-h")))
        {
            Usage();
            return 1;
        }
    }

//    if (load_file == 0)
//    {
//        cerr << "Please specify a Player Data file." << endl << endl;
//        Usage();
//        return 3;
//    }

#ifdef PDCURSES
    PDC_set_title(version);
#endif

//---------Initialize Curses---------

    keypad(initscr(), 1);
    keypad(stdscr, TRUE);
    curs_set(0);
    //wresize(MainWindow, WinWidth, WinHeight);
    if(AutoDisplay==true)
    {
        getmaxyx(stdscr,WinHeight,WinWidth);
    }
//-----------------------------------
    attron(COLOR_PAIR(COLOR_BLUE));
    mainMenu();
    return 0;
}
