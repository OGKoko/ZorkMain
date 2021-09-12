#pragma once
#include <string>

using namespace std;

enum  typeItem { BANDAGE, NAIL, VAULT_KEY, DOOR_KEY, LEAVES, VAULT };

class Items
{
protected:

	string name;
	string description;
	int type;

public:
	Items();
	Items(string, string, int);
	string getName();
	string getDescription();
	int getId();
};



class ItemsContenedor : Items {
	Items obj;
public:
	ItemsContenedor();
	ItemsContenedor(string n, string d, int id);
	ItemsContenedor(string, string, int, Items);
	Items getObject();
	void addObject(Items objT);
	int getId();
	string getName();
	string getDescription();
	Items getContedido();
};