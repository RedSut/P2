#ifndef DLIST
#define DLIST
/*
ESERCIZIO. 

Definire un template di classe dList<T> i cui oggetti rappresentano una struttura dati lista doppiamente concatenata (doubly linked list) per elementi di uno stesso tipo T. Il template dList<T> deve soddisfare i seguenti vincoli:

1. Gestione della memoria senza condivisione.

2. dList<T> rende disponibile un costruttore dList(unsigned int k, const T& t) che costruisce una 
lista contenente k nodi ed ognuno di questi nodi memorizza una copia di t.

3. dList<T> permette l’inserimento in testa ed in coda ad una lista in tempo O(1) (cioe` costante):
-- Deve essere disponibile un metodo void insertFront(const T&) con il seguente comportamento: dl.insertFront(t) inserisce l’elemento t in testa a dl in tempo O(1).
-- Deve essere disponibile un metodo void insertBack(const T&) con il seguente comportamento: dl.insertBack(t) inserisce l’elemento t in coda a dl in tempo O(1).

4. dList<T> rende disponibile un opportuno overloading di operator< che implementa l’ordinamento lessicografico (ad esempio, si ricorda che per l'ordinamento lessicografico tra stringhe abbiamo che "campana" < "cavolo" e che
"eccellente" < "ottimo").

5. dList<T> rende disponibile un tipo iteratore costante dList<T>::constiterator i cui oggetti permettono di iterare sugli elementi di una lista.
*/

#include<iostream>

//-------------------------------------------DEFINIZIONE-------------------------------------------------------------

template<class T>
class dList {
private:
  class nodo {
  public:
    T info;
    nodo *prev, *next;
    nodo(const T& t = T(), nodo* p=nullptr, nodo* n=nullptr);
    ~nodo();
  };
  nodo *last, *first; // lista vuota iff first==last==nullptr

  static nodo* copy(nodo*, nodo*&);
  static bool isLess(nodo*, nodo*);

public:
  ~dList();
  dList(const dList&);
   
  dList& operator=(const dList&);
  void insertFront(const T&);
  void insertBack(const T&);
  dList(unsigned int, const T&);
  bool operator<(const dList&) const;
  
  class constiterator {
    friend class dList<T>;
  private:
    nodo* ptr;
    bool pastTheEnd; // true iff constiterator e' "past-the-end"
    // conversione nodo* => constiterator
    constiterator(nodo* p, bool pte=false);
  public:
    constiterator();

    const T& operator*() const;
    const T* operator->() const;
    constiterator& operator++();
    constiterator& operator--();
    bool operator==(const constiterator&) const;
    bool operator!=(const constiterator& x) const;
  };
  constiterator begin() const;
  constiterator end() const;
};


//---------------------------------------------IMPLEMENTAZIONE-------------------------------------------------------------

template<class T>
class nodo;

template<class T>
class constiterator;

template<class T>
dList<T>::nodo::nodo(const T& t, nodo* p, nodo* n): info(t), prev(p), next(n) { }

template<class T>
dList<T>::nodo::~nodo() {delete next;}

template<class T>
typename dList<T>::nodo* dList<T>::copy(nodo* p, nodo*& l){
    if(p==nullptr) return l=nullptr;
    nodo* prec=new nodo(p->info,nullptr,nullptr);
    nodo* succ=prec;;
    nodo* start=prec;
    while(p->next!=nullptr) {
      succ = new nodo(p->next->info,prec,nullptr);
      prec->next=succ;
      p=p->next;
      prec=prec->next;
    }
    l=succ;
    return start;
}
/* possibile versione ricorsiva
  static nodo* copy(nodo* p, nodo* pre, nodo*& l) {
    if(p == nullptr) return p = nullptr;
    // p != nullptr
    nodo* temp = new nodo(p->info,pre,nullptr);
    temp->next = copy(p->next,temp,l);
    if(p->next == nullptr) l=temp;
    return temp;
  }
*/
template<class T>
bool dList<T>::isLess(nodo* d1, nodo* d2) {
    if(d2==nullptr) return false;
    // d2 NON e' vuota
    if(d1==nullptr) return true;
    // d1 e d2 NON vuote
    return d1->info < d2->info || 
      (d1->info==d2->info && isLess(d1->next,d2->next));
}   

template<class T>
dList<T>::~dList() {delete first;}

template<class T>
dList<T>::dList(const dList& d): first(copy(d.first,last)) {
    // first=copy(d.first,last);
}

template<class T>
dList<T>& dList<T>::operator=(const dList& d) {
    if(this != &d) {
      delete first;
      first=copy(d.first,last);
    }
    return *this;
  }

template<class T>
void dList<T>::insertFront(const T& t) {
    first = new nodo(t,nullptr,first);
    if(first->next==nullptr) {
      // lista di invocazione era vuota
      last=first;
    }
    else {
      // lista di invocazione NON era vuota
      (first->next)->prev=first;
    }
}

template<class T>
void dList<T>::insertBack(const T& t) {
    last = new nodo(t,last,nullptr);
    if(last->prev==nullptr) {
      // lista di invocazione era vuota
      first=last;
    }
    else {
      // lista di invocazione NON era vuota
      (last->prev)->next=last;
    }
}

template<class T>
dList<T>::dList(unsigned int k, const T& t): last(nullptr), first(nullptr) {
    for(unsigned int i=0; i<k; ++i) 
      insertFront(t);
}

template<class T>
bool dList<T>::operator<(const dList& d) const {
    return isLess(first,d.first);
}

template<class T>
dList<T>::constiterator::constiterator(nodo* p, bool pte): ptr(p), pastTheEnd(pte) { }
    
template<class T>    
dList<T>::constiterator::constiterator(): ptr(nullptr), pastTheEnd(false) { }

template<class T>
const T& dList<T>::constiterator::operator*() const {
    return ptr->info;
}

template<class T>
const T* dList<T>::constiterator::operator->() const {
    return &(ptr->info);
}

template<class T>    
typename dList<T>::constiterator& dList<T>::constiterator::operator++() {
  if(ptr!= nullptr) {
	if(!pastTheEnd) { 
	  if(ptr->next==nullptr) {++ptr; pastTheEnd=true;}
	  else {ptr=ptr->next;}
	}
  }
  return *this;
}

template<class T>    
typename dList<T>::constiterator& dList<T>::constiterator::operator--() {
  if(ptr!=nullptr) {
	if(pastTheEnd) {--ptr; pastTheEnd=false;}
	else ptr=ptr->prev;
  }
  return *this;
}

template<class T>    
bool dList<T>::constiterator::operator==(const constiterator& x) const {
    return ptr==x.ptr;
}

template<class T>
bool dList<T>::constiterator::operator!=(const constiterator& x) const {
    return ptr!=x.ptr;
}

template<class T>
typename dList<T>::constiterator dList<T>::begin() const {
    return first;
}

template<class T>
typename dList<T>::constiterator dList<T>::end() const {
    if(last==nullptr) return nullptr;
    return constiterator(last+1,true);
}

#endif // !DLIST