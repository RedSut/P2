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
    //OPERATORI
    orario Ora(22,45),Ora1;
    orario DUE_ORE_E_UN_QUARTO(2,15);
    Ora1 = Ora + DUE_ORE_E_UN_QUARTO;
    std::cout<<"Orario Ora somma: "<<Ora1.Ore()<<":"<<Ora1.Minuti()<<":"<<Ora1.Secondi()<<std::endl;
    Ora1 = Ora - DUE_ORE_E_UN_QUARTO;
    std::cout<<"Orario Ora sottrazione: "<<Ora1.Ore()<<":"<<Ora1.Minuti()<<":"<<Ora1.Secondi()<<std::endl;
}