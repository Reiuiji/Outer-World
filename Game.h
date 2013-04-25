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
#include "Definition.h"

int Game(/*Player USER*/);
void Move(int &x,int &y,int xcen, int ycen,char Map[][MapMax]);
bool MoveCheck(int &x,int &y,int xcen, int ycen, int xmove, int ymove, char Map[][MapMax]);

bool CollisionCheck(int x, int y, int xcen, int ycen, char Map[][MapMax], char event);
bool CollisionRangeCheck(int x, int y, int xcen, int ycen, char Map[][MapMax], char Start, char End);
void eventListener(int x, int y, int xcen,int ycen, char Map[][MapMax], char input);

// void eventListener(int x,int y, char* Map[][MapMax], char input);

void eventListener(int x,int y, char* Map[][MapMax], char input);

int Input(void);
