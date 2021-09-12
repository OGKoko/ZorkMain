#pragma once
#include <vector>
#include "Room.h"

using namespace std;

class MapManager
{
	vector<Room*> rooms;
public:
	MapManager(vector<Room*>);
	Room* getFirstRoom();

};

