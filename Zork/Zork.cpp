#include <iostream>
#include "Room.h"
#include "TypeCharacter.h"
#include "Map.h"
#include "MapManager.h"
#include "Player.h"


using namespace std;

int main()
{
	string space = "--------------------------------------------------------------------\n";
	string welcomeMsg = "Hi, Welcome to Zork! \nRemember, you can always type <h> or <Help> to see the commands available \nHave fun! ^^ \n";
	TypeCharacter type(0.5);
	Player p(3);
	char pInput;
	

	type << space;
	type << welcomeMsg;
	type << space;

	Map map;
	map.addRoom(new Room("\nOutside Garden \n", "You're on a garden, you can observe there's a fence, and a big white house in the distance, ahh it looks warm \nWhat you want to do? \n", false));
	map.addRoom(new Room("\nNorth Garden \n", "You're surrounded by trees and leafy shrubs, you see a beautifull fountain and the white house past it, how nice would be to sleep in it tonight \nWhat you want to do? \n", false));
	map.addRoom(new Room("\nMain Garden \n", "Looks like that's the entrance to the house but it's closed, you see the fountain next to you, unfortunately looks like it's out of service... \nWhat you want to do? \n", false));
	map.addRoom(new Room("\nBackyard \n", "Looks like a creepy and neglected backyard, nothing usefull should be found here...\nWhat you want to do? \n", false));
	map.addRoom(new Room("\nHouse \n", "Finally in!!!, time to rest so you can go back home tomorrow. GG \n", true));

	MapManager mm = MapManager(map.getRooms());
	map.setActiveRoom(mm.getFirstRoom());

	type << map.getNameRoom();
	
	Items itemsAux;

	while (!map.getActiveRoom()->getIsGG()) {
		cin >> pInput;
		pInput = tolower(pInput);
		switch (pInput) {
		case 'n':
			type << map.goNorth()->getLastMove();
			break;

		case 's':
			type << map.goSouth()->getLastMove();
			break;

		case 'w':
			type << map.goWest()->getLastMove();
			break;

		case 'e':
			type << map.goEast()->getLastMove();
			break;

		case 'l':
			if (map.getActiveRoom()->listItems().size() != 0) {

				type << "\nThose items can be found here, press <G> or type  <Get> to pick them: \n";
				type << map.getActiveRoom()->listItems();

			}
			else {
				type << "\nI can't see any items on this place\n";
			}
			break;

		case 'g':
			type << "\nSelect the number of the item desired: \n";
			int itemPick;
			cin >> itemPick;
			itemsAux = map.getActiveRoom()->desiredItem(itemPick).getObject();
			if (itemsAux.getId() != -1) {
				if (itemsAux.getId() == NAIL) {

					if (p.updHp(-1) < 1) {
						type << "YOU ARE DEAD \nGAME OVER";
						exit(0);
					}
					else {
						type << "OUCH!! \nYou got hurted, you got: " + to_string(p.getHp()) + " health points left \n";
					}

				}
				else if (itemsAux.getId() == BANDAGE && p.getHp() <= 2) {
					p.updHp(1);
					type << "aaah feels good, you got: " + to_string(p.getHp()) + "  health points left \n";
				}
				else if (itemsAux.getId() == VAULT && p.inventoryItem(VAULT_KEY).getId() != -1) {
					ItemsContenedor i = map.getActiveRoom()->desiredItem(VAULT);
					p.addItems(i.getContedido());
					p.dropItems(VAULT_KEY);
					type << "Magestic Key added to the inventory\n";
				}
				else {
				
					p.addItems(itemsAux);
					type << "Item has been added to the inventory\n";
				}
			}
			else {
				type << "Item not found \n";
			}
			break;

		case 'i':
			type << "\nThats your current inventory:\n ";
			if (p.listItems().size() < 1)
				type << "\n You dont have any item yet\n";
			type << p.listItems();
			break;

		case 'd':
			int itemDrop;
			type << "\nSelect the number of the item you want to drop: \nQuick tip, Save your Bandages, if you drop them hurted, it will heal you\n";
			type << p.listItems();
			cin >> itemDrop;
			if (itemDrop == typeItem(BANDAGE) && p.getHp() <= 2) {
				p.updHp(1);
				type << "\nYou  just got healed, " + to_string(p.getHp()) + " hp left \n";
				p.dropItems(itemDrop);
			}
			else if (p.dropItems(itemDrop))
				type << "Item has been dropped\n";
			else
				type << "404 item not found :(\n";
			break;

		case 'h':
			type << "type below what action you want to perform: \n";
			type << "<N> to go North			<L> to look for items \n";
			type << "<S> to go South			<G> to take the items \n";
			type << "<W> to go West 			<I> to list the Inventory \n";
			type << "<E> to go East 			<D> to Drop any item from the Inventory \n";
			break;


		default:
			type << "I'm sorry, wrong input, \nYou must be confused... \nPress <H> or type <Help> if you don't remember how to play\n";
		}
	}
}

