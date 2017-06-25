#include "Scena.hh"

using namespace std;

Scena::Scena() {
	//Robot r;
	rob.push_back(make_shared<Robot>());
	obiekty.push_back(std::make_shared<Robot>());
	obiekty.push_back(rob[0]);
	{
	Wektor2D wek0(15,0);
	rob.push_back(std::make_shared<Robot>(wek0,0));
	Wektor2D wek1(0,5), wek2(-3,-3), wek3(3,-3);
	rob[1]->dodajWierzcholek(wek1);
	rob[1]->dodajWierzcholek(wek2);
	rob[1]->dodajWierzcholek(wek3);
	obiekty.push_back(rob[1]);
	}
	Wektor2D wek0(0,-15);
	rob.push_back(std::make_shared<Robot>(wek0,0));
	Wektor2D wek1(0,3), wek2(1,1), wek3(2,-2), wek4(0,-1), wek5(-2,-2), wek6(-1,1);
	rob[2]->dodajWierzcholek(wek1);
	rob[2]->dodajWierzcholek(wek2);
	rob[2]->dodajWierzcholek(wek3);
	rob[2]->dodajWierzcholek(wek4);
	rob[2]->dodajWierzcholek(wek5);
	rob[2]->dodajWierzcholek(wek6);
	obiekty.push_back(rob[2]);


	Wektor2D ld1(-10,20), ld2(-30,9), ld3(20, 5);
	obiekty.push_back(std::make_shared<Przeszkoda>(ld1,15,10));
	obiekty.push_back(std::make_shared<Przeszkoda>(ld2,5,12));
	obiekty.push_back(std::make_shared<Przeszkoda>(ld3,15,5));

	Lacze.DodajNazwePliku("Robot.dat",PzG::RR_Ciagly,2);
	Lacze.DodajNazwePliku("Sciezka.dat",PzG::RR_Ciagly,1);
	Lacze.DodajNazwePliku("Przeszkody.dat",PzG::RR_Ciagly,2);
	Lacze.UstawZakresX(srodekSceny[0]-SZEROKOSC_SCENY,srodekSceny[0]+SZEROKOSC_SCENY);
	Lacze.UstawZakresY(srodekSceny[1]-SZEROKOSC_SCENY,srodekSceny[1]+SZEROKOSC_SCENY);
	robotZmieniony=przeszkodyZmienione=true;
	wyswietl();
}

bool Scena::rysujRoboty(const char *sNazwaPliku) {
	ofstream  StrmPlikowy;

	StrmPlikowy.open(sNazwaPliku);
	if (!StrmPlikowy.is_open())  {
		cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
		<< ":(  nie powiodla sie." << endl;
	return false;
	}
	for(unsigned int i=0;i<rob.size();++i) {
		rob[i]->wyswietl(StrmPlikowy);
	}
	StrmPlikowy.close();
	return !StrmPlikowy.fail();
}
bool Scena::rysujSciezke(const char *sNazwaPliku) {
	ofstream  StrmPlikowy;

	StrmPlikowy.open(sNazwaPliku);
	if (!StrmPlikowy.is_open())  {
		cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
		<< ":(  nie powiodla sie." << endl;
	return false;
	}
	for(unsigned int i=0;i<rob.size();++i)
		rob[i]->wyswietlSciezke(StrmPlikowy);
	StrmPlikowy.close();
	return !StrmPlikowy.fail();
}
bool Scena::rysujPrzeszkody(const char *sNazwaPliku) {
	ofstream  StrmPlikowy;

	StrmPlikowy.open(sNazwaPliku);
	if (!StrmPlikowy.is_open())  {
		cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
		<< ":(  nie powiodla sie." << endl;
	return false;
	}
	for(unsigned int i=0;i<obiekty.size();++i)
		if(obiekty[i]->typ())
			obiekty[i]->wyswietl(StrmPlikowy);
	StrmPlikowy.close();
	return !StrmPlikowy.fail();
}

int Scena::wyswietl() {
	if (robotZmieniony) {
		if (!rysujRoboty("Robot.dat")) return 1;
		if (!rysujSciezke("Sciezka.dat")) return 1;
		robotZmieniony=false;
	}
	if (przeszkodyZmienione) {
		if (!rysujPrzeszkody("Przeszkody.dat")) return 1;
		przeszkodyZmienione=false;
	}
	Lacze.Rysuj();
	return 0;
}

bool Scena::ruch(int czas, int nrRobota) {
	int krokow=czas/KROK;
	for(int i=0;i<krokow;++i) {
		int k=0;
		int predkoscIlosciowo=rob[nrRobota]->wezPredkoscIlosciowo();
		while(k<predkoscIlosciowo){
			if (kolizjaPoRuchu(nrRobota)) {
				wyswietl();
				return false;
			}
			rob[nrRobota]->ruch(KROK);
			k++;
			robotZmieniony=true;
		}
		wyswietl();
		usleep(ODSTEP_CZASU);
	}
	return true;
}

void Scena::obrocRobota(int kat, int nrRobota) {
	if(kat>0) {
		for(int i=0;i<kat/POJEDYNCZY_OBROT;++i) {
			rob[nrRobota]->obroc(POJEDYNCZY_OBROT);
			robotZmieniony=true;
			wyswietl();
			usleep(ODSTEP_CZASU);
		}
		rob[nrRobota]->obroc(kat%POJEDYNCZY_OBROT);
	}
	else {
		for(int i=0;i<kat/-POJEDYNCZY_OBROT;++i) {
			rob[nrRobota]->obroc(-POJEDYNCZY_OBROT);
			robotZmieniony=true;
			wyswietl();
			usleep(ODSTEP_CZASU);
		}
		rob[nrRobota]->obroc(kat%-POJEDYNCZY_OBROT);
	}
	if(kat%POJEDYNCZY_OBROT) {
		robotZmieniony=true;
		wyswietl();
		usleep(ODSTEP_CZASU);
	}
}

void Scena::zmienPredkoscRobota(double jednostek, int nrRobota) {
	rob[nrRobota]->zmienPredkosc(jednostek);
}
void Scena::przesunScene(Wektor2D wek) {
	srodekSceny=srodekSceny+wek;
	for(unsigned int i=0;i<obiekty.size();++i)
		obiekty[i]->przesun(wek);
	for(unsigned int i=0;i<rob.size();++i) 
		rob[i]->przesunSciezke(wek);
	robotZmieniony=true;
	przeszkodyZmienione=true;
	wyswietl();
}
void Scena::przywrocScene() {
	Wektor2D wek=-srodekSceny;
	przesunScene(wek);
}
void Scena::centrujNaRobocie(int nrRobota) {
	przesunScene(srodekSceny-rob[nrRobota]->wezPolozenie());
}
bool Scena::kolizjaPoRuchu(int nrRobota) {
	Wektor2D polozenie = rob[nrRobota]->wezPolozenie()+rob[nrRobota]->wezPredkosc();
	double prom=rob[nrRobota]->wezPromien();
	for(unsigned int i=0;i<obiekty.size();++i) {
		if (obiekty[i]->typ()) //przeszkody
			if (polozenie[0]>(*(obiekty[i]))[0][0]-prom&&
				polozenie[0]<(*(obiekty[i]))[2][0]+prom&&
				polozenie[1]>(*(obiekty[i]))[0][1]-prom&&
				polozenie[1]<(*(obiekty[i]))[2][1]+prom)
				return true;
	}
	for(int i=0;i<int(rob.size());++i) {
		if (i!=nrRobota&&(polozenie-rob[i]->wezPolozenie()).dl()<prom+rob[i]->wezPromien())
			return true;
	}
	return false;
	
}
int Scena::iloscRobotow() {
	return rob.size();
}

bool Scena::dodajRobota(Robot nowyRob) {
	Wektor2D polozenie = nowyRob.wezPolozenie();
	double prom=nowyRob.wezPromien();
	for(unsigned int i=0;i<obiekty.size();++i) {
		if (obiekty[i]->typ()) //przeszkody
			if (polozenie[0]>=(*(obiekty[i]))[0][0]-prom&&
				polozenie[0]<=(*(obiekty[i]))[2][0]+prom&&
				polozenie[1]>=(*(obiekty[i]))[0][1]-prom&&
				polozenie[1]<=(*(obiekty[i]))[2][1]+prom)
				return false;
	}
	for(unsigned int i=0;i<rob.size();++i) {
		if ((polozenie-rob[i]->wezPolozenie()).dl()<prom+rob[i]->wezPromien())
			return false;
	}
	rob.push_back(std::make_shared<Robot>(nowyRob));
	obiekty.push_back((rob.back()));
	robotZmieniony=true;
	return true;
}

bool Scena::dodajPrzeszkode(Przeszkoda nowaPrzesz) {
	Wektor2D wierzcholki[4] = {nowaPrzesz[0],nowaPrzesz[1],nowaPrzesz[2],nowaPrzesz[3]};
	for(int j=0;j<4;++j) {
		for(unsigned int i=0;i<obiekty.size();++i) {
			if (obiekty[i]->typ())
				if (wierzcholki[j][0]>(*(obiekty[i]))[0][0]&&
					wierzcholki[j][0]<(*(obiekty[i]))[2][0]&&
					wierzcholki[j][1]>(*(obiekty[i]))[0][1]&&
					wierzcholki[j][1]<(*(obiekty[i]))[2][1])
					return false;
		}
	}
	for(unsigned int i=0;i<rob.size();++i) {
		if (rob[i]->wezPolozenie()[0]>nowaPrzesz[0][0]-rob[i]->wezPromien()&&
			rob[i]->wezPolozenie()[0]<nowaPrzesz[2][0]+rob[i]->wezPromien()&&
			rob[i]->wezPolozenie()[1]>nowaPrzesz[0][1]-rob[i]->wezPromien()&&
			rob[i]->wezPolozenie()[1]<nowaPrzesz[2][1]+rob[i]->wezPromien())
			return false;
	}
	obiekty.push_back(make_shared<Figura>(nowaPrzesz));
	przeszkodyZmienione=true;
	return true;
}