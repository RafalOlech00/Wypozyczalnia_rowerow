#include "Rower.h"

using namespace std;

int Rower::generateID = 0;
int id;

int Rower::Wypisz()
{
	return id;
}
Rower::Rower()   // konstruktor domy�lny
{
	id = generateID; 
	generateID++;
}

