#include "Figura.hh"

using namespace std;

int Figura::ilosc=0;
int Figura::aktualnaIlosc=0;

Figura::Figura() {
	Wektor2D start(0,0);
	P=start;
	ilosc++;
	aktualnaIlosc++;
}
Figura::Figura(Wektor2D x) {
	P=x;
	ilosc++;
	aktualnaIlosc++;
}
Figura::Figura(Figura& Fig) {
	P=Fig.P;
	narozniki=Fig.narozniki;
	ilosc++;
	aktualnaIlosc++;
}
Figura::~Figura() {
	aktualnaIlosc--;
}
/*Figura::Figura(const Figura &Pr) {
	P=Pr.P;
	narozniki=new Wektor2D[narozniki-1];
	for(int i=0;i<narozniki-1;++i) narozniki[i]=Pr.narozniki[i];
}*/

/*void Figura::dodajWierzcholek(Wektor2D w) {
	narozniki.push_back(w);
}*/
void Figura::wyswietl(ostream& Strm) {
	//Strm<<P<<endl;
	for(unsigned int i=0;i<(narozniki.size());++i)
		Strm<<P+narozniki[i]<<endl;
	Strm<<P+narozniki[0]<<endl<<endl;
}
Wektor2D Figura::wezPolozenie() const {
	return P;
}

Wektor2D Figura::operator [](int p) const {
	for(int i=0;i<int(narozniki.size());++i) 
		if(i==p) return P+narozniki[i];
	throw std::exception();
}
//[1] zwraca zerowy element vectora
Wektor2D& Figura::operator ()(int p) {
	for(int i=0;i<int(narozniki.size());++i) 
		if(i==p) return narozniki[i];
	throw std::exception();
}
int Figura::liczbaWierzcholkow() const {
	return narozniki.size();
}
void Figura::przesun(Wektor2D wek) {
	P=P+wek;
}

ostream& operator << (ostream &Strm, const Figura &Fig)
{
	for(int i=1;i<Fig.liczbaWierzcholkow()+1;++i)
	Strm << setw(16) << fixed << setprecision(10) << Fig[i][0]
		 << setw(16) << fixed << setprecision(10) << Fig[i][1] << endl;
	return Strm;
}

//std::map wskaźniki robotów na ścieżki
//roboty o różnych kształtach
