/* ESERCIZIO:
Definire una classe vettore i cui oggetti rappresentano array di interi. 
vettore deve includere un costruttore di default, una operazione di 
concatenazione che restituisce un nuovo vettore v1+v2, una operazione di 
append v1.append(v2), l'overloading dell'uguaglianza, dell'operatore di 
output e dell'operatore di indicizzazione.  Deve inoltre includere il 
costruttore di copia profonda, l'assegnazione profonda e la distruzione profonda.
*/
#ifndef VETTORE_H
#define VETTORE_H
#include<iostream>

class Vettore {
private:
  // vettore vuoto iff a==nullptr && _size==0
  int* a;
  unsigned int _size;
public:
  // Conversione: unsigned int => Vettore
  Vettore(unsigned int s=0, int x=0);
  unsigned int size()const;
  Vettore(const Vettore& v); // ridefinizione costruttore di copia
  Vettore& operator=(const Vettore& v);
  ~Vettore();
  int& operator[](unsigned int i)const;
  // Esercizio: scrivere implementazione di append che effettura una sola copia
  void append(const Vettore& v); 
  bool operator==(const Vettore& v) const;
};
std::ostream& operator<<(std::ostream& os, const Vettore& v);
Vettore operator+(const Vettore& v1, const Vettore& v2);

#endif // VETTORE_H