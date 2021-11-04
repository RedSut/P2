#include<iostream>
#include "dataora.h"

int dataora::Giorno()const{
    return giorno;
}
int dataora::Mese()const{
    return mese;
}
int dataora::Anno()const{
    return anno;
}
dataora::dataora(int g, int m, int a, orario o){
    giorno=g;
    mese=m;
    anno=a;
    sec=o;
}
