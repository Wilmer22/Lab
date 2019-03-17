CC:=g++
exe:=main
file:=A.cpp

all:
	g++ A.cpp -o main

run:
	./main
clean:
	rm -rf main