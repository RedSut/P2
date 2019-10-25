#include<iostream>
#include "bolletta.h"
#include "../telefonata.h"

// ------------------------------------- CLASSE NODO ----------------------------------------------------

bolletta::nodo::nodo() : next(nullptr) { } //usa il costruttore di default per info

bolletta::nodo::nodo(const telefonata& t,nodo* s) : info(t), next(s) { }

bolletta::nodo::~nodo(){ // nel distruttore non bisogna mettere la lista di inizializzaione
    // invocazione del distruttore standard di telefonata e deallocazione automatica di next (alla fine)
    if(next!=0){
        delete next; // chiamata ricorsiva
    }
}
// ------------------------------------- CLASSE ITERATORE ----------------------------------------------------

bool bolletta::iteratore::operator==(const iteratore& i)const{
    return punt==i.punt;
}
bool bolletta::iteratore::operator!=(const iteratore& i)const{
    return punt!=i.punt;
}
bolletta::iteratore& bolletta::iteratore::operator++(){ // ++ prefisso
    if(punt){
        punt=punt->next;
    }
    return *this;
}
bolletta::iteratore bolletta::iteratore::operator++(int){ // ++ postfisso
    iteratore aux(*this);
    if(punt){
        punt=punt->next;
    }
    return aux;
}
telefonata* bolletta::iteratore::operator->()const{
    return &(punt->info);
}
telefonata& bolletta::iteratore::operator*()const{
    return punt->info;
}
// ------------------------------------- CLASSE BOLLETTA ----------------------------------------------------

bolletta::bolletta() : first(nullptr) { }

bolletta::~bolletta(){ // nel distruttore non bisogna mettere la lista di inizializzaione
    if(first){
        delete first; // chiama ~nodo()
    }
}

bolletta::bolletta(const bolletta& b) : first(copia(b.first)) { } // ridefinizione del costruttore di copia di bolletta

bolletta::iteratore bolletta::begin()const{
    iteratore aux;
    aux.punt=first;
    return aux;
}
bolletta::iteratore bolletta::end()const{
    iteratore aux;
    aux.punt=nullptr;
    return aux;
}
telefonata& bolletta::operator[](const bolletta::iteratore& it)const{
    return it.punt->info;
}
bool bolletta::Vuota()const{
    return first==0;
}
void bolletta::Aggiungi_Telefonata(const telefonata& t){
    first=new nodo(t,first);
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
telefonata bolletta::EstraiUna(){
    // PRE = bolletta non vuota
    nodo* p = first;
    first = first->next;
    telefonata aux = p->info;
    delete p;
    return aux;
}
bolletta::nodo* bolletta::copia(nodo*p){
    if(!p){ // caso base
        return nullptr;
    }else{
        return new nodo(p->info,copia(p->next)); // caso ricorsivo
    }
}
void bolletta::distruggi(nodo*p){
    // caso base -> non faccio niente
    if(p){
        distruggi(p->next); // caso ricorsivo
        delete p;
    }
}
bolletta& bolletta::operator=(const bolletta& b){
    if(this != &b){ // controlla che l'oggetto d'invocazione sia diverso da b
        distruggi(first);
        first=copia(b.first);
    }
    return *this;
}
