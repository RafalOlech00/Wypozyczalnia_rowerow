#include <iostream>
#include "Rower.h"
#include "Klient.h"
#include "Stoisko.h"
#include <array>


int main()
{

	/*Za��my �e pracujemy w ramach projektu po�wi�conego stworzeniu aplikacji do zarz�dzania wypo�yczalni�
		rower�w.Dla realizacji jednego z zadao konieczne jest wykonanie nast�puj�cego scenariusza :
	 Stw�rz klasy reprezentuj�ce Rower, Klienta oraz Stoisko wed�ug opisu poni�ej.
		* Umie�d klasy w osobnych plikach.
		* Stw�rz Klienta, 2 Stoiska, Rower oraz tablic� Rower�w
		* Przyporz�dkuj tablice do Stoiska 1, pojedynczy Rower - do stoiska 2
		* Ustaw pola Klienta, Roweru oraz Stoiska na prywatne
		* Wypo�ycz Rower przez klienta ze Stoiska 1, po czym oddaj go przy Stoisku 2
		* Stw�rz funkcj� wy�wietlaj�ca informacj� o dost�pnych Rowerach przy podanym Stoisku, odpal j� dla obu Stoisk
		Klasa Klient :
	    * Dane
		* Wska�nik* wypo�yczonyRower
		* Metody wypisz / uzupe�nij
		* Metody wypo�yd / oddaj
		* Inne metody niezb�dne do realizacji scenariusza
		Klasa Rower :
	    * Id roweru
		* Metody wypisz / uzupe�nij
		* Inne metody niezb�dne do realizacji scenariusza
		Klasa Stoisko :
		* Wska�nik* Rowery
		* Metoda poka�Dost�pne
		* Metody wypisz / uzupe�nij
		* Inne metody niezb�dne do realizacji scenariusza*/


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







