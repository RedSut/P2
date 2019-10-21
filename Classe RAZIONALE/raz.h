#ifndef RAZIONALE_H
#define RAZIONALE_H
#include<iostream>
class Raz{
    private:
        int num, den; //INV: den!=0
    public:
        Raz(int n=0,int d=1); // è anche un covertitore da int a Raz
        Raz inverso()const;
        static Raz UnTerzo();
        operator double()const; //convertitore Raz -> double
        Raz operator+(const Raz& r)const; //lo definisco all'interno della classe, perchè ho deciso di lasciare le rappresentazioni multiple (1/2==2/4)
        Raz operator*(const Raz& r)const; //lo definisco all'interno della classe, perchè ho deciso di lasciare le rappresentazioni multiple (1/2==2/4)
        Raz operator++(int);
        Raz& operator++();
        bool operator==(const Raz& r)const;
        //Non ha senso definire dei metodi che ritornano num e den perchè li metterei nella parte pubblica, così facendo
        //però ne do l'accesso anche nel main e avendo scelto di permettere le rappresentazioni multiple, lo stesso valore
        //in virgola mobile avrebbe più di un valore per num e più di un valore per den
};
std::ostream& operator<<(std::ostream&,const Raz&);
#endif // RAZIONALE_H
