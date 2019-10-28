/* ESERCIZIO:
Definire una classe vettore i cui oggetti rappresentano array di interi. 
vettore deve includere un costruttore di default, una operazione di 
concatenazione che restituisce un nuovo vettore v1+v2, una operazione di 
append v1.append(v2), l'overloading dell'uguaglianza, dell'operatore di 
output e dell'operatore di indicizzazione.  Deve inoltre includere il 
costruttore di copia profonda, l'assegnazione profonda e la distruzione profonda.
*/
#include<iostream>
#include "vettore.h"

Vettore::Vettore(unsigned int s, int x): a(s==0 ? nullptr :  new int[s]), _size(s){
    for(int i=0; i<_size; ++i) a[i]=x;
}  

unsigned int Vettore::size() const {return _size;}

Vettore::Vettore(const Vettore& v): a(v.size() == 0 ? nullptr : new int[v.size()]), _size(v.size()) {
    for(int i=0; i<_size; ++i) a[i]=v.a[i];
}

Vettore& Vettore::operator=(const Vettore& v) {
    if(this != &v) {
      delete[] a;
      a = v.size() == 0 ? nullptr : new int[v.size()];
      _size = v.size();
      for(int i=0; i<_size; ++i) a[i]=v.a[i];
    }
    return *this;
}

Vettore::~Vettore() {
    delete[] a;
}

int& Vettore::operator[](unsigned int i) const {
    return a[i];
}

bool Vettore::operator==(const Vettore& v) const {
    if(this == &v) return true;
    if(size() != v.size()) return false;
    // this != &v && size() == v.size() 
    for(int i=0; size(); ++i) if(a[i]!=v[i]) return false;
    // this != &v && size() == v.size() && \forall i in [0,v.size()[. a[i]==v[i]
    return true;
}

std::ostream& operator<<(std::ostream& os, const Vettore& v) {
  for(int i=0; i<v.size(); ++i) os << v[i] << ' '; 
  return os;
}

Vettore operator+(const Vettore& v1, const Vettore& v2) {
    Vettore aux(v1.size() + v2.size());
    int i=0;
    for( ;i<v1.size(); ++i) aux[i] = v1[i];
    for( ;i<aux.size(); ++i) aux[i] = v2[i-v1.size()];
    return aux;
}
// Esercizio: scrivere implementazione di append che effettura una sola copia
void Vettore::append(const Vettore& v) {
    *this = *this + v;
}
