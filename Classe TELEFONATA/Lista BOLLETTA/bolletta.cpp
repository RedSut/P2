#include<iostream>
#include "bolletta.h"
#include "../telefonata.h"

bolletta::nodo::nodo() : next(nullptr) { } //usa il costruttore di default per info

bolletta::nodo::nodo(const telefonata& t,nodo* s) : info(t),next(s) { }

bolletta::bolletta() : first(nullptr) { }

bool bolletta::Vuota()const{
    return first==0;
}
void bolletta::Aggiungi_Telefonata(const telefonata& t){
    *first=nodo(t,first);
}
void bolletta::Togli_Telefonata(const telefonata& t){
    nodo*p=first,*prec=nullptr;
    while(p && !(p->info==t)){
        prec=p;
        p=p->next;
    }
    if(p){
        if(!prec){
            first=p->next;
        }else{
            prec->next=p->next;
        }
        delete p;
    }
}