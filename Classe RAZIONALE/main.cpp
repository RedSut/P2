#include<iostream>
#include "raz.h"

int main(){
    Raz R1(1,4), R2(1,2), R3;
    //OUTPUT
    std::cout<<"R1: "<<R1<<std::endl;
    std::cout<<"R2: "<<R2<<std::endl;
    std::cout<<"R3: "<<R3<<std::endl;
    //OPERATORI
    std::cout<<"R1+R2: "<<R1+R2<<std::endl; // + 
    std::cout<<"R1*R2: "<<R1*R2<<std::endl; // *
    std::cout<<"R1++: "<<R1++<<std::endl; // ++ postfisso
    R1=Raz(1,4);
    std::cout<<"++R1: "<<++R1<<std::endl; // ++ prefisso
    std::cout<<"R1==R2: "; // ==
    R1==R2 ? std::cout<<"Sì"<<std::endl : std::cout<<"No"<<std::endl;
    Raz R4=Raz(R1);
    std::cout<<"R1==R4: ";
    R1==R4 ? std::cout<<"Sì"<<std::endl : std::cout<<"No"<<std::endl;
    //UN_TERZO
    std::cout<<"Un Terzo: "<<R1.UnTerzo()<<std::endl; //potevo usare un qualsiasi Raz
}