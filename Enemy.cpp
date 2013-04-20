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
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

//#include "items.h"
#include "Enemy.h"
Enemy::Enemy(bool S)
{
    Enemy::Set_Name("meeny");
    Enemy::Set_LVL(1);
    Enemy::MAX_Health(5);
    Enemy::Set_Health(5);
    Enemy::MAX_Mana(5);
    Enemy::Set_Mana(5);
    Enemy::Set_State(S);
    Enemy::Set_Position(0,0,0);
}
//Enemy::Enemy(*Data_File)
//{
//    //implement a load feature for Enemy
//}
//
//void Enemy::SaveEnemy(*Data_File)
//{
//    //impement a save feature
//}

void Enemy::Set_N(string N)
{
    Name =  N;
}

string Enemy::N()
{
    return Name;
}

void Enemy::Set_Name(string Name)
{
    Enemy::Set_N(Name);
}

void Enemy::Set_LVL(int LVL)
{
    Level = LVL;
}

void Enemy::MAX_Health(double H)
{
    MaxHealth = H;
}

void Enemy::Set_Health(double H)
{
    Health = H;
}

void Enemy::INC_Health(double INC)
{
    if((Health = Health + INC) > MaxHealth)
    {
        Health = MaxHealth;
    }
}

void Enemy::DEC_Health(double DEC)
{
    if((Health = Health - DEC )<= 0)
    {
        Health = 0;
        Set_State(1);//he's dead jim
    }
}

double Enemy::H()
{
    return Health;
}

void Enemy::Set_Mana(int M)
{
    Mana = M;
}

void Enemy::MAX_Mana(int M)
{
    MaxMana = M;
}

void Enemy::INC_Mana(int INC)
{
    if((Mana = Mana + INC) > MaxMana)
    {
        Mana = MaxMana;
    }
}

void Enemy::DEC_Mana(int DEC)
{
    if((Mana = Mana - DEC) < 0)
    {
        Mana = 0;
    }
}

double Enemy::M()
{
    return Mana;
}

void Enemy::Set_State(bool S) //0 alive, 1 dead
{
    State = S;
}

bool Enemy::S()
{
    if(State == 0)
        return 0;
    else
        return 1;
}

void Enemy::INT_Inventory(int I) //initilize inventory
{

}

void Enemy::Insert_Inventory(int I)
{

}

void Enemy::Remove_Inventory(int R)
{

}

void Enemy::Set_Position(float X,float Y,int Map) //x,y,map#
{
    Xpos = X;
    Ypos = Y;
    Location = Map;
}

void Enemy::Position(float& X, float& Y, float& Map)
{
    X = Xpos;
    Y = Ypos;
    Map = Location;
}

void Enemy::move(float X,float Y)
{
    Xpos = Xpos + X;
    Ypos = Ypos + Y;
}
