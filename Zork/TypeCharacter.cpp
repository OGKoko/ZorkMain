#include <Windows.h>
#include <cstdlib>
#include <cassert>
#include "TypeCharacter.h"


using namespace std;

void TypeCharacter::operator<<(string s) {

	for (int i = 0; i < s.size(); i++) {
		cout << s.at(i);
		if (s.at(i) != ' ' && s.at(i) != '\n') Beep(10, 5);
		Sleep(this->miliseconds);
	}
}

TypeCharacter::TypeCharacter() {
	this->miliseconds = 200;
}

TypeCharacter::TypeCharacter(int s) {
	this->miliseconds = s;
}