#ifndef NODO_HPP
#define NODO_HPP

class Nodo{
    private: 
    Nodo* Siguiente;
    int Dato;

    public:
    Nodo(int);
    Nodo(Nodo*, int);
    Nodo* getSiguiente()const;
    void setSiguiente(Nodo*);
    int getDato()const;
    void setDato(int);
};

#endif