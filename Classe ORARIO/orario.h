//#include</home/davide/Documenti/Code/P2/Classe ORARIO/orario.cpp>
#ifndef ORARIO_H
#define ORARIO_H
#include<iostream>
class orario{
    private:
    int sec;
    public:
    orario operator+(orario) const;
    orario operator-(orario) const;
    bool operator>(orario) const;
    bool operator<(orario) const;
    bool operator==(orario) const;
    bool operator!=(orario) const;
    orario(int=0,int=0,int=0);
    operator int();
    int Ore()const;
    int Minuti()const;
    int Secondi()const;
    orario UnOraPiuTardi()const;
    void AvanzaUnOra();
};
std::ostream& operator<<(std::ostream&,const orario&); //FA CONFLITTO CON QUELLO IN orario.cpp (!!)
#endif