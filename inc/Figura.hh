#pragma once

#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
#include "Wektor2D.hh"


/*!
 *  \brief Klasa opisująca figurę
 *
 *  Klasa opisuje wielokąt jako wektor ozanczający wierzchołek P i wektory
 *  łączące go z pozostałymi wierzchołkami prostokąta
 */
class Figura {
protected:
  Wektor2D P; //!<łączy środek z początkiem układu współrzędnych
  std::vector<Wektor2D> narozniki; //!<łączą narożniki ze środekiem
public:
	static int ilosc;
	static int aktualnaIlosc;
	Figura(); //!<konstruktor zadający środek figury
	Figura(Wektor2D x); //!<konstruktor zadający środek figury
	Figura(Figura& Fig); //!<konstruktor kopiujący
	void wyswietl(std::ostream& Strm);
		//!<przekazuje współrzędne wierzchołków czytelne dla gnuplota
	virtual ~Figura(); //!<destruktor
	Wektor2D operator [](int f) const;
		//!<zwraca współrzędne wierzchołka nr p(0-3) prostokąta
	Wektor2D& operator ()(int f);
		//!<zwraca referencję do danego wektora (nr 0-3) tworzącego prostokąt
	int liczbaWierzcholkow() const; //!<zwraca liczbę wierzchołków figury
	Wektor2D wezPolozenie() const; //!<zwraca środek figury
	void przesun(Wektor2D wek); //!<przesuwa figurę o wektor
	virtual int typ() {return -1;} //!< zwraca typ obiektu: 0 - robot 1 - przeszkoda
};


/*!
 * wej: ostream&, prostokąt
 * wyświetla: współrzędne kolejnych wierzchołków prostokąta
 * wyj: ostream&
 */
std::ostream& operator << ( std::ostream &Strm, const Figura    &Fig);
//iterator list