#ifndef BOLLETTA_H
#define BOLLETTA_H
#include<iostream>
#include "../telefonata.h"
class bolletta{
    public:
        bolletta();
        bool Vuota()const;
        void Aggiungi_Telefonata(const telefonata&);
        void Togli_Telefonata(const telefonata&);
        telefonata EstraiUna();
    private:
        class nodo{ // definisco un'altra classe nodo nella parte privata di bolletta con cui rappresento la lista
            public:
                nodo();
                nodo(const telefonata&,nodo*);
                telefonata info;
                nodo* next;
        };
        nodo* first; // puntatore al primo nodo della lista    
};
#endif // BOLLETTA_H