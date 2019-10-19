//ORARIO has-a TELEFONATA
#ifndef TELEFONATA_H
#define TELEFONATA_H
#include<iostream>
#include "../Classe ORARIO/orario.h"
class telefonata{
    private:
        orario inizio, fine;
        int numero; //da modificare il tipo
    public:
        telefonata(const orario&,const orario&,const int&);
        orario Inizio()const;
        orario Fine()const;
        int Numero()const;
        bool operator==(const telefonata)const;
};
std::ostream& operator<<(std::ostream&,const telefonata);
#endif // TELEFONATA_H