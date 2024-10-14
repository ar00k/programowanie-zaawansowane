#include <iostream>
#include "ListaDwustronna.h"

ListaDwustronna::Element::Element() :Element({}) {};
ListaDwustronna::Element::Element(int _wartosc) :wartosc(_wartosc), poprzedni(nullptr), nastepny(nullptr) {

}

ListaDwustronna::ListaDwustronna() :poczatek(nullptr), koniec(nullptr), ilosc{} {

};
void ListaDwustronna::DodajElementNaPoczatku(int _wartosc) {

	Element* temp = new Element(_wartosc);
	if (poczatek == nullptr) {
		poczatek = temp;
		koniec = temp;
	}
	else {
		Element* staryPoczatek = poczatek;
		poczatek = temp;
		poczatek->nastepny = staryPoczatek;
		staryPoczatek->poprzedni = poczatek;
	}
	++ilosc;
}
void ListaDwustronna::DodajElementNaPoczatku(int _wartosc) {
	Element* temp = new Element(_wartosc);
	if (koniec == nullptr) {
		poczatek = temp;
		koniec = temp;
	}
	else {
		Element* staryKoniec = koniec;
		koniec = temp;
		koniec->poprzedni = staryKoniec;
		staryKoniec->nastepny = koniec;
	}
	++ilosc;
}