#ifndef BOLLETTA_H
#define BOLLETTA_H
#include<iostream>
#include "../telefonata.h"
class bolletta{
    public:
        bolletta();
        bolletta(const bolletta&); // ridefinizione del costruttore di copia
        bool Vuota()const;
        void Aggiungi_Telefonata(const telefonata&);
        void Togli_Telefonata(const telefonata&);
        telefonata EstraiUna();
        bolletta& operator=(const bolletta&);
    private:
        class nodo{ // definisco un'altra classe nodo nella parte privata di bolletta con cui rappresento la lista
            public:
                nodo();
                nodo(const telefonata&,nodo*);
                telefonata info;
                nodo* next;
        };
        nodo* first; // puntatore al primo nodo della lista
        static nodo* copia(nodo* p); // funzione statica per copiare una bolletta in maniera profonda (deep copy)
        static void distruggi(nodo* p); // funzione statica per deallocare tutti i nodi dopo p di una bolletta   
};
#endif // BOLLETTA_H