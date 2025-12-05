#ifndef PERSONAJES_HPP
#define PERSONAJES_HPP
#include <string>
#include <iostream>
using namespace std;

class Personaje{
    private:
    string nombre;
    int posicion;

    public:
    Personaje(string Nombre, int Posicion){
        nombre=Nombre;
        posicion=Posicion;
    }

    Personaje(){
    }
    
    void setNombre(string Nombre){
        nombre=Nombre;
    }
    void setPosicion(int Posicion){
        posicion=Posicion;
    }

    void imprimirPersonaje(){
        cout<<"Nombre del personaje: "<<nombre<<endl;
        cout<<"Posicion: "<<posicion<<endl;
    }

    string getNombre(){
        return nombre;
    }
    
    int getPosicion(){
        return posicion;
    }
};
#endif