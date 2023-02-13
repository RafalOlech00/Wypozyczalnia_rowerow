#include "Stoisko.h"

Rower** rowery;  // tworz� wska�nik na wska�nik 
int size;        // tworz� sobie zmienn� kt�ra b�dzie mnie informowa� o ilo�ci samochod�w 

Stoisko::Stoisko(Rower** rower)  // tworz� konstruktor, kt�ry przypisuje pojedy�czy rower do stoiska 
{
	this->rowery = rower;
	this->size = 1;              // ustawiamy size na 1 poniewaz chodzi nam o jeden rower 
}

Stoisko::Stoisko(Rower** rowery, int size)   // tworz� konstruktor, kt�ry przypisuje tablice rower�w do stoiska 
{
	this->rowery = rowery;
	this->size = size;
}

void Stoisko::wypisz()               // metoda, kt�ra wypisuje nam ile na pocz�tku by�o rower�w na stoisku 
{
	cout << "Na stanie mam " << size << " rowerow" << endl;
}

void Stoisko::pokazDostepny()       // metoda, kt�re pokazuje nam dost�pne aktualnie rowery czyli ich id 
{
	Rower** rower = this->rowery;   // przypisuje wska�nik do wska�nika �eby rusza� wska�nikiem lokalnym a nie globalnym 
	                                // �eby globalny dalej pokazywa� na pierwszy element 
	for (int i = 0; i < size; i++)  // size okre�la ile masymalnie mog�o si� tam znajdowa� rower�w 
		                            // wi�c nie mo�emy przekroczy� tej liczby w poszukiwanii dost�pnych
	{
		if (rower[i] != NULL)
		{
			cout << "Rower o id " << rower[i]->Wypisz() << endl;
		}
	}
}

Rower* Stoisko::wyporzycz(int n)     // metoda, kt�ra s�u�y do wypo�yczania rower�w 
{
	if (n >= size || n < 0) return NULL;   // je�eli kto� poda �e chce usun�� rower spoza tablicy zwr�� NULL, takie zabezpieczenie 

	Rower* rower = rowery[n];        // iterujemy po tablicy wska�nik�w
	if (rower == NULL) return NULL; // tu jest przypadek kiedy rower ju� jest wypo�yczony

	rowery[n] = NULL;          // je�eli wypo�yczymy rower ustawiamy go na NULL
	return rower;
}

void Stoisko::przyjmij(Rower* rower)   // stoisko przyjmuje rower oddawany przez Klienta
{
	for (int i = 0; i < size; i++)
	{
		if (rowery[i] == NULL) rowery[i] = rower;   // je�eli miejsce rower[i] wcze�niej by� NULLEM,
		                                            // czyli nie by�o tam roweru to teraz wkaznik pokazuje na przyjety i oddany rower
	}
}