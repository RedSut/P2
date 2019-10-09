#include<iostream>
//#include</home/davide/Documenti/Code/P2/Classe ORARIO/orario.h>
#include</home/davide/Documenti/Code/P2/Classe ORARIO/orario.cpp>

int main(){
    orario O(14,45,19); 
    int ore=O.Ore(),min=O.Minuti(),sec=O.Secondi();
    std::cout<<"Orario O: "<<ore<<":"<<min<<":"<<sec<<std::endl;
    orario O1=O.UnOraPiuTardi();
    std::cout<<"Orario O1: "<<O1.Ore()<<":"<<O1.Minuti()<<":"<<O1.Secondi()<<std::endl;
    O.AvanzaUnOra();
    std::cout<<"Orario O nuovo: "<<O.Ore()<<":"<<O.Minuti()<<":"<<O.Secondi()<<std::endl;
}