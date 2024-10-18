#include <iostream>
#include "ListaDwustronna.h"

ListaDwustronna::Element::Element() :Element({}) {};
ListaDwustronna::Element::Element(int _wartosc) :wartosc(_wartosc), poprzedni(nullptr), nastepny(nullptr) {

}

ListaDwustronna::ListaDwustronna() :poczatek(nullptr), koniec(nullptr), ilosc{} {

};
ListaDwustronna::~ListaDwustronna() {
	WyczyscListe();
}
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
void ListaDwustronna::DodajElementNaKoncu(int _wartosc) {
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
void ListaDwustronna::WypiszElementyListy() {

	std::cout << *this;
}
void ListaDwustronna::WypiszElementyListyOdKonca() {
	if (ilosc == 0) {
		std::cout<< "Lista pusta\n";
		return;
	}
	if (poczatek == nullptr) {
		std::cout << "Lista pusta\n";
		return ;
	}
	ListaDwustronna::Element* temp = koniec;
	while (temp->poprzedni != nullptr) {
		std::cout << *temp << " ";
		temp = temp->poprzedni;
	}
	std::cout << *temp << "\n";
}
void ListaDwustronna::UsunElementZPoczatkuListy() {

	if (ilosc == 0) {
		std::cout << "Nie mozna usunac elementu z pustej listy\n";
		return;
	}
	if (poczatek == nullptr) {
		std::cout << "Nie mozna usunac elementu z pustej listy\n";
		return;
	}
	if (poczatek == koniec || ilosc == 1) {
		delete poczatek;
		poczatek = nullptr;
		koniec = nullptr;

	}
	else
	{
		ListaDwustronna::Element* temp = poczatek->nastepny;
		delete poczatek;
		poczatek = temp;
		poczatek->poprzedni = nullptr;
	}
	--ilosc;
}
void ListaDwustronna::UsunElementZKoncaListy() {

	if (ilosc == 0) {
		std::cout << "Nie mozna usunac elementu z pustej listy\n";
		return;
	}
	if (koniec == nullptr) {
		std::cout << "Nie mozna usunac elementu z pustej listy\n";
		return;
	}
	if (poczatek == koniec || ilosc == 1) {
		delete koniec;
		koniec = nullptr;
		poczatek = nullptr;

	}
	else {
		ListaDwustronna::Element* temp = koniec->poprzedni;
		delete koniec;
		koniec = temp;
		koniec->nastepny = nullptr;
	}
	--ilosc;
}
void ListaDwustronna::WyczyscListe() {
	ListaDwustronna::Element* temp = poczatek;
	while (temp != nullptr) {
		ListaDwustronna::Element* holder = temp->nastepny;
		delete temp;
		temp = holder;
	}
	delete temp;
	poczatek = nullptr;
	koniec = nullptr;
	ilosc = 0;
}
std::ostream& operator<<(std::ostream& os, const ListaDwustronna::Element& element) {

	os << element.wartosc;
	return os;
}
std::ostream& operator<<(std::ostream& os, const ListaDwustronna& lista) {
	if (lista.ilosc == 0) {
		os << "Lista pusta\n";
		return os;
	}
	if (lista.poczatek == nullptr) {
		os << "Lista pusta\n";
		return os;
	}
	ListaDwustronna::Element* temp = lista.poczatek;
	while (temp->nastepny != nullptr) {
		os << *temp << " ";
		temp = temp->nastepny;
	}
	os << *temp << "\n";
	return os;
}
//std::ostream& operator<<(std::ostream& os, const ListaDwustronna a);
