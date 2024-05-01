objects = main.o count.o
edit:$(objects)
	g++ $(objects) -o edit

main.o:main.cpp count.h
count.o:count.cpp count.h


.PHONY:clear
clear:
	rm  edit $(objects)