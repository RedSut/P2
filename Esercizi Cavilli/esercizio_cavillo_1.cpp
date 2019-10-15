//Esercizio Cavillo:
#include<iostream>
class C {
    public:
    int x;
    C() {x=8;}
    void f(int& s) const { s=4; } //metodo costante, non provoco modifiche sull'oggetto di invocazione
    void m() { f(x); } //metodo non costante, ma perchè? non faccio altro se non chiamare la funzione costante -> x è il campo dati dell'oggetto di invocazione -> FA SIDE EFFECT
};                     //se mettessi il const non andrebbe il compilatore.
                       //perchè?? è un errore di tipo, se mettessi il const quando faccio f(x) x è come this->x, e x è di tipo const int, non tipa sul parametro della funzione f

int main() {
    C c;
    std::cout << c.x << std::endl; // stampa 8
    c.m();
    std::cout << c.x << std::endl; // stampa 4
}