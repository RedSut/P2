#include<iostream>
#include "dataora.h"

int main(){ 
    orario o1(12,12,12), o2(16,51);
    dataora d1;
    o2=d1; // Subtyping, conversione da DATAORA ad ORARIO
    std::cout<<"d2: "<<d1<<std::endl; // Subtyping, conversione da DATAORA ad ORARIO
    std::cout<<"o1: "<<o1<<std::endl;
    std::cout<<"o2: "<<o2<<std::endl;
}