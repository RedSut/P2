//ORARIO has-a TELEFONATA
#include<iostream>
#include "telefonata.h"

int main(){
    orario I1(12,45), I2(17), F1(13), F2(20,32,45);
    int N1 = 33135, N2 = 34087;
    telefonata T1(I1,F1,N1), T2(I2,F2,N2);
    //OPERATORE OUTPUT
    std::cout<<"T1: "<<T1<<std::endl;
    std::cout<<"T2: "<<T2<<std::endl;
    //OPERATORE ==
    telefonata T3(T1);
    if(T3==T1){
        std::cout<<"T3 è uguale a T1"<<std::endl;
    }else{
        std::cout<<"T3 è diverso da T1"<<std::endl;
    }
    if(T2==T1){
        std::cout<<"T2 è uguale a T1"<<std::endl;
    }else{
        std::cout<<"T2 è diverso da T1"<<std::endl;
    }
    
}