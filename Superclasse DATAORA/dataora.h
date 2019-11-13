#ifndef DATAORA_H
#define DATAORA_H

#include "Classe ORARIO/orario.h"
#include<iostream>

class dataora: public orario{ // DEFINIZIONE DI EREDITARIETÀ (PUBBLICA)
private:
    int giorno, mese, anno;
public:
    int Giorno()const;
    int Mese()const;
    int Anno()const;
};

#endif // DATAORA_H
