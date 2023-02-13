#pragma once
#include <iostream>
#include "Rower.h"

class Rower
{
private:
	static int generateID;
	int id;

public:
	Rower();
	int Wypisz();
};
