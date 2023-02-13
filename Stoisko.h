#pragma once
#include "Rower.h"
#include <iostream>

using namespace std;

class Stoisko
{
private:
	Rower** rowery;
	int size;

public:
	Stoisko(Rower**);
	Stoisko(Rower**, int);
	void wypisz();
	void pokazDostepny();
	Rower* wyporzycz(int);
	void przyjmij(Rower*);
};



