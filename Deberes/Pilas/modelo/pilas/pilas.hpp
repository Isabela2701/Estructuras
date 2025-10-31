#ifndef PILA_HPP
#define PILA_HPP

#include "../Nodo/nodo.hpp"

class pilas{
    private:
    nodo* Top;
    public:
    pilas();
    pilas(int);
    ~pilas();
    void push(int);
    void pop();
    bool isEmpty()const;
    void peek()const;
    void display()const;
    void editTop(int);
};

#endif