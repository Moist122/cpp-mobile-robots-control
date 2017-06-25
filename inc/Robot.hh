#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include "Wektor2D.hh"
#include "Macierz2x2.hh"
#include "Sciezka.hh"
#include "Figura.hh"

/*!
 *  \brief Klasa opisująca robota
 *
 *  Klasa opisuje robota jako wektor ozanczający środek P i 5 wektorów
 *  łączących go z wierzchołkami modelu robota
 */
class Robot :public Sciezka, public Figura {
	//int wierzcholkiRobota;
	double promien; //!<największa odległość wierzchołka od środka
	Wektor2D predkosc; //!<kierunek ruchu robota (wektor jednostkowy)
	int predkoscIlosciowo; //!<prędkość jako liczba jednostek
	double katObrotu; //!<kąt o jaki obórcono robota
	std::vector<Wektor2D> wzorNaroznikow; //!<wzorcowe wartości narożników figury tworzącej robota
	Wektor2D wzorPredkosci; //!<wzorcowa prędkość jednostkowa robota
public:
	Robot(); //!<konstruktor ustawiający domyślnego robota
	Robot(Wektor2D wek); //!<konstruktor ustawiający domyślnego robota w wybranym miejscu
	Robot(Wektor2D wek, double kat);
		//!<konstruktor ustawiający domyślnego robota w wybranym miejscu i obróconego
	Robot(const Robot &rob); //!<konstruktor kopiujący
	void wyswietlSciezke(std::ostream& Strm) const;
		//!<przekazuje punkty scieżki czytelnie dla gnuplota
	Wektor2D wezPolozenie() const; //!<zwraca wektor aktualnego położenia
	double wezPromien() const; //!<zwraca promien robota
	Wektor2D wezPredkosc() const; //!<zwraca wektor aktualnej predkosci
	int wezPredkoscIlosciowo() const; //!<zwraca aktualną prędkość jako liczbę
	void ruch(int czas); //!<wykonuje ruch przez określoną ilość jednostek czasu
	void obroc(double kat); //!<obraca figurę i wektor prędkości o zadany kąt
	void zmienPredkosc(int jednostek); //!<zmienia prędkość na określloną ilość jednostek
	void obliczPromien(); //!<oblicza promień robota
	void dodajWierzcholek(Wektor2D w); //!<dodaje wierzchołek do robota
	virtual ~Robot()=default; //!<destruktor
	virtual int typ() {return 0;}
	void przesunSciezke(Wektor2D wek); //!<przesuwa ścieżkę o wektor
};