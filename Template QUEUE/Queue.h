#ifndef QUEUE_H
#define QUEUE_H

template<class T> 
class Queue{
friend ostream& operator<< <T> (std::ostream&, const Queue<T>&);
private:
    class QueueItem{
    friend ostream& operator<< <T> (std::ostream&, const QueueItem<T>&);
    friend ostream& operator<< <T> (std::ostream&, const Queue<T>&);
    public:
        QueueItem(const T& val);
        T info;
        QueueItem* next;
    };
    QueueItem<T>* primo;
    QueueItem<T>* ultimo;
public:
    Queue();
    ~Queue();
    bool empty()const;
    void add(const T&);
    T remove();
};

template<class T>
Queue<T>::Queue():primo(nullptr),ultimo(nullptr){}{ }

template<class T>
Queue<T>::~Queue(){
    while(empty()){
        remove();
    }
}

template<class T>
bool Queue<T>::empty()const{
    return (primo==nullptr);
}

template<class T>
void Queue<T>::add(const T& val){
    QueueItem<T>* p = new QueueItem<T>(val);
    if(empty()){
        primo=ultimo=p;
    }else{
        ultimo->next = p;
        ultimo = p;
    }
}

#include<iostream>
using std::endl; using std::cerr;

template<class T>
T Queue<T>::remove(){
    if(empty()){
        cerr<<"remove() su coda vuota!"<<endl;
        exit(1);
    }
    QueueItem<T>* p = primo;
    primo = primo->next;
    T aux = p->info;
    delete p;
    return aux;
}

template<class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template<class T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& q){
    os << "(";
    QueueItem<T>* p = q.primo;
    for(;p!=0;p=p->next){
        os << *p << " ";
    }
    os << ")" << endl;
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream&, const QueueItem<T>&);

template<class T>
std::ostream& operator<<(std::ostream& os, const QueueItem<T>& qi){
    os << qi.info; // Richiede operator<< per il tipo T
    return os;
};

#endif // QUEUE_H