#include <iostream>
#include "ListaDwustronna.h"
using namespace std;

int main() {

	ListaDwustronna lista;
	lista.DodajElementNaPoczatku(1);
	lista.DodajElementNaKoncu(2);
	lista.DodajElementNaKoncu(3);
	lista.DodajElementNaKoncu(4);
	lista.DodajElementNaKoncu(5);
	lista.DodajElementNaKoncu(6);
	lista.WypiszElementyListy();
	lista.WyczyscListe();
	lista.WypiszElementyListy();
	lista.DodajElementNaPoczatku(1);
	lista.DodajElementNaKoncu(2);
	lista.DodajElementNaKoncu(3);
	lista.DodajElementNaKoncu(4);
	lista.DodajElementNaKoncu(5);
	lista.DodajElementNaKoncu(6);
	lista.WypiszElementyListy();
	lista.UsunElementNaIndeks(3);
	lista.WypiszElementyListy();
	lista.WyswietlNastepnyElement(3);

}