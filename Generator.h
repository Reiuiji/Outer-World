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
typedef struct room
{
    int             Room_Type;  //0=default;1=start; 2=end
    void*           ITEM_ptr;
    void*           MOB_ptr;
    void*           Event_ptr;
    struct room*    North;
    struct room*    East;
    struct room*    South;
    struct room*    West ;
    struct room*    NextFloor;
    struct room*    PrevFloor;
} ROOM;

typedef struct Dungeon
{
    char            Dungeon_Name;
    int             FLOOR_NUM;
    void*           MOB_RATE;
    void*           ITEM_RATE;
    struct room*    Entrance;
    struct room*    BOSS;
} DUNGEON;

class Generator
{
public:
    Dungeon DungeonGen();
    void MobGen();
    void ItemGen();
};
