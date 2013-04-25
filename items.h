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

class items
{
public:
	items();
	items(char name, char desc, int atk, int magatk, int def, int magdef, int itemtype, int usable, int health, int mana, int smoke, int repel, int key);
	char getitem();
	int getstats();
	char getdesc();

private:
	char name; // weapon name.
	char desc; // weapon description.

	int atk; // the attack bonus or decrease of the item.
	int magatk; // the magic attack bonus or decrease of the item.
	int def; // the defense bonus or decrease of the item.
	int magdef; // the magic defense bonus or decrease of the item.
	int itemtype; // defines the type of item.

    int usable; // defines whether or not an item is usable
	int health; // defines the amount of health the item restores
	int mana; // defines the amount of mana the item restores
	int smoke; // defines if an item is a smoke bomb
	int repel; // defines if an item is a repel
	int key; // defines if an item is a key item
}
