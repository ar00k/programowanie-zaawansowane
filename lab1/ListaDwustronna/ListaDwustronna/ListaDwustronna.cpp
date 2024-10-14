#include <iostream>
#include "ListaDwustronna.h"

ListaDwustronna::Element::Element() :wartosc{}, poprzedni(nullptr), nastepny{} {

};

ListaDwustronna::ListaDwustronna() :poczatek(nullptr), koniec(nullptr) {
	
};
