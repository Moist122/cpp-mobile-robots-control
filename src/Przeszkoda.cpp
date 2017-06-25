#include "Przeszkoda.hh"

using namespace std;

Przeszkoda::Przeszkoda(Wektor2D x, int dl, int szer) {
	Wektor2D srodek(x[0]+szer/2,x[1]+dl/2);
	P=srodek;
	Wektor2D wek1(-szer/2,-dl/2);
	Wektor2D wek2(-szer/2,dl/2);
	Wektor2D wek3(szer/2,dl/2);
	Wektor2D wek4(szer/2,-dl/2);
	narozniki.push_back(wek1);
	narozniki.push_back(wek2);
	narozniki.push_back(wek3);
	narozniki.push_back(wek4);
}
