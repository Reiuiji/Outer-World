/* ECE 264 Group Prject: Player.cpp
 *
 * This software is licensed under the terms of the MIT-License
 * See COPYING for further information.
 * ---
 * Copyright (C) 2013 Daniel Noyes <Reiuiji@gmail.com>
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

//#include "items.h"
#include "Player.h"
Player::Player(bool S)
{
    Player::Set_Name("Crimson","Grimoire");
    Player::Set_LVL(1);
    Player::Set_EXP(0);
    Player::MAX_Health(20);
    Player::Set_Health(20);
    Player::MAX_Mana(5);
    Player::Set_Mana(5);
    Player::Set_State(S);
    Player::Set_Position(0,0,0);
}
//Player::Player(*Data_File)
//{
//    //implement a load feature for player
//}
//
//void Player::SavePlayer(*Data_File)
//{
//    //impement a save feature
//}

void Player::Set_FN(string FN)
{
    FirstName =  FN;
}

string Player::FN()
{
    return FirstName;
}

void Player::Set_LN(string LN)
{
    LastName = LN;
}

string Player::LN()
{
    return LastName;
}

void Player::Set_Name(string FirstName, string LastName)
{
    Player::Set_FN(FirstName);
    Player::Set_LN(LastName);
}

void Player::Set_LVL(int LVL)
{
    Level = LVL;
}

void Player::LVL_UP()
{
    Level = Level + 1;
}

int Player::LVL()
{
    return Level;
}

void Player::Set_EXP(int EXP)
{
    Experience = EXP;
}

void Player::Gain_EXP(int EXP)
{
    Experience = Experience + EXP;
    while( Experience >= (10*pow(Level,1.75)))
        LVL_UP();
}

int Player::EXP()
{
    return Experience;
}


void Player::MAX_Health(double H)
{
    MaxHealth = H;
}

void Player::Set_Health(double H)
{
    Health = H;
}

void Player::INC_Health(double INC)
{
    if((Health = Health + INC) > MaxHealth)
    {
        Health = MaxHealth;
    }
}

void Player::DEC_Health(double DEC)
{
    if((Health = Health - DEC )<= 0)
    {
        Health = 0;
        Set_State(1);//he's dead jim
    }
}

double Player::H()
{
    return Health;
}

void Player::Set_Mana(int M)
{
    Mana = M;
}

void Player::MAX_Mana(int M)
{
    MaxMana = M;
}

void Player::INC_Mana(int INC)
{
    if((Mana = Mana + INC) > MaxMana)
    {
        Mana = MaxMana;
    }
}

void Player::DEC_Mana(int DEC)
{
    if((Mana = Mana - DEC) < 0)
    {
        Mana = 0;
    }
}

double Player::M()
{
    return Mana;
}

void Player::Set_State(bool S) //0 alive, 1 dead
{
    State = S;
}

bool Player::S()
{
    if(State == 0)
        return 0;
    else
        return 1;
}

void Player::INT_Inventory(int I) //initilize inventory
{

}

void Player::Insert_Inventory(int I)
{

}

void Player::Remove_Inventory(int R)
{

}

void Player::Set_Position(float X,float Y,int Map) //x,y,map#
{
    Xpos = X;
    Ypos = Y;
    Location = Map;
}

void Player::Position(float& X, float& Y, float& Map)
{
    X = Xpos;
    Y = Ypos;
    Map = Location;
}

void Player::move(float X,float Y)
{
    Xpos = Xpos + X;
    Ypos = Ypos + Y;
}
