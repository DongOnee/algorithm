CC = g++
OBJECT = main.o suv.o car.o engineer.o motorcycle.o

a.out : $(OBJECT)
	$(CC) $(OBJECT)
	rm *.o *.gch
	./a.out

main.o : main.cpp
	$(CC) -c main.cpp

suv.o : suv.cpp suv.hpp
	$(CC) -c suv.cpp suv.hpp

car.o : car.cpp car.hpp
	$(CC) -c car.cpp car.hpp

engineer.o : engineer.cpp engineer.hpp
	$(CC) -c engineer.cpp engineer.hpp

motorcycle.o : motorcycle.cpp motorcycle.hpp
	$(CC) -c motorcycle.cpp motorcycle.hpp

clean :
	rm a.out