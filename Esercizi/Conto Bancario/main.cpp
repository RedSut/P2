#include<iostream>
#include "conto_bancario.h"

void StampaSaldiConti(ContoBancario cb, ContoCorrente cc, ContoDiRisparmio cr, ContoArancio ca){
    std::cout<<"ContoBancario: "<<cb.getSaldo()<<std::endl;
    std::cout<<"ContoCorrente: "<<cc.getSaldo()<<std::endl;
    std::cout<<"ContoDiRisparmio: "<<cr.getSaldo()<<std::endl;
    std::cout<<"ContoArancio: "<<ca.getSaldo()<<" Appoggio: "<<ca.getSaldoAppoggio()<<std::endl;
}

int main(){
    ContoBancario cb(1000);
    ContoCorrente cc(1000), cca(1000);
    ContoDiRisparmio cr(1000);
    ContoArancio ca(cca,1000);

    std::cout<<"-----Saldi Iniziali-----"<<std::endl;
    StampaSaldiConti(cb,cc,cr,ca);
    std::cout<<"-----Prelievo di 100-----"<<std::endl;
    cb.preleva(100);
    cc.preleva(100);
    cr.preleva(100);
    ca.preleva(100);
    StampaSaldiConti(cb,cc,cr,ca);
    std::cout<<"-----Deposito di 50-----"<<std::endl;
    cb.deposita(50);
    cc.deposita(50);
    cr.deposita(50);
    ca.deposita(50);
    StampaSaldiConti(cb,cc,cr,ca);
    std::cout<<"-----Prelievo di -100-----"<<std::endl;
    cb.preleva(-100);
    cc.preleva(-100);
    cr.preleva(-100);
    ca.preleva(-100);
    StampaSaldiConti(cb,cc,cr,ca);
    std::cout<<"-----Deposito di -50-----"<<std::endl;
    cb.deposita(-50);
    cc.deposita(-50);
    cr.deposita(-50);
    ca.deposita(-50);
    StampaSaldiConti(cb,cc,cr,ca);
    std::cout<<"-----Prelievo di 2000-----"<<std::endl;
    cb.preleva(2000);
    cc.preleva(2000);
    cr.preleva(2000);
    ca.preleva(2000);
    StampaSaldiConti(cb,cc,cr,ca);
}