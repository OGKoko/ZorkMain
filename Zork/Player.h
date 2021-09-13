#pragma once
#include"Room.h"
class Player
{
	int hp;
	vector<Items> playerItems;

public:

	Player(int);
	string listItems();
	void addItems(Items);
	bool dropItems(int);
	int updHp(int);
	int getHp();

	Items inventoryItem(int itemToFind);

};

