#include<iostream>
#include"vettore.h"

int main() {
  Vettore v1, v2(3,1), v3(5,2);
  std::cout <<"V1: "<< v1 << std::endl;
  std::cout <<"V2: "<< v2 << std::endl;
  std::cout <<"V3: "<< v3 << std::endl;
  v1 = v2+v3;
  v2.append(v2);
  v3.append(v1);
  std::cout <<"V1 nuovo: "<< v1 << std::endl;
  std::cout <<"V2 nuovo: "<< v2 << std::endl;
  std::cout <<"V3 nuovo: "<< v3 << std::endl;
}