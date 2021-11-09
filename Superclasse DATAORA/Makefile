output: main.o dataora.o orario.o
	g++ main.o dataora.o orario.o -o output

display: output
	@echo "ECCO L'OUTPUT:"
	./output

main.o: main.cpp
	g++ -c main.cpp

dataora.o: dataora.cpp dataora.h
	g++ -c dataora.cpp

orario.o: Classe\ ORARIO/orario.cpp Classe\ ORARIO/orario.h
	g++ -c Classe\ ORARIO/orario.cpp 

clean:
	rm *.o output

all: output display clean
