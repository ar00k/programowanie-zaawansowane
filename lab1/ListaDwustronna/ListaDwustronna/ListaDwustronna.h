#pragma once
class ListaDwustronna
{
	struct Element
	{	
		int wartosc;
		int* nastepny;
		int* poprzedni;
		Element();

	};
	Element* poczatek;
	Element* koniec;
public:
	ListaDwustronna();
	


};

