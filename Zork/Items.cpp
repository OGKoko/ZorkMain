#include "Items.h"


Items::Items() {
}

Items::Items(string n, string d, int id) {
	this->name = n;
	this->description = d;
	this->type = id;
}

string Items::getName() {
	return this->name;
}
string Items::getDescription() {
	return this->description;
}
int Items::getId() {
	return this->type;
}


//implementación ItemsContenedor
ItemsContenedor::ItemsContenedor() {
}

ItemsContenedor::ItemsContenedor(string n, string d, int id) : Items(n, d, id) {
	//this->obj = Item;
}
ItemsContenedor::ItemsContenedor(string n, string d, int id, Items objT) : Items(n, d, id) {
	this->obj = objT;
}
Items ItemsContenedor::getObject() {
	return Items(this->name, this->description, this->type);
}
void ItemsContenedor::addObject(Items objT) {
	this->obj = objT;
}
int ItemsContenedor::getId() {
	return this->type;
}
string ItemsContenedor::getName() {
	return this->name;
}
string ItemsContenedor::getDescription() {
	return this->description;
}

Items ItemsContenedor::getContedido() {
	return this->obj;
}