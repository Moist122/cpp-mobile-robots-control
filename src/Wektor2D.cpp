#include "Wektor2D.hh"

using namespace std;

int Wektor2D::ilosc=0;
int Wektor2D::aktualnaIlosc=0;

Wektor2D::Wektor2D(float wsp1, float wsp2) {
	wspolrzedne=new float[WYMIARY];
	wspolrzedne[0]=wsp1;
	wspolrzedne[1]=wsp2;
	ilosc++;
	aktualnaIlosc++;
}
Wektor2D::Wektor2D(const Wektor2D& wek) {
	wspolrzedne=new float[WYMIARY];
	for(int i=0;i<WYMIARY;++i) wspolrzedne[i]=wek.wspolrzedne[i];
	ilosc++;
	aktualnaIlosc++;
}
Wektor2D::~Wektor2D() {
	delete[] wspolrzedne;
	aktualnaIlosc--;
}
Wektor2D Wektor2D::operator=(Wektor2D wek) {
	wspolrzedne=new float[WYMIARY];
	for(int i=0;i<WYMIARY;++i) wspolrzedne[i]=wek.wspolrzedne[i];
	ilosc++;
	//aktualnaIlosc++;
	return *this;
}

float& Wektor2D::operator [](int n) const {
	if(n<0||n>=WYMIARY)  throw std::exception();
	return wspolrzedne[n];
}
float& Wektor2D::operator [](int n) {
	if(n<0||n>=WYMIARY)  throw std::exception();
	return wspolrzedne[n];
}

Wektor2D Wektor2D::operator +(Wektor2D wek) const {
	Wektor2D W(wspolrzedne[0]+wek[0],wspolrzedne[1]+wek[1]);
	return W; 
}

Wektor2D Wektor2D::operator -(Wektor2D wek) const {
	Wektor2D W(wspolrzedne[0]-wek[0],wspolrzedne[1]-wek[1]);
	return W; 
}
Wektor2D Wektor2D::operator -() const {
	Wektor2D W(-wspolrzedne[0],-wspolrzedne[1]);
	return W; 
}
Wektor2D Wektor2D::operator *(int n) const {
	Wektor2D W(wspolrzedne[0]*n,wspolrzedne[1]*n);
	return W; 
}
bool Wektor2D::operator ==(const Wektor2D wek) const {
	if(wspolrzedne[0]==wek.wspolrzedne[0]&&wspolrzedne[1]==wek.wspolrzedne[1])
		return true;
	else
		return false;
}
float Wektor2D::dl() {
	return sqrt(pow(wspolrzedne[0],2)+pow(wspolrzedne[1],2));
}

std::ostream& operator << (std::ostream &Strm, const Wektor2D &W) {
	for(int i=0;i<WYMIARY;++i)
		Strm << setw(16) << fixed << setprecision(10) << W[i];
	return Strm;
}

std::istream& operator >> (std::istream &Strm, Wektor2D &W) {
	float wsp1, wsp2;
	Strm>>wsp1>>wsp2;
	W[0]=wsp1;
	W[1]=wsp2;
	return Strm;
}
