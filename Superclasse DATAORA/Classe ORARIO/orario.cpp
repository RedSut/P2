#include "orario.h"
#include<iostream>

orario::orario(int o,int m,int s){
    if(o<0 || o>23 || m<0 || m>59 || s<0 || s>59){
        sec=0;
    }else{
        sec = o*3600 + m*60 + s;
    }
};
orario orario::operator+(orario o) const{
    orario aux;
    aux.sec=(sec+o.sec)%86400;
    return aux;
}
orario orario::operator-(orario o) const{
    orario aux;
    aux.sec=(sec-o.sec)%86400;
    return aux;
}
bool orario::operator>(orario o) const{
    if(sec>o.sec){
        return true;
    }else{
        return false;
    }
}
bool orario::operator<(orario o) const{
    if(sec<o.sec){
        return true;
    }else{
        return false;
    }
}
bool orario::operator==(orario o) const{
    if(sec==o.sec){
        return true;
    }else{
        return false;
    }
}
bool orario::operator!=(orario o) const{
    if(sec!=o.sec){
        return true;
    }else{
        return false;
    }
}
orario::operator int(){
    return sec;
}
int orario::Ore() const{
    return sec/3600;
};
int orario::Minuti() const{
    return (sec/60)%60;
}
int orario::Secondi() const{
    return sec%60;
}
orario orario::UnOraPiuTardi() const{
    orario aux;
    aux.sec=/*this->*/sec+3600;
    return aux;
}
void orario::AvanzaUnOra(){
    sec+=3600;
}
std::ostream& operator<<(std::ostream& os,const orario& o){
    return os <<o.Ore()<<":"<<o.Minuti()<<":"<<o.Secondi();
}