#include <iostream>
#include "ListaDwustronna.h"
using namespace std;

int main() {

	ListaDwustronna lista;
	lista.DodajElementNaPoczatku(1);
	lista.DodajElementNaPoczatku(2);
	lista.DodajElementNaPoczatku(3);
	lista.DodajElementNaKoncu(10);
	lista.WypiszElementyListy();
	lista.WypiszElementyListyOdKonca();
	
	
}