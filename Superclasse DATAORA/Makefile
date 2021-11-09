all: compile display clean

compile: main.o dataora.o orario.o
	g++ main.o dataora.o orario.o -o output
	@echo "----------------------------------------------"

display:
	@echo "----------------- OUTPUT: --------------------"
	./output
	@echo "----------------------------------------------"

main.o: main.cpp
	@echo "-------------- Compilazione ------------------"
	g++ -c main.cpp

dataora.o: dataora.cpp dataora.h
	g++ -c dataora.cpp

orario.o: Classe\ ORARIO/orario.cpp Classe\ ORARIO/orario.h
	g++ -c Classe\ ORARIO/orario.cpp 

clean:
	@echo "------------- Pulizia dei file  --------------"
	rm *.o output
	@echo "----------------------------------------------"
