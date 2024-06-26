bin: main.o empty.o 
	g++ main.o empty.o -o bin 
	rm *.o
main.o: main.cpp
	g++ -c -Wall main.cpp
empty.o: empty.cpp
	g++ -c -Wall empty.cpp
clean:
	rm *.o
