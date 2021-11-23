/*Definire una classe "Persona" i cui oggetto rappresentano
anagraficamente un personaggio storico caratterizato da nome, anno di nascita
e anno di morte.
Includere opportuni costruttori, metodi di accesso ai campi
ed overloading dell'operatore di output come funzione esterna.
Separare interfaccia ed implementazione della classe.
Si definisca inoltre un esempio di metodo main() che usa tutti i metodi
della classe e l'operatore di output.*/

#include<iostream>
#ifndef PERSONA_H
#define PERSONA_H

class Persona{
    private:
        std::string Nome;
        int anno_nascita;
        int anno_morte;
    public:
        Persona(std::string n, int an, int am): Nome(n), anno_nascita(an), anno_morte(am){};
        int getAnnoNascita()const;
        int getAnnoMorte()const;
        std::string getNome()const;
    friend std::ostream& operator<<(std::ostream&s, const Persona&);
};

std::ostream& operator<<(std::ostream&, const Persona&);

#endif