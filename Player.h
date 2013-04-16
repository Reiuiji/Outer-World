/* ECE 264 Group Prject: Player.h
 *
 * This software is licensed under the terms of the MIT-License
 * See COPYING for further information.
 * ---
 * Copyright (C) 2013 Daniel Noyes <Reiuiji@gmail.com>
 */

class Player
{
public:
    Player(bool);           //implement new player
    //Player(ifstream);   //import player data
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
