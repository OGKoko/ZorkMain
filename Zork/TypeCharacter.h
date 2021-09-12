#pragma once
#include<iostream>

using namespace std;

class TypeCharacter {
	int miliseconds;

public:
	TypeCharacter();
	TypeCharacter(int);
	void operator<<(string);
};
