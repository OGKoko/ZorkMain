#include "MapManager.h"

using namespace std;

MapManager::MapManager(vector<Room*> r)
{
	int vectorSize = r.size();
	if (vectorSize < 5) {
		exit(-1);
	}

	/* room 0 (Out Garden)
	   room 1 (North Garden)
	   room 2 (Main Garden)
	   room 3 (Backyard)
	   room 4 (House)*/

	r[0]->setNorth(r[1]);
	r[0]->setSouth(r[3]);


	r[1]->setSouth(r[2]);

	r[2]->setSouth(r[3]);
	r[2]->setEast(r[4]);

	r[3]->setWest(r[0]);
	r[3]->setNorth(r[2]);

	r[0]->addItem(ItemsContenedor("Bandage ", "[ Heal yourself with it ]", BANDAGE));
	r[0]->addItem(ItemsContenedor("Bunch of leaves ", "[ Just a bunch of leaves ]", LEAVES));
	r[0]->addItem(ItemsContenedor("Nails ", "[ A small box with rusty nails on it ]", NAIL));

	r[1]->addItem(ItemsContenedor("Nails ", "[A small box with rusty nails on it ]", NAIL));
	r[1]->addItem(ItemsContenedor("Bandage ", "[ Heal yourself with it ]", BANDAGE));

	r[2]->addItem(ItemsContenedor("Nails ", "[ A small box with rusty nails on it ]", NAIL));
	r[2]->addItem(ItemsContenedor("Key ", "[ Something could be opened with it ]", VAULT_KEY));
	
	r[3]->addItem(ItemsContenedor("Wood Plank ", "[ Could be usefull to catch fire, unlucky i don't have a lighter ]", LEAVES));
	r[3]->addItem(ItemsContenedor("Vault", "[ Will this vault contain a treasure? ]", VAULT, Items("Magestic Key", "[ Key from a big fancy door ]", DOOR_KEY)));

	rooms = r;
}



Room * MapManager::getFirstRoom()
{
	return rooms[0];
}
