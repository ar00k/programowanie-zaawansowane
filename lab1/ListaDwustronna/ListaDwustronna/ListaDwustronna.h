#pragma once
class ListaDwustronna
{
	struct Element
	{	
		int wartosc;
		Element* nastepny;
		Element* poprzedni;
		Element();
		Element(int _wartosc);
	};
	Element* poczatek;
	Element* koniec;
	int ilosc;
public:
	ListaDwustronna();
	void DodajElementNaPoczatku(int _wartosc);
	void WypiszElementyListy();
	void DodajElementNaKoncu(int _wartosc);
};

