a.out : main.o Button.o Lamp.o
	g++ main.o Button.o Lamp.o
	rm *.o *.gch

main.o : main.cpp
	g++ -c main.cpp

Button.o : Button.cpp Button.hpp
	g++ -c Button.cpp Button.hpp

Lamp.o : Lamp.cpp Lamp.hpp
	g++ -c Lamp.cpp Lamp.hpp

clean:
	rm *.o a.out *.gch