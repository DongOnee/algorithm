a.out : main.o lamp.o ButtonImp.o Button.o
	g++ main.o lamp.o ButtonImp.o Button.o
	rm *.o *.gch

main.o : main.cpp
	g++ -c main.cpp

lamp.o : lamp.cpp lamp.hpp ButtonClient.hpp
	g++ -c lamp.cpp

ButtonImp.o : ButtonImp.cpp ButtonImp.hpp
	g++ -c ButtonImp.cpp

Button.o : Button.cpp Button.hpp
	g++ -c Button.cpp