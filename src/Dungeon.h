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

class Dungeon
{
public:
    void StartDungeon(Player plyone,int DungeonLVL);
    void DisplayRoom(const char Map[DungeonRoomNum][DungeonMapY][DungeonMapX],const int DungeonMap[DungeonMapLVL][DungeonMapLVL],int PlayerY,int PlayerX, int DungeonY, int DungeonX);
    //DungeonGen(int FloorCount, int FloorSize, int LvlLow, int LvlHigh);
    bool MoveCheck(int &x,int &y,int xcen, int ycen, int xmove, int ymove, const char Map[][DungeonMapX]);
    void MobGen();
    void ItemGen();
    void Display(int Sx, int Sy, int x, int y,int xcen, int ycen,const char Map[][DungeonMapX]);

private:
    void RoomCreate(int X, int Y, int *Floor);
};

const char CoverPage[20][41] =
{
    {"+------------------+------------------ +"},
    {"|                                      |"},
    {"|                                      |"},
    {"|                                      |"},
    {"|                                      |"},
    {"|                                      |"},
    {"|  |                                   |"},
    {"|  |                                   |"},
    {"|  |                                   |"},
    {"|                                      |"},
    {"|                                      |"},
    {"|                                      |"},
    {"|                                      |"},
    {"|                                      |"},
    {"|                                      |"},
    {"|                                      |"},
    {"|                                      |"},
    {"|                                      |"},
    {"|                                      |"},
    {"+------------------+------------------ +"},
};

const int DungeonMap1[DungeonMapLVL][DungeonMapLVL] =
{
    {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5},
    {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
    {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
    {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
    {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
    {5,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,5},
    {5,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,5},
    {5,0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,5},
    {5,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,5},
    {5,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,5},//10
    {5,0,0,0,0,1,1,1,1,2,1,1,1,1,1,1,0,0,0,5},//10
    {5,0,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,0,5},
    {5,0,0,1,1,1,0,0,1,0,0,1,1,0,0,1,0,0,0,5},
    {5,0,0,0,0,0,0,0,1,1,1,0,1,1,0,1,0,0,0,5},
    {5,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,5},
    {5,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0,0,5},
    {5,0,0,0,0,0,0,1,0,0,0,0,0,0,0,3,0,0,0,5},
    {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
    {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
    {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5},

};

const char DungeonRoom [DungeonRoomNum][DungeonMapY][DungeonMapX] =
{
// Regualar Room [1]
    {
        "+------------------+",
        "|1                 |",
        "|                  |",
        "|                  |",
        "|        ||        |",
        "|        ||        |",
        "|                  |",
        "|                  |",
        "|                  |",
        "+------------------+"
    },

// Start Room [2]
    {
        "+------------------+",
        "|2                 |",
        "|    __      __    |",
        "|   /  \\    /  \\   |",
        "|   |##|    |##|   |",
        "|   |##| @  |##|   |",
        "|   \\__/    \\__/   |",
        "|                  |",
        "|                  |",
        "+------------------+"
    },

// End Room [3]
    {
        "+------------------+",
        "|3                 |",
        "|                  |",
        "|                  |",
        "|        ||        |",
        "|        ||        |",
        "|                  |",
        "|                  |",
        "|                  |",
        "+------------------+"
    },
};
