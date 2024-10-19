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
void ListaDwustronna::DodajElementNaIndeks(int indeks, int wartosc) {
	if (indeks < 0 || indeks > ilosc) {
		std::cout << "Nieprawidłowy indeks.\n";
		return;
	}
	if (indeks == 0) {
		DodajElementNaPoczatku(wartosc);
		return;
	}
	if (indeks == ilosc) {
		DodajElementNaKoncu(wartosc);
		return;
	}

	Element* nowyElement = new Element(wartosc);
	Element* temp = poczatek;

	for (int i = 0; i < indeks - 1; ++i) {
		temp = temp->nastepny;
	}

	nowyElement->nastepny = temp->nastepny;
	nowyElement->poprzedni = temp;
	if (temp->nastepny != nullptr) {
		temp->nastepny->poprzedni = nowyElement;
	}
	temp->nastepny = nowyElement;

	++ilosc;
}

void ListaDwustronna::UsunElementNaIndeks(int indeks) {
	if (indeks < 0 || indeks >= ilosc) {
		std::cout << "Nieprawidłowy indeks.\n";
		return;
	}
	if (indeks == 0) {
		UsunElementZPoczatkuListy();
		return;
	}
	if (indeks == ilosc - 1) {
		UsunElementZKoncaListy();
		return;
	}

	Element* temp = poczatek;
	for (int i = 0; i < indeks; ++i) {
		temp = temp->nastepny;
	}

	temp->poprzedni->nastepny = temp->nastepny;
	temp->nastepny->poprzedni = temp->poprzedni;

	delete temp;
	--ilosc;
}

void ListaDwustronna::WyswietlNastepnyElement(int indeks) {
	if (indeks < 0 || indeks >= ilosc - 1) {
		std::cout << "Nieprawidlowy indeks lub brak kolejnego elementu.\n";
		return;
	}

	Element* temp = poczatek;
	for (int i = 0; i <= indeks; ++i) {
		temp = temp->nastepny;
	}

	std::cout << "Nastepny element: " << *temp << "\n";
}

void ListaDwustronna::WyswietlPoprzedniElement(int indeks) {
	if (indeks <= 0 || indeks >= ilosc) {
		std::cout << "Nieprawidlowy indeks lub brak poprzedniego elementu.\n";
		return;
	}

	Element* temp = poczatek;
	for (int i = 0; i < indeks; ++i) {
		temp = temp->nastepny;
	}

	std::cout << "Poprzedni element: " << *temp->poprzedni << "\n";
}
//std::ostream& operator<<(std::ostream& os, const ListaDwustronna a);
