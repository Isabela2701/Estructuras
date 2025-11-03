#ifndef NODO_HPP
#define NODO_HPP

class nodo{

    private:

    nodo* Siguiente;
    nodo* Anterior;
    int Dato;

    public:
    nodo(int);
    nodo(nodo*, int);
    nodo(nodo*, nodo*, int);
    ~nodo();
    nodo* getSiguiente()const;
    nodo* getAnterior()const;
    void setSiguiente(nodo*);
    void setAnterior(nodo*);
    int getDato();
    void setDato(int);
};

#endif