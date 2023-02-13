#include <iostream>
#include "Rower.h"
#include "Klient.h"
#include "Stoisko.h"
#include <array>


int main()
{

	/*Za³ó¿my ¿e pracujemy w ramach projektu poœwiêconego stworzeniu aplikacji do zarz¹dzania wypo¿yczalni¹
		rowerów.Dla realizacji jednego z zadao konieczne jest wykonanie nastêpuj¹cego scenariusza :
	 Stwórz klasy reprezentuj¹ce Rower, Klienta oraz Stoisko wed³ug opisu poni¿ej.
		* Umieœd klasy w osobnych plikach.
		* Stwórz Klienta, 2 Stoiska, Rower oraz tablicê Rowerów
		* Przyporz¹dkuj tablice do Stoiska 1, pojedynczy Rower - do stoiska 2
		* Ustaw pola Klienta, Roweru oraz Stoiska na prywatne
		* Wypo¿ycz Rower przez klienta ze Stoiska 1, po czym oddaj go przy Stoisku 2
		* Stwórz funkcjê wyœwietlaj¹ca informacjê o dostêpnych Rowerach przy podanym Stoisku, odpal j¹ dla obu Stoisk
		Klasa Klient :
	    * Dane
		* WskaŸnik* wypo¿yczonyRower
		* Metody wypisz / uzupe³nij
		* Metody wypo¿yd / oddaj
		* Inne metody niezbêdne do realizacji scenariusza
		Klasa Rower :
	    * Id roweru
		* Metody wypisz / uzupe³nij
		* Inne metody niezbêdne do realizacji scenariusza
		Klasa Stoisko :
		* Wska¿nik* Rowery
		* Metoda poka¿Dostêpne
		* Metody wypisz / uzupe³nij
		* Inne metody niezbêdne do realizacji scenariusza*/


	Rower* rower = new Rower();      // tworze pojedynczy rower 
	Rower* rowery[5];                // tworze tablice rowerow
	for (int i = 0; i < (sizeof(rowery) / sizeof(Rower*)); i++) rowery[i] = new Rower();

	Klient klient1, klient2;
	Stoisko stoisko1 = Stoisko(&rower);  // przypisuje pojedynczy rower do stoisko1
	Stoisko stoisko2 = Stoisko(rowery, sizeof(rowery) / sizeof(Rower*));  // przypisuje tablice rowerow do stoisko2
	klient1.wypisz();

	cout << endl;
	//stoisko2.wypisz();
	stoisko1.pokazDostepny();
	cout << endl;

	stoisko2.pokazDostepny();
	cout << endl;

	klient1.wyporzycz(stoisko1.wyporzycz(0));
	klient2.wyporzycz(stoisko2.wyporzycz(3));
	cout << endl;

	stoisko1.pokazDostepny();
	cout << endl;

	stoisko2.pokazDostepny();
	cout << endl;

	stoisko2.przyjmij(klient1.oddaj());
	stoisko1.przyjmij(klient2.oddaj());
	cout << endl;

	stoisko1.pokazDostepny();
	cout << endl;

	stoisko2.pokazDostepny();
	cout << endl;

}







