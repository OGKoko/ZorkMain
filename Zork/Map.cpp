#include "Map.h"

Map::Map() {
	this->activeRoom = NULL;
}

void Map::setActiveRoom(Room* a) {
	this->activeRoom = a;
}

vector<Room *>Map::getRooms() {
	return rooms;
}

void Map::addRoom(Room* room)
{
	rooms.push_back(room);
}

string Map::getNameRoom()
{
	return activeRoom->getName() + "\n " + activeRoom->getDescription() + "\n";
}



Room* Map::goNorth() {
	if (activeRoom->getNorth() != NULL) {
		this->activeRoom = activeRoom->getNorth();
		this->activeRoom->setLastMove("You are located in: " + this->activeRoom->getName() + "\n" + this->activeRoom->getDescription());
	}
	else {
		this->activeRoom->setLastMove("Its not possible to go North, you still in: " + this->activeRoom->getName());
	}
	return this->activeRoom;
}



Room* Map::goSouth() {
	if (activeRoom->getSouth() != NULL) {
		this->activeRoom = activeRoom->getSouth();
		this->activeRoom->setLastMove("You are located in: " + this->activeRoom->getName() + "\n" + this->activeRoom->getDescription());
	}
	else {
		this->activeRoom->setLastMove("Its not possible to go South, you still in: " + this->activeRoom->getName());
	}
	return this->activeRoom;
}



Room* Map::goEast() {
	if (activeRoom->getEast() != NULL) {
		this->activeRoom = activeRoom->getEast();
		this->activeRoom->setLastMove("You are located in: " + this->activeRoom->getName() + "\n" + this->activeRoom->getDescription());
	}
	else {
		this->activeRoom->setLastMove("Its not possible to go East, you still in: " + this->activeRoom->getName());
	}
	return this->activeRoom;
}



Room* Map::goWest() {
	if (activeRoom->getWest() != NULL) {
		this->activeRoom = activeRoom->getWest();
		this->activeRoom->setLastMove("You are located in: " + this->activeRoom->getName() + "\n" + this->activeRoom->getDescription());
	}
	else {
		this->activeRoom->setLastMove("Its not possible to go West, you still in: " + this->activeRoom->getName());
	}
	return this->activeRoom;
}

Room* Map::getActiveRoom() {
	return this->activeRoom;
}

/*string Map::getResult() {
	return this->movementResult;
}*/
