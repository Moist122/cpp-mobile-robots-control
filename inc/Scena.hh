#pragma once

#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <memory>

#include "Wektor2D.hh"
#include "Macierz2x2.hh"
#include "Przeszkoda.hh"
#include "Robot.hh"
#include "lacze_do_gnuplota.hh"

constexpr int SZEROKOSC_SCENY=50;
constexpr int KROK=1; //!<co tyle czasu w trakcie ruchu odświeża się obraz
constexpr int ODSTEP_CZASU=500000; //!<odstęp między akcjami w mikrosekundach
constexpr int POJEDYNCZY_OBROT=45; //!<o tyle stopni roboty obracają się na raz;

class Scena {
	std::vector<std::shared_ptr<Robot>> rob; //!<lista robotów

	std::vector<std::shared_ptr<Figura>> obiekty; //!<lista robotów i przeszkód
	Wektor2D wekPrzesuniecia;

	Wektor2D srodekSceny; //!<centralny punkt wyswietlanego obszaru
	PzG::LaczeDoGNUPlota  Lacze; //!<łącze do gnuplota
	
	bool robotZmieniony; //!<czy trzeba aktualizować plik ze współrzędnymi robotów?
	bool przeszkodyZmienione; //!<czy trzeba aktualizować plik ze współrzędnymi przeszkód?
	
	bool rysujRoboty(const char *sNazwaPliku);
		//!<<zapisuje współrzędne wierzchołków robotów do pliku
	bool rysujSciezke(const char *sNazwaPliku);
		//!<zapisuje dotychczasowe ścieżki robotów do pliku
	bool rysujPrzeszkody(const char *sNazwaPliku);
		//!<zapisuje współrzędne wierzchołków przeszkód do  pliku
	
	public:
	Scena(); //!< konstruktor tworzący domyślną scenę
	void obrocRobota(int kat, int nrRobota); //!< obraca robota o zadanym numerze o podany kąt
	void zmienPredkoscRobota(double jednostek, int nrRobota);
		//!< zmienia prędkość danego robota na określoną ilość jednostek
	void przesunScene(Wektor2D wek); //!< przesuwa środek sceny o zadany wektor
	bool ruch(int czas, int nrRobota); //!< symuluję ruch przez zadaną ilość jednostek czasu
	bool kolizjaPoRuchu(int nrRobota);
		//!< sprawdza czy podany robot po przesunięciu zderzy się z przeszkodą
	int wyswietl(); //!<wyświetla scenę
	void przywrocScene(); //!<przywraca domyślny środek sceny
	void centrujNaRobocie(int nrRobota); //!<centruje scenę na środku robota
	
	bool dodajRobota(Robot nowyRob);
		//!< dodaje robota do listy, wartość zwracana oznacza sukces lub jego brak
	bool dodajPrzeszkode(Przeszkoda nowaPrzesz);
		//!< dodaje przeszkodę do listy, wartość zwracana to sukces lub jego brak
	int iloscRobotow();
	
	//double wezKat(int nrRobota);
	//double wezPolozenie(int nrRobota);
};

//using FiguraPtr=std::shared_ptr<Figura>
//obiekty.push_back(std::make_shared<Przeszkoda/Robot>(parametry konstuktora))
//przesuwanie sceny
//for(auto i:obiekty) i->przesun(x,y);
//alternatywa:
//figura może zwracać typ
//#include<algorithm> std::find() std::find_if(lista.begin(),lista.end(),[](auto& i)) {return i->zwrocID()=="Robot"}
//lambdy