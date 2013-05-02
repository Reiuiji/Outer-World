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
    void DisplayRoom(char Map[DungeonRoomNum][DungeonMapY][DungeonMapX], int RNum);
    //DungeonGen(int FloorCount, int FloorSize, int LvlLow, int LvlHigh);
    void MobGen();
    void ItemGen();

private:
    void RoomCreate(int X, int Y, int *Floor);
};
