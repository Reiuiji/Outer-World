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
//#ifndef PLAYER_SET
//#define PLAYER_SET
#include <string>
class Player
{
public:
    Player(bool);                //implement new player
    void LoadPlayer(ifstream);   //import player data
    void SavePlayer(ifstream);   //export player data

    void Set_FN(string);
    string FN();
    void Set_LN(string);
    string LN();
    void Set_Name(string,string);

    void Set_LVL(int);
    void LVL_UP();
    int LVL();

    void Set_EXP(int);
    void Gain_EXP(int);
    int EXP();

    void MAX_Health(double);
    void Set_Health(double);
    void INC_Health(double);
    void DEC_Health(double);
    double H();

    void Set_Mana(int);
    void MAX_Mana(int);
    void INC_Mana(int);
    void DEC_Mana(int);
    double M();

    void Set_State(bool);
    bool S();

    void INT_Inventory(int);
    void Insert_Inventory(int);
    void Remove_Inventory(int);

    void Set_Position(float,float,int); //x,y,map#
    void Position(float&,float&,float&);
    void move(float,float);

private:
    string FirstName;
    string LastName;
    int Level;
    int Experience;
    double Health;
    double MaxHealth;
    int Mana;
    int MaxMana;
    bool State;

    int inventory;

    //position
    float Xpos;
    float Ypos;
    int Location;

};

//#endif
