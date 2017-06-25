#include "Robot.hh"

using namespace std;

//Wektor2D Robot::wzorPredkosci(0,1);
//Wektor2D* Robot::wzorNaroznikow = new Wektor2D[narozniki.size()]; //watości przypisano w mainie

Robot::Robot(){
	Wektor2D start(0,0);
	P=start;
	Wektor2D w1(0,5),w2(4,2),w3(4,-2),w4(-4,-2),w5(-4,2);
	narozniki.push_back(w1);
	narozniki.push_back(w2);
	narozniki.push_back(w3);
	narozniki.push_back(w4);
	narozniki.push_back(w5);
	wzorNaroznikow.push_back(w1);
	wzorNaroznikow.push_back(w2);
	wzorNaroznikow.push_back(w3);
	wzorNaroznikow.push_back(w4);
	wzorNaroznikow.push_back(w5);
	Wektor2D pr(0,1);
	predkosc=pr;
	wzorPredkosci=pr;
	katObrotu=0;
	predkoscIlosciowo=1;
	promien=0;
	for(unsigned int i=0;i<narozniki.size();++i) {
		if (narozniki[i].dl()>promien) promien=narozniki[i].dl();
	}
	dodajPunkt(P);
}
Robot::Robot(Wektor2D wek) {
	P=wek;
	Wektor2D w1(0,5),w2(4,2),w3(4,-2),w4(-4,-2),w5(-4,2);
	narozniki.push_back(w1);
	narozniki.push_back(w2);
	narozniki.push_back(w3);
	narozniki.push_back(w4);
	narozniki.push_back(w5);
	wzorNaroznikow.push_back(w1);
	wzorNaroznikow.push_back(w2);
	wzorNaroznikow.push_back(w3);
	wzorNaroznikow.push_back(w4);
	wzorNaroznikow.push_back(w5);
	Wektor2D pr(0,1);
	predkosc=pr;
	wzorPredkosci=pr;
	katObrotu=0;
	predkoscIlosciowo=1;
	promien=0;
	for(unsigned int i=0;i<narozniki.size();++i) {
		if (narozniki[i].dl()>promien) promien=narozniki[i].dl();
	}
	dodajPunkt(P);
}
Robot::Robot(Wektor2D wek, double kat) {
	//narozniki=new Wektor2D[narozniki.size()];
	P = wek;
	Wektor2D pr(0,1);
	predkosc=pr;
	wzorPredkosci=pr;
	katObrotu=0;
	obroc(kat);
	predkoscIlosciowo=1;
	promien=0;
	for(auto i :narozniki) {
		if (i.dl()>promien) promien=i.dl();
	}
	dodajPunkt(P);
}
void Robot::dodajWierzcholek(Wektor2D w) {
	narozniki.push_back(w);
	wzorNaroznikow.push_back(w);
	if (w.dl()>promien) promien=w.dl();
}
void Robot::obliczPromien() {
	promien=0;
	for(unsigned int i=0;i<narozniki.size();++i) {
		if (narozniki[i].dl()>promien) promien=narozniki[i].dl();
	}
}
Robot::Robot(const Robot &rob) {
	P=rob.P;
	narozniki=rob.narozniki;
	wzorNaroznikow=rob.wzorNaroznikow;
	predkosc=rob.predkosc;
	wzorPredkosci=rob.wzorPredkosci;
	katObrotu=rob.katObrotu;
	predkoscIlosciowo=rob.predkoscIlosciowo;
	promien=rob.promien;
	dodajPunkt(P);
}
void Robot::wyswietlSciezke(ostream& Strm) const {
	for(unsigned int i=0;i<trasa.size();++i)
		Strm<<trasa[i]<<endl;
	Strm<<endl;
}
void Robot::ruch(int czas) {
	P=predkosc*czas+P;
	dodajPunkt(P);
}
void Robot::obroc(double kat) {
	katObrotu+=kat;
	double rad=katObrotu*M_PI/180;
	Macierz2x2 przeksztalcenie(cos(rad),-sin(rad),sin(rad),cos(rad));
	predkosc=przeksztalcenie*wzorPredkosci;
	for(unsigned int i=0;i<narozniki.size();++i) narozniki[i]=przeksztalcenie*wzorNaroznikow[i];
}
void Robot::zmienPredkosc(int jednostek) {
	if(jednostek>0) {
		predkoscIlosciowo=jednostek;
	}
}

Wektor2D Robot::wezPolozenie() const {
	return P;
}
double Robot::wezPromien() const {
	return promien;
}
Wektor2D Robot::wezPredkosc() const {
	return predkosc;
}
int Robot::wezPredkoscIlosciowo() const {
	return predkoscIlosciowo;
}
void Robot::przesunSciezke(Wektor2D wek) {
	for(unsigned int i=0;i<trasa.size();++i)
		trasa[i]=trasa[i]+wek;
}
