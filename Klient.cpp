#include "Klient.h"

string imie;
string nazwisko;
int numerDowodu;
Rower* wyporzyczonyRower;

void Klient::wypisz()
{
	cout << "Klient: " << endl
		<< "Imie : " << imie << endl
		<< "Nazwisko: " << nazwisko << endl
		<< "Numer dowodu: " << numerDowodu << endl;
	if (wyporzyczonyRower != NULL)        // wypisuje id roweru, który aktualnie wypo¿ycza Klient                
		cout << "ID roweru: " << wyporzyczonyRower->Wypisz();
	else
		cout << "Kient nie wyporzyczyl zadnego roweru." << endl;
}

void Klient::wyporzycz(Rower* rower)
{

	if (wyporzyczonyRower == NULL)  // Klient mo¿e mieæ wyporzyczony tylko jeden rower na raz 
	{
		wyporzyczonyRower = rower;
	}
}

Rower* Klient::oddaj()    // Klient oddaje wypozyczony rower
{
	Rower* rower = wyporzyczonyRower;   // wskaznik rower pokazuje na wypozyczonyRower
	wyporzyczonyRower = NULL;           // wypozyczonyRower nie wskazuje teraz na zaden rower wiec przypisujemy mu NULLA
	return rower;                       // zwracamy rower, który wpozyczalismy
}