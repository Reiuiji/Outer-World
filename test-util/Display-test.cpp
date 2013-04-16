/* ECE 264 Group Prject: Display-test.cpp
 *
 * This software is licensed under the terms of the MIT-License
 * See COPYING for further information.
 * ---
 * Copyright (C) 2013 Daniel Noyes <Reiuiji@gmail.com>
 */

//this will test the display function
//first make it output as a printf then interpet to various gui (api)
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <curses.h>
#include <time.h>
#include <math.h>

#define MapMax 202
#define MaxHeight   40
#define MaxWidth    100

#define Displaycenset 5

void Move(int &x,int &y,int xcen, int ycen,char Map[][MapMax]);
bool MoveCheck(int &x,int &y,int xcen, int ycen, int xmove, int ymove, char Map[][MapMax]);
int Input(void);

bool debug = false;

class CDisplay	//curses display
{
public:
    void init_StatusBar();
    void init_Border();

    void Display(int Sx, int Sy, int x, int y,int xcen, int ycen, char Map[][MapMax]);


    void DebugScreen(int x,int y, char Map[][MapMax]);
};

char m1[10][MapMax] =  //set a map max main to test with diff aspects
{
    {"+------------------+"},
    {"|\\      /\\/\\      /|"},
    {"| \\    / /\\ \\    / |"},
    {"|  \\  / /  \\ \\  /  |"},    //anoyed \\ since \ will not show
    {"|   \\/ / /\\ \\ \\/   |"},
    {"|   /\\ \\ \\/ / /\\   |"},
    {"|  /  \\ \\  / /  \\  |"},
    {"| /    \\ \\/ /    \\ |"},
    {"|/      \\/\\/      \\|"},
    {"+------------------+"},
};

char StatusBar[5][102] =
{
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    "X  Health                    /             equiped items               \\                     Mana   X",
    "X  [                      ] || [j:  ] [k:  ] [j: ] [i: ]  [sword:    ] || [                      ]  X",
    "X  ___%                      \\                                         /                     ___%   X",
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};

char Default_200X100_Map_Grid [202][202] =  //center is x=100,y=50      x = x+100; y = 50-y;
{
    "+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+",
    "|                                                                                                                                                                                                       |",
    "|                                                                                                                                                                                                       |",
    "|                                                                                                                                                                                                       |",
    "|                                                                                                                                           www                                                         |",
    "|                                                                                                                                        wwwwwwwwww                                                     |",
    "|                                                                                                                                    wwwwwwwwwwwwwwww                                                   |",
    "|                                                                                                                                  wwwwwwwwwwwwwwwwwwww                                                 |",
    "|                                                                                                                                  wwwwww  /=v  wwwwwwww                                                |",
    "|                                                                                                                                 wwwwww  |xxx|  wwwwwww                                                |",
    "|                                                                                                                                 wwwwwww |xxx| wwwwwww                                   mmmm  mmmm    |",
    "|                                                                                                                                 wwwwwwww     wwwwwww                           mmmm  mmm    mm    mmmm|",
    "|                                                                                                                                   wwwwwwwwwwwwwwwww                        mmmm    mm                 |",
    "|                                                                                                                                     wwwwwwwwwwwww                      mmmm                           |",
    "|                                                                                                                                         wwwwwww                     mmm               mmm             |",
    "|                                                                                                                                          wwwwww                    mm         mmmm   m   mm  mm       |",
    "|                                                                                                                                           wwwww                  mm        mmmm   mmm      mm  mm     |",
    "|                                                                                                                                          wwwww                  mm        mm                     mm   |",
    "|                                                                                                                                           wwww                  mm       mm                        mm |",
    "|                                                                                                                                          wwwwww                 m        m                           m|",
    "|                                                                                                                                        wwwwwww                   mm      m       000000000           m|",
    "|                                                                                                                                      m wwwwww                    mm      mm     0         0          m|",
    "|                                                                                                                                       mmwwwwmm           mmm   mmm        m     0    F    0          m|",
    "|                                                                                                                           mm            ffff  mmmmm   mmm   mmmm          m     0    @    0          m|",
    "|                                                                                          mmm      mmmmm                     mmmm  mmm   ffff      mmmm                    m     0         0          m|",
    "|                                                                                   mmmmmmm   mmmmmm     mmm                      mm   mm ffff                              m      000~~~000          mm|",
    "|                                                                             mmmmmmm                       mmmmm                        mwwwwm                              mm       ###            mmm|",
    "|                                                                           mmmmm                                mmm           mwww        www m          mmmmm               mm     ###             mmm|",
    "|                                                                         mm                                        mm          mwwwww      www          mm   mmmm              mm   ###   mmmm    mmm  |",
    "|                                                                       mm                mmmmmmmmm    mmmm           m          mmmwwwww  wwww        mmm        mmmm   mmmmm   mmmm###mmmmm  mmmm     |",
    "|                                                                     mm               mmm         mmmm    mm          mmm          mmwwwwwwwww        m     mmm      mmm     mmmmmmm########mmm        |",
    "|                                                                   mm              mmm                      mmm          mm          mmwwwwwww        m      m      m      m    mmmmmmmm######m        |",
    "|                                                          mmmm  mmm           mmmmm             mmmmmmm        mmm         mmm         mwwww         mm  m           m    m    m#######mmm####m   mmm  |",
    "|                                                       mmm    mm          mmmmm                mmmxxxmmm          mm          mmm       www         mm  mm                    m###############mm    mm |",
    "|                                                     mm                   m              m     mmxxxxxmm     mm     mmmmmm       mmm     ww        mm        mmmmmm     mmm  mm##mmmmm######mm         |",
    "|                                                  mm                     mm            m       mmxxxxxmm       m         mm         mm    ww      mm        mm    mm          m######mmmmmmm    mm     |",
    "|                                               mmm                      mm           mm        mmm~~~mmm                   mm              ww    mm       mmm      mmm         mmm#########mm     m    |",
    "|                                             mm                       mm    m          m       mm  @  mm         mm   m      m            www    m   mm   m          mm       mmmmmm#######mmm         |",
    "|                    mm                     mm                         m    m                   mm  D  mmm          m m        m          www   mmm  mm    m           mmm  mmm          ###  mmm  mm   |",
    "|                mmmm  mm mm mmm mm       mm                          mm                        m        mmm               m    mmm     www    mm         mm              mm             ###     mm  mm |",
    "|           mm mm                  mmm  mm                           m            mmmm        mmm          mmmmmm                  mm   wwwww mm         mm                              ####          m|",
    "|         mm  m                       mm                            m          mmmm   mmm   mmm               mmmmm                  mmmwwwwwmm   m    mmm                                ####         m|",
    "|     mmmm                                                         m         mmm         mmm                      mmmmmmmm     mm      mmmwwmm   mm   mmm                                  ####         |",
    "|   mm                 mm mm                                       m       mmm                                           mm   mmm         ff          m        /v                           ###         |",
    "|mmm                 mm     mm mmmm                              mmm      mm                                              mmm       mmm   ff mmm     mm       /  v                          ###         |",
    "|                 mmmm             mm                           mm  m    mm                                                 m      mm     ff   m   mm        /____v                         ###         |",
    "|                m                                              m   m   mm                                                  mm          mmffmm   mm            []           /v              ###         |",
    "|               m                   mmmmmm                      m       mm        0000000        =======        =======      mm    mmmmmmwwwwwmmm                          /  v             ###         |",
    "|               m      mmm  mmmmm mm      mmmmmm       mmm      m      mm        0       0      /  [&]  v      /  +--+ v      mmmmmm   wwwwwwwww                          /____v            ###         |",
    "|              mmm  mmm   mm     m       mmm            mm       m     m        0 ++      0    |         |    |  B+--+  |              wwwwwwwww                            []              ###         |",
    "|         mm mm   mm                   mmm                       m      m       0 ||   A  0    |         |    |  @      |               wwwwwww            wwwwwwwwww                       ###         |",
    "|      mmm  m                      mmmm        mm                m      m       0 ++   @  0    |         |    |         |                 wwww            wwwwwwwwwwww                      ###         |",
    "|     m                         mmm       mmmmmmm                mm      m       0       0      v       /      v       /                   wwwww     wwwwwww  wwwwwwwwwww                   ###         |",
    "|    m                         m        mm       mm             mm        m       00~ ~00        ==~ ~==        ==~ ~==                    wwwwwwwwwwwwwwww         wwwwwwww                ###         |",
    "|  mm            mm           mm      mmm          mm          mm     m   m         ###            ###            ###                      wwwwwwwwwwww                 wwwwwwwww          ####         |",
    "|mm    m m        m            mm        mm          mmmm     m       m   m         #################################                     wwww                               wwwww       #####          |",
    "|     m                    mmmm  mmmmm     mm            mm mm            m          ###############################                      wwww          #####################################           |",
    "|                        mm    mmm   mmm    mm             m               m                     #######                                wwwww          ######################################           |",
    "|             mmmmmm  mmm         mmm         mmm  mmm                     m                      #####    /v                        wwwwwww           #####                  www        #####          |",
    "|           mmm    mmm                          mmm  mm          mm        m                       ###    /  v                 wwwwwwwwwwww             ###                  www           ####         |",
    "|         mmm                                          mm    m mm          m                       ###   /____v              wwwwwwwwwwwww              ###                 www             ###         |",
    "|       mmm                                             m   mmm            mmm            /v       ###     []               wwwwwwwwwwwwwww             ###                www              ###    G    |",
    "|  m    m                                  /v           mm m       mmmm      mm          /  v      ###             /v       wwwwwwwwwwwwww     000      ###               wwwwwwwww         ###    @   0|",
    "|  m   mm                                 /  v           mmm         mmmm     mmm       /____v     ###            /  v      wwwwwwwwwwwww     0xxx0     ###          wwwwwwwwwwwwwwwwww     ####       0|",
    "|      m        000000000                /____v           mmm            mm      m        []       ###           /____v      wwwwwwwwww       0xxx0     ###         ww      wwwwwwwwwwww    ###########~|",
    "|      m       0         0                 []              mmm             m      mmm              ###             []         wwwww            0~0      ###    -------------        www      ##########~|",
    "|     mm       0    I    0                                   mmmm            m      mm             ###                         wwww                    ####    |ooooooooooo|        www                0|",
    "|    mm        0    @    0                                      mmmmmmmm     m mmm   m             ###      /v                  www                   #####    |+++++++++++|   E    www                0|",
    "|    m         0         0                                             mmmmm   mm    m             ###     /  v                www                ########     |ooooooooooo|   @    wwww               0|",
    "|    m          000~~~000                                                  mmm   m   m             ###    /____v              www       ###############        |+++++++++++|         wwww       /v /v  0|",
    "|   mm             ###                                                       mm   m  m             ###      []                ww      ##############           |ooooooooooo|          wwww     /  /  v 0|",
    "|  mm              ###                                                         mm    m H           ###                        ww     #####                     |-----------|           www  /v /v /v /v |",
    "|mmm               ####                                                         mmmmm  @          #####                       ww   #####                                              www  /  /  /  /  /|",
    "|m                  ####                                                         000             #######                      ww  #####                                              www   /v /v /v /v /|",
    "|                    ############################################################# ###################################################                                                wwww/  /  /  /  / |",
    "|                      ###########################################################~##################################################     /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v|",
    "|                                                                                000             #######                      www        /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  |",
    "v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v    #####    /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v |",
    " v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v    ###    /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /|",
    "/v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v    ###    /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /|",
    "  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v   ###   /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  / |",
    " /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v___v  ###  /___/v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v|",
    "v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v]    ###    [/  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  |",
    "v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v     ###     /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v |",
    " v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v    ###    /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  v|",
    "/v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v___v   ###   /___/v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /|",
    "  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v]     ###     [/  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  / |",
    " /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v      ###      /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v|",
    "v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v     ###     /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  |",
    "v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v___v    ###    /___/v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v |",
    " v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v]      ###      [/  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  v|",
    "/v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v       ###       /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /|",
    "  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v      ###      /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  / |",
    " /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v___v     ###     /___/v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v|",
    "v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v]       ###       [/  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  |",
    "v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v     ###     /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v |",
    " v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v    #C#    /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /|",
    "/v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v___v   #@#   /___/v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /|",
    "  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v]    =~~~=    [/  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  / |",
    " /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v / ### v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v /v|",
    "v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v  v-------/  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /  /",
};

int main()
{
    int x=0,y=0;

//    struct timespec tim,tim2;
//    tim.tv_sec = 0;
//    tim.tv_nsec = 1000000L;

    //setup curses
#ifdef PDCURSES
    PDC_set_title(version);
#endif
    keypad(initscr(), 1);
    curs_set(0);
    attron(COLOR_PAIR(COLOR_BLUE));

    CDisplay test;


    while(1)
    {


        //attron(A_REVERSE);
//  y=10*sin(x)+50;
        test.init_StatusBar();
        test.Display(MaxWidth,MaxHeight,x,y,100,50,Default_200X100_Map_Grid);
        test.init_Border();
        test.DebugScreen(x,y,Default_200X100_Map_Grid);

//    x++;
//    if(x == 200)
//    {
//        x=100;
//    }
        Move(x,y,100,50,Default_200X100_Map_Grid);
        refresh();
        //nanosleep(&tim,&tim2);
        //attroff(A_REVERSE);



    }

    return 0;
}

void Move(int &x,int &y,int xcen, int ycen,char Map[][MapMax])
{
    switch(Input())
    {
    case KEY_UP:
    case 'w':
        if(MoveCheck(x,y,xcen,ycen,0,1,Map) == 0)
            y++;
        break;
    case KEY_DOWN:
    case 's':
        if(MoveCheck(x,y,xcen,ycen,0,-1,Map) == 0)
            y--;
        break;
    case KEY_LEFT:
    case 'a':
        if(MoveCheck(x,y,xcen,ycen,-1,0,Map) == 0)
            x--;
        break;
    case KEY_RIGHT:
    case 'd':
        if(MoveCheck(x,y,xcen,ycen,1,0,Map) == 0)
            x++;
        break;

    case 'q':
        if(MoveCheck(x,y,xcen,ycen,-1,+1,Map) == 0 && (MoveCheck(x,y,xcen,ycen,0,+1,Map) == 0 || MoveCheck(x,y,xcen,ycen,-1,0,Map) == 0))
        {
            x--;
            y++;
        }
        break;
    case 'e':
        if(MoveCheck(x,y,xcen,ycen,+1,+1,Map) == 0 && (MoveCheck(x,y,xcen,ycen,0,+1,Map) == 0 || MoveCheck(x,y,xcen,ycen,+1,0,Map) == 0))
        {
            x++;
            y++;
        }
        break;
    case 'z':
        if(MoveCheck(x,y,xcen,ycen,-1,-1,Map) == 0 && (MoveCheck(x,y,xcen,ycen,0,-1,Map) == 0 || MoveCheck(x,y,xcen,ycen,-1,0,Map) == 0))
        {
            x--;
            y--;
        }
        break;
    case 'c':
        if(MoveCheck(x,y,xcen,ycen,+1,-1,Map) == 0 && (MoveCheck(x,y,xcen,ycen,0,-1,Map) == 0 || MoveCheck(x,y,xcen,ycen,+1,0,Map) == 0))
        {
            x++;
            y--;
        }
        break;
    case '`':
        if(debug == false)
            debug = true;
        else
            debug = false;
        break;
    default:
        break;
    }
}

int Input(void)
{
    int ch = getch();
    return ch;
}

bool MoveCheck(int &x,int &y,int xcen, int ycen, int xmove, int ymove, char Map[][MapMax])
{
    if(strncmp(&Map[ycen-y-ymove][x+xcen+xmove]," ",1) == 0 || strncmp(&Map[ycen-y-ymove][x+xcen+xmove],"#",1) == 0)
        return 0;
    else
        return 1;
}

void CDisplay::init_StatusBar()
{
    move(0,0);
    for(int i = 0; i<5; i++)
    {
        for(int j = 0; j<=100; j++)
            printw("%c",StatusBar[i][j]);
        printw("\n");
    }
}

void CDisplay::init_Border()
{
    move(Displaycenset+1,0);
    for(int i = 0; i<=MaxHeight; i++)
    {
        for(int j = 0; j<=MaxWidth; j++)
            if(i == 0 || i == MaxHeight || j == 0 || j == MaxWidth)
            {
                mvaddch(Displaycenset+i,j,'X');
            }
    }
}

void CDisplay::DebugScreen(int x, int y, char Map[][MapMax])
{
    move(Displaycenset+MaxHeight+1,0);
    if(debug == true)
    {
        printw("X: %d\n",x);
        printw("Y: %d\n",y);
        printw("MapMax: %d\n",MapMax);
        printw("MaxHeight: %d\n",MaxHeight);
        printw("MaxWidth: %d\n",MaxWidth);
        printw("LX: min: %d    max: %d\n",(x-MaxWidth/2),(x+MaxWidth/2) );
        printw("LY: min: %d    max: %d\n",(y-MaxHeight/2),(y+MaxHeight/2) );
    }
    else
    {
        for(int i = 0 ; i<7; i++)
        {
            for(int j = 0; j<40;j++)
                printw(" ");
            printw("\n");
        }
    }
}

void CDisplay::Display(int Sx, int Sy, int x, int y,int xcen, int ycen, char Map[][MapMax]) //have to hard code for array, change to vector after test
{
    x = x+xcen; //center cords
    y = ycen-y;
    move(Displaycenset,1);
    for(int Ly = (y-Sy/2) ; Ly < (y+Sy/2); Ly ++)
    {
        //bool EOL = false; //check state for end of line

        for(int Lx = (x - Sx/2) ; Lx < (x + Sx/2) ; Lx++)
        {
//            if(Ly == (y-Sy/2) || Ly == (y+Sy/2) || Lx == (x + Sx/2) || Lx ==( x - Sx/2) )
//            {
//                printf("X");
//            }
//            if(Lx == x && Ly == y)
//                //mvaddch(Ly,Lx,'@');
//                printw("@");
//            else
//            {
            if( Ly >= 0 && Ly < MapMax && Lx >= 0 && Lx < MapMax)
            {
                //mvaddch(Ly,Lx,Map[Ly][Lx]);
                if(Lx == x && Ly == y)
                {
                    printw("@");
                }
                else
                {
                    if(strncmp(&Map[Ly][Lx],"v",1) == 0)
                        printw("\\");
                    else
                        printw("%1c",Map[Ly][Lx]);
                }

            }
            else
            {
                //mvaddch(Ly,Lx,'+');
                printw(" ");
            }
            //          }
        }
        printw("\n");
    }
}
