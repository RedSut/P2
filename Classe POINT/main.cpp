#include<iostream>
#include "Point.h"

int main(){
    Point P1(1,2,3),P2(3,0,9),P3;
    std::cout<<"Punto P1: "<<P1<<std::endl;
    std::cout<<"Punto P2: "<<P2<<std::endl;
    std::cout<<"Punto P3: "<<P3<<std::endl;
    std::cout<<"Norma P1: "<<P1.norm()<<std::endl;
    std::cout<<"Norma P2: "<<P2.norm()<<std::endl;
    std::cout<<"Norma P3: "<<P3.norm()<<std::endl;
    std::cout<<"P1 + P2: "<<P1+P2<<std::endl;
    std::cout<<"P2 + P1: "<<P2+P1<<std::endl;
    std::cout<<"P1 + P3: "<<P1+P3<<std::endl;
    std::cout<<"P3 + P2: "<<P3+P2<<std::endl;
}