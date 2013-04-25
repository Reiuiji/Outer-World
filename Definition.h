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
#define MapMax 202
#define MaxHeight   40
#define MaxWidth    100
#define GameName "test"

#define MaxMsg      50
#define XCenter     50
#define msg_X_Width 40
#define msg_Y_Width 20
#define YCenter     20

#define Displaycenset 5

//Global variables
extern int WinHeight;
extern int WinWidth;
//manage menu windows layout
extern int MenuX;
extern int MenuY;
extern int dotx;
extern int doty;


extern bool debug;
extern bool play;
extern bool BattleMode;
extern bool AutoDisplay;

//color setup
#define COLOR_BROWN 10
#define ENV_WATER   20
#define ENV_WFALL   21//water fall
#define ENV_PATH    22
#define ENV_TREE    23
