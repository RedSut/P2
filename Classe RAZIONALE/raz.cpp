#include<iostream>
#include "raz.h"

Raz::Raz(int n,int d) : num(n),den(d!=0 ? d : 1){ }//mantiene INV (den!=0)
Raz Raz::inverso()const{
    //return Raz(den/num); NO se num==0 la funzione ritorna den/1 e non 0 (!!)
    return num!=0 ? Raz(den,num) : Raz();
}
Raz Raz::UnTerzo(){
    return Raz(1,3);
}
Raz::operator double()const{
    //return num/den; NO è una divisione tra interi e ritorna un int e non un double (!!)
    return static_cast<double>(num)/static_cast<double>(den); //static_cast<double>(n) -> converte n a double
}
Raz Raz::operator+(const Raz& r)const{
    return Raz(num*r.den + den*r.num,den*r.den);
}
Raz Raz::operator*(const Raz& r)const{
    return Raz(num*r.num,den*r.den);
}
Raz Raz::operator++(int){ // operatore ++ postfisso (x++)
    Raz aux(*this);
    *this=this->operator+(1); // assegno a this il suo valore +1, usando l'operatore + definito in precedenza, quindi converto 1 a Raz(1,1) con il costruttore ad un parametro
    return aux;
}
Raz& Raz::operator++(){ // operatore ++ prefisso (++x) 
    *this=this->operator+(1); // assegno a this il suo valore +1, usando l'operatore + definito in precedenza, quindi converto 1 a Raz(1,1) con il costruttore ad un parametro
    return *this;
}
bool Raz::operator==(const Raz& r)const{
    return num*r.den==den*r.num; // è sempre vero, anche per le rappresentazioni multiple
}
std::ostream& operator<<(std::ostream& os,const Raz& r){ // Non posso rappresentarlo num/den perchè è fouri dalla classe e non posso avere i metodi che ritornano num e den
    return os <<"Il razionale in virgola mobile è: "<<r.operator double();
}
