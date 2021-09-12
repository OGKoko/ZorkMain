#include "Room.h"
using namespace std;
Room::Room(string name, string description, bool isGG)
{
	this->name = name;
	this->description = description;
	this->isGG = isGG;
	this->east = this->north = this->south = this->west = NULL;
}

string Room::getName()
{
	return this->name;
}
string Room::getDescription()
{
	return this->description;
}

void Room::setNorth(Room* n)
{
	this->north = n;
}
void Room::setSouth(Room* s)
{
	this->south = s;
}
void Room::setEast(Room* e)
{
	this->east = e;
}
void Room::setWest(Room* w)
{
	this->west = w;
}


Room* Room::getNorth()
{
	return this->north;
}
Room* Room::getSouth()
{
	return this->south;
}
Room * Room::getEast()
{
	return this->east;
}
Room* Room::getWest() {
	return this->west;
}
bool Room::getIsGG() {
	return this->isGG;
}

string Room::getLastMove() {
	return this->lastMove;
}

void Room::setLastMove(string msg) {
	this->lastMove = msg;
}

void Room::addItem(ItemsContenedor item) {
	this->itemsOnRoom.push_back(item);
}

string Room::listItems() {
	string concat = "";

	for (ItemsContenedor c : itemsOnRoom)
		concat += to_string(c.getId()) + " " + c.getName() + " " + c.getDescription() + "\n";

	return concat;
}

ItemsContenedor Room::desiredItem(int n)
{

	for (int x = 0; x < itemsOnRoom.size(); x++) {
		if (itemsOnRoom[x].getId() == n) {
			ItemsContenedor itemAux(itemsOnRoom[x].getName(), itemsOnRoom[x].getDescription(), itemsOnRoom[x].getId(), itemsOnRoom[x].getContedido());
			if (itemsOnRoom[x].getId() != VAULT)
				itemsOnRoom.erase(itemsOnRoom.begin() + x);
			return itemAux;
		}
	}
	return ItemsContenedor("", "", -1);
}
