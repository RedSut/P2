//ORARIO has-a TELEFONATA
#include "telefonata.h"

telefonata::telefonata(){ numero==0; }

telefonata::telefonata(const orario& i,const orario& f,const int& n):inizio(i),fine(f),numero(n){/*vuoto*/};

orario telefonata::Inizio()const{
    return inizio;
}        
orario telefonata::Fine()const{
    return fine;
}
int telefonata::Numero()const{
    return numero;
}
bool telefonata::operator==(const telefonata t)const{
                                                                 // I primi due == utilizzano l'overloading di ==
    return inizio==t.inizio && fine==t.fine && numero==t.numero; // definito nella classe ORARIO, se non fosse definito,
                                                                 // l'operazione darebbe un ERRORE (!)
}                                                                 
std::ostream& operator<<(std::ostream& os,const telefonata t){
    return os<<std::endl<<"INIZIO: "<<t.Inizio()<<std::endl<<"FINE: "<<t.Fine()<<std::endl<<"NUMERO: "<<t.Numero()<<std::endl;
}