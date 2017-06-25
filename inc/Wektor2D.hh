#pragma once

#include <iostream>
#include <cmath>
#include <iomanip>

constexpr int WYMIARY=2; //!<ilość wymiarów w których znajduje się wektor

/*!
 *  \brief Klasa opisująca wektor 2D
 *
 *  Klasa opisująca wektor w 2 wymiarach poprzez 2 współrzędne
 */
class Wektor2D {
	float *wspolrzedne; //!<współrzędne (tablica 2 elementowa)
public:
	static int ilosc; //!<ilość utworzonych wektorów
	static int aktualnaIlosc; //!< aktualna ilość istniejących wektorów
	Wektor2D(float wsp1=0, float wsp2=0); //!<konstrunktor inicjujący wartości
	Wektor2D(const Wektor2D &W); //!<konstruktor kopiujący
	~Wektor2D(); //!<destruktor
	Wektor2D operator=(Wektor2D wek); //!<przypisanie wartości wektorowi
	float& operator [](int n) const; //!<zwraca wybraną współrzędną jako stałą
	float& operator [](int n); //!<zwraca wybraną współrzędną jako referencję
	Wektor2D operator +(Wektor2D wek) const; //!<suma wektorów
	bool operator ==(const Wektor2D wek) const; //!<porównanie wektorów
	Wektor2D operator -(Wektor2D wek) const; //!<różnica wektorów (odległość punktów)
	Wektor2D operator -() const; //!<wektor przeciwny
	Wektor2D operator *(int n) const;        //!<mnożenie współrzędnych wektora przez liczbę
	float dl();	//!<długość wektora
};


/*!
 * wej: istream&, Wektor2D (2 współrzędne)
 * przypisuje: Wektorowi2D zadane współrzędne [x,y]
 * wyj: &istream
 */
std::istream& operator >> (std::istream &Strm, Wektor2D &Wek);

/*!
 * wej: ostream&, wektor
 * wyświetla: wektor [x,y]
 * wyj: ostram&
 */
std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek);
