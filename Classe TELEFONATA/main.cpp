//ORARIO has-a TELEFONATA
#include<iostream>
#include "telefonata.h"
#include "./Lista BOLLETTA/bolletta.h"

orario Somma_Durate(bolletta b){ // b passato per valore, così non modifico la lista originale
    orario durata;
    while(!b.Vuota()){
        telefonata t = b.EstraiUna();
        durata = durata + t.Fine() - t.Inizio();
    }
    return durata; // quando esco dalla funzione gli oggetti locali (b,t e durata) vengono deallocati
    // quando b viene deallocata, il puntatore first viene deallocato, ma la lista di tipo nodo NON viene deallocata (!!)
}

int main(){
    orario I1(12,45), I2(17), F1(13), F2(20,32,45), I3(15,30), F3(16,11,30);
    int N1 = 33135, N2 = 34087, N3 = 33499;
    telefonata T1(I1,F1,N1), T2(I2,F2,N2), T3(I3,F3,N3);
    //OPERATORE OUTPUT TELEFONATA
    std::cout<<"T1: "<<T1<<std::endl;
    std::cout<<"T2: "<<T2<<std::endl;
    std::cout<<"T3: "<<T3<<std::endl;
    //OPERATORE ==
    telefonata T4(T1);
    if(T4==T1){
        std::cout<<"T4 è uguale a T1"<<std::endl;
    }else{
        std::cout<<"T4 è diverso da T1"<<std::endl;
    }
    if(T2==T1){
        std::cout<<"T2 è uguale a T1"<<std::endl;
    }else{
        std::cout<<"T2 è diverso da T1"<<std::endl;
    }
    //LISTA BOLLETTA
    bolletta b, b2;
    b.Aggiungi_Telefonata(T1);
    b.Aggiungi_Telefonata(T2);
    b.Aggiungi_Telefonata(T3);
    b2=b;
    std::cout<<"La somma delle durate di b è: "<<Somma_Durate(b)<<std::endl;
    b.Togli_Telefonata(T2);
    std::cout<<"La somma delle durate di b è: "<<Somma_Durate(b)<<std::endl;
    std::cout<<"La somma delle durate di b2 è: "<<Somma_Durate(b2)<<std::endl;
    if(b.Vuota()){
        std::cout<<"b è vuota"<<std::endl;
    }else{
        std::cout<<"b NON è vuota"<<std::endl;
    }
    std::cout<<b.EstraiUna()<<std::endl;
    std::cout<<"La somma delle durate di b è: "<<Somma_Durate(b)<<std::endl;
    std::cout<<b.EstraiUna()<<std::endl;
    std::cout<<"La somma delle durate di b è: "<<Somma_Durate(b)<<std::endl;

}