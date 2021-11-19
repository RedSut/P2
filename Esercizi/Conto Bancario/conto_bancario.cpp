#include<iostream>
#include "conto_bancario.h"

double ContoBancario::getSaldo(){
    return saldo;
}

double ContoBancario::deposita(double somma){
    return somma<=0 ? saldo : saldo+=somma;
}

double ContoBancario::preleva(double p){
    return p<=0 ? saldo : saldo-=p;
}

ContoBancario::ContoBancario(double s=0){
    saldo=s;
}

double ContoCorrente::deposita(double somma){
    return ContoBancario::deposita(somma-spesaFissa);
}

double ContoCorrente::preleva(double p){
    return ContoBancario::preleva(p+spesaFissa);
}

double ContoCorrente::spesaFissa=1.1;

ContoCorrente::ContoCorrente(double c=0): ContoBancario(c){}

double ContoDiRisparmio::preleva(double p){
    return getSaldo()<p ? getSaldo() : ContoBancario::preleva(p);
}

ContoDiRisparmio::ContoDiRisparmio(double c=0): ContoBancario(c>0 ? c : 0){}

double ContoArancio::deposita(double somma){
    appoggio.preleva(somma);
    return ContoDiRisparmio::deposita(somma);
}

double ContoArancio::preleva(double p){
    if(p <= getSaldo()){
        appoggio.deposita(p);   
        return ContoDiRisparmio::preleva(p);
    }
    return getSaldo();
}

double ContoArancio::getSaldoAppoggio(){
    return appoggio.getSaldo();
}

ContoArancio::ContoArancio(ContoCorrente& cc, double cr=0): ContoDiRisparmio(cr), appoggio(cc){}