/* 
Definire un template di classe albero<T> i cui oggetti rappresentano 
un albero 3-ario ove i nodi memorizzano dei valori di tipo T ed hanno 
3 figli (invece dei 2 figli di un usuale albero binario). Il template 
albero<T> deve soddisfare i seguenti vincoli:
1. Deve essere disponibile un costruttore di default che costruisce l’albero vuoto. 
2. Gestione della memoria senza condivisione.
3. Metodo void insert(const T&): a.insert(t) inserisce nell'albero a una nuova radice che memorizza il valore t ed avente come figli 3 copie di a 
4. Metodo bool search(const T&): a.search(t) ritorna true se t occorre nell'albero a, altrimenti ritorna false.
5. Overloading dell'operatore di uguaglianza.
6. Overloading dell'operatore di output.
*/

#ifndef TRIALBERO_H
#define TRIALBERO_H

#include<iostream>

template<class T>
class trialbero;

template <class T> 
std::ostream& operator<< (std::ostream&, const trialbero<T>&);

template <class T> 
class trialbero {
friend std::ostream& operator<< <T> (std::ostream&, const trialbero&);
private:
  class nodo {
  public:
    nodo(const T& =T(), nodo* =0, nodo* =0, nodo* =0);
    T info;
    nodo *sx, *cx, *dx;
    std::ostream& rec_print(std::ostream&);
  };
  nodo* root; // trialbero vuoto iff root==nullptr
  static nodo* copy(nodo*);
  static void destroy(nodo*);
  static bool rec_search(nodo*, const T&);
  static bool rec_equality(nodo*, nodo*); 
public:
  trialbero();
  trialbero(const trialbero&);
  trialbero& operator=(const trialbero&);
  ~trialbero();
  void insert(const T&);
  bool search(const T& t)const;
  bool operator==(const trialbero&)const;
};

//------------------------------------------IMPLEMENTAZIONE---------------------------------------------------------

template <class T> 
trialbero<T>::nodo::nodo(const T& t, nodo* s, nodo* c, nodo* d):info(t), sx(s), cx(c), dx(d) { }

template <class T>     
std::ostream& trialbero<T>::nodo::rec_print(std::ostream& os) {
    os << "(" << info << ",";
    if(sx) {sx->rec_print(os); os << ",";} else os << "null, ";
    if(cx) {cx->rec_print(os); os << ",";} else os << "null, ";
    if(dx) {dx->rec_print(os); os << ")";} else os << "null)";
    return os;
}

template <class T> 
typename trialbero<T>::nodo* trialbero<T>::copy(nodo* p) {
    if(!p) return nullptr;
    // p!= nullptr
    return new nodo(p->info,copy(p->sx), copy(p->cx), copy(p->dx)); 
}

template <class T> 
void trialbero<T>::destroy(nodo* p) {
    if(p!=nullptr) {
      destroy(p->sx);
      destroy(p->cx);
      destroy(p->dx);
      delete p; 
    } 
}

template <class T> 
bool trialbero<T>::rec_search(nodo* p, const T& t) {
    if(!p) return false;
    // p!=nullptr
    return p->info==t || rec_search(p->sx,t) || rec_search(p->cx,t) || rec_search(p->dx,t);
}

template <class T> 
bool trialbero<T>::rec_equality(nodo* p1, nodo* p2) {
    if(!p1 && !p2) return true;
    // p1 || p2
    if(!p1 || !p2) return false;
    // p1 && p2
    return p1->info==p2->info && rec_equality(p1->sx,p2->sx) &&
      rec_equality(p1->cx,p2->cx) && rec_equality(p1->dx,p2->dx);
} 

template <class T> 
trialbero<T>::trialbero(): root(nullptr) {}

template <class T> 
trialbero<T>::trialbero(const trialbero& t): root(copy(t.root)) {}

template <class T>   
trialbero<T>& trialbero<T>::operator=(const trialbero& t) {
    if(this != &t) {
      destroy(root);
      root=copy(t.root);
    }
    return *this;
}

template <class T> 
trialbero<T>::~trialbero() {destroy(root);} 
  
template <class T> 
void trialbero<T>::insert(const T& t) {
    root = new nodo(t,root,copy(root),copy(root));
}

// T deve offrire operator==
template <class T>
bool trialbero<T>::search(const T& t) const {
    return rec_search(root,t);
}

template <class T> 
bool trialbero<T>::operator==(const trialbero& t) const {
    return rec_equality(root,t.root);
}

template <class T> 
std::ostream& operator<< (std::ostream& os, const trialbero<T>& t) {
  if(t.root != nullptr) return t.root->rec_print(os);
  return os;
}

#endif // TRIALBERO_H