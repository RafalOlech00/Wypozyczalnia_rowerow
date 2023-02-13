#include "Stoisko.h"

Rower** rowery;  // tworzê wskaŸnik na wskaŸnik 
int size;        // tworzê sobie zmienn¹ która bêdzie mnie informowaæ o iloœci samochodów 

Stoisko::Stoisko(Rower** rower)  // tworzê konstruktor, który przypisuje pojedyñczy rower do stoiska 
{
	this->rowery = rower;
	this->size = 1;              // ustawiamy size na 1 poniewaz chodzi nam o jeden rower 
}

Stoisko::Stoisko(Rower** rowery, int size)   // tworzê konstruktor, który przypisuje tablice rowerów do stoiska 
{
	this->rowery = rowery;
	this->size = size;
}

void Stoisko::wypisz()               // metoda, która wypisuje nam ile na pocz¹tku by³o rowerów na stoisku 
{
	cout << "Na stanie mam " << size << " rowerow" << endl;
}

void Stoisko::pokazDostepny()       // metoda, które pokazuje nam dostêpne aktualnie rowery czyli ich id 
{
	Rower** rower = this->rowery;   // przypisuje wskaŸnik do wskaŸnika ¿eby ruszaæ wskaŸnikiem lokalnym a nie globalnym 
	                                // ¿eby globalny dalej pokazywa³ na pierwszy element 
	for (int i = 0; i < size; i++)  // size okreœla ile masymalnie mog³o siê tam znajdowaæ rowerów 
		                            // wiêc nie mo¿emy przekroczyæ tej liczby w poszukiwanii dostêpnych
	{
		if (rower[i] != NULL)
		{
			cout << "Rower o id " << rower[i]->Wypisz() << endl;
		}
	}
}

Rower* Stoisko::wyporzycz(int n)     // metoda, która s³u¿y do wypo¿yczania rowerów 
{
	if (n >= size || n < 0) return NULL;   // je¿eli ktoœ poda ¿e chce usun¹æ rower spoza tablicy zwróæ NULL, takie zabezpieczenie 

	Rower* rower = rowery[n];        // iterujemy po tablicy wskaŸników
	if (rower == NULL) return NULL; // tu jest przypadek kiedy rower ju¿ jest wypo¿yczony

	rowery[n] = NULL;          // je¿eli wypo¿yczymy rower ustawiamy go na NULL
	return rower;
}

void Stoisko::przyjmij(Rower* rower)   // stoisko przyjmuje rower oddawany przez Klienta
{
	for (int i = 0; i < size; i++)
	{
		if (rowery[i] == NULL) rowery[i] = rower;   // je¿eli miejsce rower[i] wczeœniej by³ NULLEM,
		                                            // czyli nie by³o tam roweru to teraz wkaznik pokazuje na przyjety i oddany rower
	}
}