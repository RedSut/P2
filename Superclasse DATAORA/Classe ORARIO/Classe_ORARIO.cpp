#include<iostream>
//#include "orario.cpp"
#include "orario.h"

int main(){
    orario O(14,45,19); 
    int ore=O.Ore(),min=O.Minuti(),sec=O.Secondi();
    std::cout<<"Orario O: "<<ore<<":"<<min<<":"<<sec<<std::endl;
    //UN ORA PIU TARDI e AVANZA UN ORA
    orario O1=O.UnOraPiuTardi();
    std::cout<<"Orario O1: "<<O1.Ore()<<":"<<O1.Minuti()<<":"<<O1.Secondi()<<std::endl;
    O.AvanzaUnOra();
    std::cout<<"Orario O nuovo: "<<O.Ore()<<":"<<O.Minuti()<<":"<<O.Secondi()<<std::endl;
    //OPERATORI
    orario Ora(22,45),Ora1;
    orario DUE_ORE_E_UN_QUARTO(2,15);
    Ora1 = Ora + DUE_ORE_E_UN_QUARTO;// +
    std::cout<<"Orario Ora somma: "<<Ora1.Ore()<<":"<<Ora1.Minuti()<<":"<<Ora1.Secondi()<<std::endl;
    Ora1 = Ora - DUE_ORE_E_UN_QUARTO;// -
    std::cout<<"Orario Ora sottrazione: "<<Ora1.Ore()<<":"<<Ora1.Minuti()<<":"<<Ora1.Secondi()<<std::endl;
    bool B = false;
    if(Ora > DUE_ORE_E_UN_QUARTO){// >
        std::cout<<Ora.Ore()<<":"<<Ora.Minuti()<<" è maggiore di "<<DUE_ORE_E_UN_QUARTO.Ore()<<":"<<DUE_ORE_E_UN_QUARTO.Minuti()<<std::endl;
    }else{
        std::cout<<Ora.Ore()<<":"<<Ora.Minuti()<<" NON è maggiore di "<<DUE_ORE_E_UN_QUARTO.Ore()<<":"<<DUE_ORE_E_UN_QUARTO.Minuti()<<std::endl;
    }
    if(Ora < DUE_ORE_E_UN_QUARTO){// <
        std::cout<<Ora.Ore()<<":"<<Ora.Minuti()<<" è minore di "<<DUE_ORE_E_UN_QUARTO.Ore()<<":"<<DUE_ORE_E_UN_QUARTO.Minuti()<<std::endl;
    }else{
        std::cout<<Ora.Ore()<<":"<<Ora.Minuti()<<" NON è minore di "<<DUE_ORE_E_UN_QUARTO.Ore()<<":"<<DUE_ORE_E_UN_QUARTO.Minuti()<<std::endl;
    }
    orario Ora_cp(Ora);
    if(Ora==Ora_cp){// ==
        std::cout<<Ora.Ore()<<":"<<Ora.Minuti()<<" è uguale a "<<Ora_cp.Ore()<<":"<<Ora_cp.Minuti()<<std::endl;
    }else{
        std::cout<<Ora.Ore()<<":"<<Ora.Minuti()<<" è diverso da "<<Ora_cp.Ore()<<":"<<Ora_cp.Minuti()<<std::endl;
    }
    if(Ora!=Ora1){// !=
        std::cout<<Ora.Ore()<<":"<<Ora.Minuti()<<" è diverso da "<<Ora1.Ore()<<":"<<Ora1.Minuti()<<std::endl;
    }else{
        std::cout<<Ora.Ore()<<":"<<Ora.Minuti()<<" è uguale a "<<Ora1.Ore()<<":"<<Ora1.Minuti()<<std::endl;
    }
    //OUTPUT
    orario Out(17,17,17);
    std::cout<<"Orario Out: "<<Out<<std::endl;
}