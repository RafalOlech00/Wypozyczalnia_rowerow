#pragma once
#include <iostream>
#include "Rower.h"

using namespace std;

class Klient
{
private:
	string imie;
	string nazwisko;
	int numerDowodu;
	Rower* wyporzyczonyRower;

public:
	void wypisz();
	void wyporzycz(Rower*);
	Rower* oddaj();

};


