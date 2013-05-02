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
/*	Map Index
	@ : player
	# : pathway
	w : water


*/
//Status Bar Base Display
#include "Definition.h"

char CoverPage[20][41] =
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

char Map [14][26][52] =
{
//map 0
    {
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |  map  0 |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |    B    |         |         |",
        "|         |         |                             ,",
        "|         |         |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+----,----+---------+---------+",
    },

//map 1
    {
        "+---------+---------+----,----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |  map 1  |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        ",                       A                         ,",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+--,------+---------+---------+---------+---------+",
    },

//map 2
    {
        "+---------+---------+----,----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |  map 2  |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        ",         |         |   C     |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
    },

//map3
    {
        "+---------+---------+----,----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |  map 3  |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |   C     |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
    },

//map 4
    {
        "+---------+---------+----,----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |  map 4  |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |   C     |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
    },

//map 5
    {
        "+---------+---------+----,----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |  map 5  |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |   C     |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
    },

//map 6
    {
        "+---------+---------+----,----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |  map 6  |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |   C     |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
    },

//map 7
    {
        "+---------+---------+----,----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |  map 7  |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |   C     |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
    },
//map 8
    {
        "+---------+---------+----,----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |  map 8  |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |   C     |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
    },

//map 9
    {
        "+---------+---------+----,----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |  map 9  |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |   C     |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
    },

//map 10
    {
        "+---------+---------+----,----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |  map 10 |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |   C     |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
    },

//map 11
    {
        "+---------+---------+----,----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |  map 11 |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |   C     |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
    },

//map 12
    {
        "+---------+---------+----,----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |  map 12 |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |   C     |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
    },
//map 13
    {
        "+---------+---------+----,----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |  map 13 |         |         |         |",
        "+---------+---------+---- ----+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |   C     |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "|         |         |         |         |         |",
        "+---------+---------+---------+---------+---------+",
    }
};

