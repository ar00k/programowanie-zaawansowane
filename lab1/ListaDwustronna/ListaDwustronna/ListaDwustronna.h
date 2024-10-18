#pragma once

#include <ostream> // Dodane, aby uzywac std::ostream

class ListaDwustronna
{
    /// Struktura reprezentujaca pojedynczy element listy dwukierunkowej.
    struct Element
    {
        int wartosc; ///< Wartosc przechowywana w elemencie.
        Element* nastepny; ///< Wskaznik na nastepny element listy.
        Element* poprzedni; ///< Wskaznik na poprzedni element listy.

        /// Konstruktor domyslny struktury Element.
        Element();

        /// Konstruktor struktury Element, inicjalizujacy wartosc.
        /// @param _wartosc Wartosc elementu.
        Element(int _wartosc);

        /// Przeciazenie operatora << do wyswietlania wartosci elementu listy.
        /// @param os Strumien wyjsciowy.
        /// @param a Element listy.
        /// @return Zmieniony strumien wyjsciowy.
        friend std::ostream& operator<<(std::ostream& os, const Element& a);
    };

    Element* poczatek; ///< Wskaznik na pierwszy element listy.
    Element* koniec; ///< Wskaznik na ostatni element listy.
    int ilosc; ///< Liczba elementow w liscie.

public:
    /// Konstruktor domyslny listy dwukierunkowej.
    ListaDwustronna();

    /// Destruktor listy dwukierunkowej.
    ~ListaDwustronna();

    /// Dodaje nowy element na poczatku listy.
    /// @param _wartosc Wartosc nowego elementu.
    void DodajElementNaPoczatku(int _wartosc);

    /// Wypisuje wszystkie elementy listy od poczatku.
    void WypiszElementyListy();

    /// Wypisuje wszystkie elementy listy od konca.
    void WypiszElementyListyOdKonca();

    /// Dodaje nowy element na koncu listy.
    /// @param _wartosc Wartosc nowego elementu.
    void DodajElementNaKoncu(int _wartosc);

    /// Usuwa element z poczatku listy.
    void UsunElementZPoczatkuListy();

    /// Usuwa element z konca listy.
    void UsunElementZKoncaListy();

    /// Usuwa wszystkie elementy z listy.
    void WyczyscListe();

    /// Przeciazenie operatora << do wyswietlania elementow listy.
    /// @param os Strumien wyjsciowy.
    /// @param lista Lista dwukierunkowa.
    /// @return Zmieniony strumien wyjsciowy.
    friend std::ostream& operator<<(std::ostream& os, const ListaDwustronna& lista);

    /// Przeciazenie operatora << do wyswietlania wartosci pojedynczego elementu listy.
    /// @param os Strumien wyjsciowy.
    /// @param element Element listy, ktory ma byc wyswietlony.
    /// @return Zmieniony strumien wyjsciowy.
    friend std::ostream& operator<<(std::ostream& os, const ListaDwustronna::Element& element);
};
