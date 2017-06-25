#
#  To sa Scena dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__start__: RobotMobilny
	./RobotMobilny

RobotMobilny: obj obj/main.o obj/Przeszkoda.o obj/Macierz2x2.o obj/Wektor2D.o\
           obj/lacze_do_gnuplota.o obj/Scena.o obj/Robot.o obj/Sciezka.o\
		   obj/Figura.o
	g++ -Wall -pedantic -std=c++0x -o RobotMobilny obj/main.o obj/Wektor2D.o\
         obj/Macierz2x2.o obj/Przeszkoda.o obj/lacze_do_gnuplota.o obj/Scena.o\
		 obj/Robot.o obj/Sciezka.o obj/Figura.o

obj:
	mkdir obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Przeszkoda.o: src/Przeszkoda.cpp inc/Przeszkoda.hh inc/Wektor2D.hh
	g++ -c ${CXXFLAGS} -o obj/Przeszkoda.o src/Przeszkoda.cpp
	
obj/Robot.o: src/Robot.cpp inc/Robot.hh #inc/Wektor2D.hh inc/ModelRobota.hh\
				inc/Sciezka.h
	g++ -c ${CXXFLAGS} -o obj/Robot.o src/Robot.cpp

obj/Macierz2x2.o: src/Macierz2x2.cpp inc/Macierz2x2.hh inc/Wektor2D.hh 
	g++ -c ${CXXFLAGS} -o obj/Macierz2x2.o src/Macierz2x2.cpp

obj/Wektor2D.o: src/Wektor2D.cpp inc/Wektor2D.hh
	g++ -c ${CXXFLAGS} -o obj/Wektor2D.o src/Wektor2D.cpp
	
obj/Figura.o: src/Figura.cpp inc/Figura.hh inc/Wektor2D.hh
	g++ -c ${CXXFLAGS} -o obj/Figura.o src/Figura.cpp

obj/Sciezka.o: src/Sciezka.cpp inc/Sciezka.hh
	g++ -c ${CXXFLAGS} -o obj/Sciezka.o src/Sciezka.cpp

obj/Scena.o: src/Scena.cpp inc/Scena.hh inc/Przeszkoda.hh inc/Macierz2x2.hh\
                               inc/Wektor2D.hh
	g++ -c ${CXXFLAGS} -o obj/Scena.o src/Scena.cpp

clean:
	rm -f obj/*.o RobotMobilny
