#include<vector>

#include"Wektor2D.hh"
/*!
 *  \brief Klasa opisująca ścieżkę robota
 *
 *  Klasa opisuje ścieżkę robota jako tablicę wektorów
 */
class Sciezka{
	protected:
	std::vector<Wektor2D> trasa;
		//!<tablica kolejnych punktów przez które przejeżdża robot
	public:
	Sciezka(); //!<konstruktor
	void dodajPunkt(Wektor2D punkt); //!< dodaje nowy punkt do tablicy
};