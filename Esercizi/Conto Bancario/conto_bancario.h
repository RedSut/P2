#include <iostream>
#ifndef CONTO_H
#define CONTO_H

/* ESERCIZIO. Definire una superclasse ContoBancario e due sue sottoclassi ContoCorrente 
e ContoDiRisparmio che soddisfano le seguenti specifiche:

1) Ogni ContoBancario è caratterizzato da un saldo e rende disponibili due funzionalità di
deposito e prelievo: double deposita(double) e double preleva(double) che ritornano il saldo
aggiornato dopo l’operazione di deposito/prelievo.
2) Ogni ContoCorrente è caratterizzato anche da una spesa fissa uguale per ogni ContoCorrente chedeve essere detratta dal saldo ad ogni operazione di deposito e prelievo.
3) Ogni ContoDiRisparmio deve avere un saldo non negativo e pertanto non tutti i prelievi sono
permessi; d’altra parte, le operazioni di deposito e prelievo non comportano costi aggiuntivi e
restituiscono il saldo aggiornato.
4) Si definisca inoltre una classe ContoArancio derivata da ContoDiRisparmio. La classe
ContoArancio deve avere un ContoCorrente di appoggio: quando si deposita una somma S su un
ContoArancio, S viene prelevata dal ContoCorrente di appoggio; d’altra parte, i prelievi di una
somma S da un ContoArancio vengono depositati nel ContoCorrente di appoggio.*/ 

class ContoBancario{
    private:
        double saldo;
    public:
        double getSaldo();
        double deposita(double);
        double preleva(double);
        ContoBancario(double);
};

class ContoCorrente: public ContoBancario{
    private:
        static double spesaFissa;
    public:
        double deposita(double);
        double preleva(double);
        ContoCorrente(double);
};

class ContoDiRisparmio: public ContoBancario{
    public:
        double preleva(double);
        ContoDiRisparmio(double);
};

class ContoArancio: public ContoDiRisparmio{
    private:
        ContoCorrente& appoggio;
    public:
        double getSaldoAppoggio();
        double deposita(double);
        double preleva(double);
        ContoArancio(ContoCorrente&,double);
};

#endif