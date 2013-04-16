/* ECE 264 Group Prject: main.cpp
 *
 * This software is licensed under the terms of the MIT-License
 * See COPYING for further information.
 * ---
 * Copyright (C) 2013 Daniel Noyes <Reiuiji@gmail.com>
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
    cerr << GameName << "  (compiled: " << __DATE__ << ")";
    cerr << " Ver." << string(revision).substr(string(revision).find(" "), string(revision).rfind("$") - string(revision).find(" ")) //trick learned from EPIPHANY e-server, thank for the idea
         << endl;

    cerr << copyrigth << GameName << " Created for ECE264 Group Project(Spring 2013)\n";
    cerr << "\n\033[4mPlease report bugs to:\033[0m \033[1m<reiuiji@gmail.com>\033[0m" << endl;
} //\033 set default text and \033[1m makes it bold and \033[0m change back
void Usage()
{
    cerr << "\033[4mUsage:\033[0m" << endl;
    cerr << endl;

    cerr << GameName << " [--load <data-file>] [--debug] [--version] [--help]" << endl;
    cerr << endl;

    cerr << "\033[4mProgram options:\033[0m" << endl;
    cerr << endl;

    cerr << " \033[1m--load   \033[0m" << "\t\tLoad a save file to the game" << endl;

    cerr << " \033[1m--debug  \033[0m" << "\t\tEnables Debug mode" << endl;

    cerr << " \033[1m--version\033[0m" << "\t\tDisplay the version number and copyrights" << endl;

    cerr << " \033[1m--help  \033[0m" << "\t\tDisplays the Help screen(you looking at it ;D)" << endl;

    cerr << endl;
    cerr << "This program is covered by the GNU General Public License. See COPYING for" << endl;
    cerr << "further information." << endl;
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

//-----------------------------------
    attron(COLOR_PAIR(COLOR_BLUE));
    mainMenu();
    return 0;
}
