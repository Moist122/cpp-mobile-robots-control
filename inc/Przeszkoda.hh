#pragma once

#include <iostream>
#include <iomanip>
#include "Wektor2D.hh"
#include "Figura.hh"

constexpr int WIERZCHOLKI=4; //!<ilość boków figury reprezentowanej przez klasę

/*!
 *  \brief Klasa opisująca prostokąt
 *
 *  Klasa opisuje prostokąt jako wektor ozanczający wierzchołek P i 3 wektory
 *  łączące go z pozostałymi wierzchołkami prostokąta
 */
class Przeszkoda :public Figura {
public:
	Przeszkoda(Wektor2D x, int dl, int szer);
		//!<konstruktor zadający lewy dolny róg, długość i szerokość
	virtual ~Przeszkoda()=default; //!<destruktor
	virtual int typ() {return 1;}
};