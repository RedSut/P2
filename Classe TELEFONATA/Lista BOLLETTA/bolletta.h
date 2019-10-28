#ifndef BOLLETTA_H
#define BOLLETTA_H
#include<iostream>
#include "../telefonata.h"
class bolletta{
    private:
        class nodo{ // definisco un'altra classe nodo nella parte privata di bolletta con cui rappresento la lista
            public:
                nodo();
                //~nodo();
                nodo(const telefonata&,nodo*);
                telefonata info;
                nodo* next;
        };
        nodo* first; // puntatore al primo nodo della lista
        static nodo* copia(nodo* p); // funzione statica per copiare una bolletta in maniera profonda (deep copy)
        static void distruggi(nodo* p); // funzione statica per deallocare tutti i nodi dopo p di una bolletta 
    public:
        class iteratore{ // definisco una classe iteratore per leggere gli elementi della lista
            friend class bolletta;
            private:
                bolletta::nodo* punt;
            public:
                bool operator==(const iteratore&)const;
                bool operator!=(const iteratore&)const;
                iteratore& operator++();
                iteratore operator++(int);
                telefonata* operator->()const;
                telefonata& operator*()const;
        };
        iteratore begin()const;                         //
        iteratore end()const;                           // Aggiungo questi 3 metodi per la classe iteratore
        telefonata& operator[](const iteratore&)const;  //
        bolletta();
        ~bolletta();
        bolletta(const bolletta&); // ridefinizione del costruttore di copia
        bool Vuota()const;
        void Aggiungi_Telefonata(const telefonata&);
        void Togli_Telefonata(const telefonata&);
        telefonata EstraiUna();
        bolletta& operator=(const bolletta&);
        friend std::ostream& operator<<(std::ostream&,const bolletta&);
         
};
#endif // BOLLETTA_H