#include <iostream>
#include "Persona.h"

int Persona::getAnnoNascita()const{
    return anno_nascita;
}

int Persona::getAnnoMorte()const{
    return anno_morte;
}

std::string Persona::getNome()const{
    return Nome;
}

std::ostream& operator<<(std::ostream& os, const Persona& p){
    return os<<"Nome:"<<p.getNome()<<", Anno Nascita:"<<p.getAnnoNascita()<<", Anno Morte:"<<p.getAnnoMorte();
};