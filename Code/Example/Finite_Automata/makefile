objects = main.o  finite.o
edit : $(objects)
	g++ -std=c++17 $(objects) -o edit

main.o : main.cpp finite_automata.h
finite : finite.cpp finite_automata.h

.PHONY:clear
clear:
	rm *.o edit
	