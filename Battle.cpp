/*
* ECE 264 Final Group Prject: Source Code
* Copyright (C) 2013 Daniel Noyes <Reiuiji@gmail.com> and Benjamin Doiron <ALEDelric@gmail.com>
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
#include "Definition.h"
#include <string.h>
#ifdef _WIN32
#include "dependencies/curses.h"
#endif
#ifdef linux
#include <curses.h>
#endif

//curses: outputs the border of the screen
//checks the limits of the border and output a border tag
/*void CDisplay::init_Border(int offset)
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
    std::string text (msg);
    int StringCen = (Width-6-(X+6))/2;
    //inputs the text into the window
    for(int y = Y+2; y < Height-2; y++)
    {
        for(int x = StringCen-text.length()/2; x < StringCen+text.length()/2; x++)
        {
            printw("%1c",text.at(x-(StringCen-text.length()/2)));

        }
    }
}
*/
