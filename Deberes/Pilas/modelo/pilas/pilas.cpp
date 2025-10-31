#include "pilas.hpp"
#include <iostream>

pilas::pilas(){
    Top=nullptr;
}
pilas::pilas(int dato){
    Top=new nodo(dato);
}
pilas::~pilas(){
    while(Top!=nullptr){
        nodo* tmp=Top;
        tmp=tmp->getSiguiente();
        delete tmp;
    }
}

void pilas::push(int dato){
    if(Top==nullptr){
        Top=new nodo(dato);
        return;
    }
    nodo* tmp=new nodo(Top, dato);
    Top->setAnterior(tmp);
    Top=tmp;
}


