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
#include "Definition.h"
class CDisplay	//curses display
{
public:
    void init_StatusBar(Player player);
    void init_Border(int offset);
    void Display(int Sx, int Sy, int x, int y,int xcen, int ycen, char Map[][MapMax]);
    void Message(int X,int Y, int Width, int Height, const char *msg);
    void DebugScreen(int x,int y, char Map[][MapMax]);
    void ColorMap(char var);
};
