#pragma once
#include <string>
#include "Items.h"
#include <vector>
using namespace std;

class Room
{
	string name, description, lastMove;
	bool isGG;
	Room* north;
	Room* south;
	Room* east;
	Room* west;
	vector<ItemsContenedor> itemsOnRoom;

public:

	Room(string, string, bool);

	void setNorth(Room*);
	void setSouth(Room*);
	void setWest(Room*);
	void setEast(Room*);

	Room* getNorth();
	Room* getSouth();
	Room* getEast();
	Room* getWest();

	string getName();
	string getDescription();
	bool getIsGG();
	void setLastMove(string);
	string getLastMove();
	string listItems();
	ItemsContenedor desiredItem(int);
	void addItem(ItemsContenedor);
};

