#include <iostream>

using namespace std;

class Nodo{
    public:
    int dato;
    Nodo* siguiente;

    Nodo(int n){
        dato=n;
        siguiente=nullptr;
    }
};


class ListaEnlazada{
    private:
    Nodo* cabeza=nullptr;
    Nodo* cola=nullptr;
    int tamanio=0;

    public:

    void append(int n){
        Nodo* nuevo_nodo=new Nodo(n);
        if(cabeza==nullptr){
            cabeza=nuevo_nodo;
            cola=nuevo_nodo;
        }
        else{
            cola->siguiente=nuevo_nodo;
            cola=nuevo_nodo;
        }
        tamanio++;
    }

    void display() {
        Nodo* current = cabeza;
        cout << "List: ";
        while (current != nullptr) {
            cout << current->dato;
            if (current->siguiente != nullptr) {
                cout << " -> ";
            }
            current = current->siguiente;
        }
        cout << " -> NULL" << endl;
        if (cabeza != nullptr) {
            cout << "Head: " << cabeza->dato << ", Tail: " << cola->dato << endl;
        }
    }

    void removerUltimoElemento(){
        if(cabeza==nullptr){
            std::cout<<"\nLa lista esta vacia"<<std::endl;
            return;  
        }
        if(cabeza==cola){
            delete cabeza;
            cabeza=nullptr;
            cola=nullptr;
        }
        
        else{

            Nodo* tmp=cabeza;
            while(tmp->siguiente!=cola){
                tmp=tmp->siguiente;
            }
            delete cola;
            cola=tmp;
            tmp->siguiente=nullptr;    
        } 
        tamanio--; 
    }

    void removerPrimerElemento(){

        if(cabeza==nullptr){
            std::cout<<"\nLa lista esta vacia"<<std::endl;
        }
        else{
            Nodo* tmp= cabeza;
            cabeza=cabeza->siguiente;
            delete tmp;

            if(cabeza==nullptr){
                cola=nullptr;
            }
        }
        tamanio--;
    }


};



int main (){

    ListaEnlazada lista1;
    lista1.append(30);
    lista1.append(40);
    lista1.append(50);
    lista1.append(60);
    lista1.append(70);
    lista1.append(80);
    lista1.display();
    lista1.removerPrimerElemento();
    lista1.display();
    lista1.removerUltimoElemento();
    lista1.display();
    lista1.removerUltimoElemento();
    lista1.display();
    lista1.removerUltimoElemento();
    lista1.display();
    lista1.removerUltimoElemento();
    lista1.display();
    lista1.removerUltimoElemento();
    lista1.display();
}

