#include "Macierz2x2.hh"

Macierz2x2::Macierz2x2(float x1, float x2, float x3, float x4){
	pola = new float*[ROZMIAR];
	for(int i = 0; i < ROZMIAR; ++i)
    	pola[i] = new float[ROZMIAR];
	pola[0][0]=x1;
	pola[0][1]=x2;
	pola[1][0]=x3;
	pola[1][1]=x4;
}
Macierz2x2::~Macierz2x2(){
	for(int i;i<ROZMIAR;++i) delete pola[i];	
	delete[] pola;
}

float Macierz2x2::operator() (int wsp1, int wsp2) const {
    if(wsp1<0||wsp2<0||wsp1>=ROZMIAR||wsp2>=ROZMIAR) throw std::exception();
	return pola[wsp1][wsp2]; 
}
Wektor2D Macierz2x2::operator *(const Wektor2D wek) const {
	Wektor2D W(wek[0]*pola[0][0]+wek[1]*pola[0][1],wek[0]*pola[1][0]+wek[1]*pola[1][1]);
	return W;
}

std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac) {
	for(int i;i<ROZMIAR;i++) {
		for(int j;j<ROZMIAR;j++) Strm<<"["<<Mac(i,j)<<"]";
		Strm<<std::endl;
	}
	return Strm;
}
