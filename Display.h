/* ECE 264 Group Prject: Display.h
 *
 * This software is licensed under the terms of the MIT-License
 * See COPYING for further information.
 * ---
 * Copyright (C) 2013 Daniel Noyes <Reiuiji@gmail.com>
 */



#include "Definition.h"
class CDisplay	//curses display
{
public:
    void init_StatusBar();
    void init_Border();
    void Display(int Sx, int Sy, int x, int y,int xcen, int ycen, char Map[][MapMax]);
    void Message(const char *);
    void DebugScreen(int x,int y, char Map[][MapMax]);
    void ColorMap(char var);
};
