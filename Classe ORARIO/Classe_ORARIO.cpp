#include<iostream>
//#include</home/davide/Documenti/Code/P2/Classe ORARIO/orario.h>
#include</home/davide/Documenti/Code/P2/Classe ORARIO/orario.cpp>

int main(){
    orario O(14,45,19); 
    int ore=O.Ore(),min=O.Minuti(),sec=O.Secondi();
    std::cout<<"Orario: "<<ore<<":"<<min<<":"<<sec<<std::endl;
}