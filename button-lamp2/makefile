a.out : main.o
	g++ main.o

main.o : main.cpp lamp.o ButtonImp.o Button.o
	g++ -c main.cpp lamp.o ButtonImp.o Button.o

lamp.o : lamp.cpp lamp.hpp ButtonClient.hpp
	g++ -c lamp.cpp

ButtonImp.o : ButtonImp.cpp ButtonImp.hpp Button.o
	g++ -c ButtonImp.cpp Button.o

Button.o : Button.cpp Button.hpp
	g++ -c Button.cpp