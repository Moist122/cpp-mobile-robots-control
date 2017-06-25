#include <iostream>
#include <iomanip>
#include <fstream>
#include <unistd.h>

#include "Wektor2D.hh"
#include "Robot.hh"
#include "Macierz2x2.hh"
#include "Przeszkoda.hh"
#include "Scena.hh"
#include "lacze_do_gnuplota.hh"



using namespace std;
//! wyświetla menu na standardowym wyjściu
void menu() {
	cout<<"Menu:"<<endl<<endl
		<<"Dostępne opcje:"<<endl
		<<" p - zmien predkość aktywnego robota"<<endl
		<<" o - obróć aktywnego robota"<<endl
		<<" j - jedź"<<endl
		<<" s - przesuń środek sceny"<<endl
		<<" r - resetuj środek sceny"<<endl
		<<" c - wycentruj scenę na aktywnym robocie"<<endl
		<<" d - dodaj robota"<<endl
		<<" w - dodaj przeszkodę"<<endl
		<<" z - zmien aktywnego robota"<<endl
		<<" m - wyświetl menu"<<endl
		<<" q - zakończ działanie programu"<<endl;
}

int main()
{
	{
	/*Wektor2D w1(0,5),w2(4,2),w3(4,-2),w4(-4,-2),w5(-4,2);
	Robot::WzorNaroznikow[0]=w1;
	Robot::WzorNaroznikow[1]=w2;
	Robot::WzorNaroznikow[2]=w3;
	Robot::WzorNaroznikow[3]=w4;
	Robot::WzorNaroznikow[4]=w5;*/
	char                  znak='0';   //do poruszania się po menu
	PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku Prostopadlosciana
	
	Scena Sc;
	if (Sc.wyswietl()) return 1;
	int aktualnyRobot=0;
	//double predkosc=1;
	//int calkowityObrot=0;
	menu();
	//int ilosc=1;
	while(znak!='q') { 
		cout<<"Twój wybór:"<<endl;
		cin>>znak;
		switch(znak) {
			case 'o': {//obroc
				int kat;
				cout<<"Podaj kąt obrotu w stopniach"<<endl;
				cin>>kat;
				Sc.obrocRobota(kat,aktualnyRobot);
				break;
			}
			case 'j': {//jedz
				cout<<"Przez jaki czas ma trwać ruch?"<<endl;
				int czas;
				cin>>czas;
				if (!Sc.ruch(czas,aktualnyRobot)) cout<<"Nastąpiła kolizja"<<endl;
				break;
			}
			case 'p': {//predkosc
				int predkosc;
				do {
					cout<<"Podaj nową prędkość"<<endl;
					cin>>predkosc;
				}while(predkosc<1);
				Sc.zmienPredkoscRobota(predkosc,aktualnyRobot);
				break;
			}
			case 'c': //centruj
				Sc.centrujNaRobocie(aktualnyRobot);
				break;
			case 's': {//przesun srodek sceny
				cout<<"Podaj wektor przesunięcia sceny"<<endl;
				Wektor2D przesuniecie;
				cin>>przesuniecie;
				Sc.przesunScene(przesuniecie);
				break;
			}
			case 'd': {//dodaj robota
				cout<<"Podaj wektor przesunięcia robota"<<endl;
				Wektor2D przesuniecie;
				cin>>przesuniecie;
				Robot rob(przesuniecie);
				if(!Sc.dodajRobota(rob))
					cout<<"Nie udało się dodać robota"<<endl;
				else {
					Sc.wyswietl();
				}
				break;
				
			}
			case 'w': { //dodaj przeszkodę
				Wektor2D lewyDolny;
				double poziomy, pionowy;
				cout<<"Podaj lewy dolny róg przeszkody"<<endl;
				cin>>lewyDolny;
				cout<<"Podaj długość poziomego boku"<<endl;
				cin>>poziomy;
				cout<<"Podaj długość pionowego boku"<<endl;
				cin>>pionowy;
				Przeszkoda nowaPrzesz(lewyDolny,pionowy,poziomy);
				if(!Sc.dodajPrzeszkode(nowaPrzesz)) cout<<"Nie udało się dodać przeszkody"<<endl;
				else Sc.wyswietl();
			}
				
			case 'r': //resetuj srodek sceny
				Sc.przywrocScene();
				break;
			case 'm':
				menu();
				break;
			case 'z': {//zmień robota
				do {
					cout<<"Podaj numer robota, którego chcesz kontrolować"<<endl;
					cin>>aktualnyRobot;
				}while(aktualnyRobot<0||aktualnyRobot>(Sc.iloscRobotow()-1));
				break;
			}
			default: break;
		}
	}
}
	cout<<"Utworzonych wektorów: "<<Wektor2D::ilosc<<endl;
	cout<<"Pozostałych wektorów: "<<Wektor2D::aktualnaIlosc<<endl;
	cout<<"Utworzonych figur: "<<Figura::ilosc<<endl;
	cout<<"Pozostałych figur: "<<Figura::aktualnaIlosc<<endl;
}
//mutable
//for(auto i :vec)