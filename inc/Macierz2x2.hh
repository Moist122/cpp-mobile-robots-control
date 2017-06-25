//#ifndef MACIERZ_HH
//#define MACIERZ_HH
#pragma once

//#include <iostream>
#include "Wektor2D.hh"

constexpr int ROZMIAR=2; //!< rozmiar macierzy

/*!
 * \brief Opisuje macierz 2x2
 *
 *  Klasa opisująca macierz 2x2 przy pomocy tablicy
 */
class Macierz2x2 {
	float **pola; //!<Wskaźnik na 2 2-elementowe tablice reprezentujące liczby w macierzy
public:
	Macierz2x2(float x1=0, float x2=0, float x3=0, float x4=0);
		//!<konstruktor zapełniają pola macierzy danymi liczbami
	~Macierz2x2(); //!<destruktor
	float operator() (int wsp1, int wsp2) const;
		//!<zwraca wartość o podanych współrzędnych z macierzy nie zmieniając macierzy
	Wektor2D operator *(const Wektor2D wek) const; //!<mnoży macierz przez wektor
};


/*!
 * wej: ostream&, Macierz2x2
 * wyświetla: macierz w postaci [a][b]
 *                              [c][d]
 * wyj: ostream&
 */
std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac);

//#endif
