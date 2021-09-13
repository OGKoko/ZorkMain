#include "Player.h"



Player::Player(int pv) {
	this->hp = pv;

}



string Player::listItems()
{
	string concat = "";

	for (Items c : playerItems)
		concat += to_string(c.getId()) + " " + c.getName() + " " + c.getDescription() + "\n";

	return concat;
}

void Player::addItems(Items it)
{
	this->playerItems.push_back(it);
}

bool Player::dropItems(int n)
{

	for (int x = 0; x < playerItems.size(); x++) {
		if (playerItems[x].getId() == n) {
			playerItems.erase(playerItems.begin() + x);
			return true;
		}
	}
	return false;
}

int Player::updHp(int hp) {
	this->hp += hp;
	return this->hp;
}
int Player::getHp() {
	return this->hp;
}

Items Player::inventoryItem(int itemToFind) {
	for (int i = 0; i < this->playerItems.size(); i++) {
		if (playerItems[i].getId() == itemToFind)
			return playerItems[i];
	}
	return Items("", "", -1);
}