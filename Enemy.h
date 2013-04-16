/* ECE 264 Group Prject: Enemy.h
 *
 * This software is licensed under the terms of the MIT-License
 * See COPYING for further information.
 * ---
 * Copyright (C) 2013 Daniel Noyes <Reiuiji@gmail.com>
 */

class Enemy
{
public:
    Enemy(bool);           //implement new Enemy
    //Enemy(ifstream);   //import Enemy data

    void Set_N(string);
    string N();
    void Set_Name(string);

    void Set_LVL(int);

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
    string Name;
    int Level;
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
