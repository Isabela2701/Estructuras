#ifndef BUSQUEDA_HPP
#define BUSQUEDA_HPP
#include "Personajes.hpp"
#include <string>
using namespace std;
class Busqueda{
    public:
    static int busquedaNombre(Personaje** listaBuscar,string nombreBuscar, int size){
        int izquierda=0;
        int derecha=size;
        


        while(izquierda<=derecha){

            int mitad=izquierda+(derecha-izquierda)/2;

            if(nombreBuscar==listaBuscar[mitad]->getNombre()){
            return mitad;
            }
            if(nombreBuscar<listaBuscar[mitad]->getNombre()){
            derecha=mitad-1;
            }
            else if(nombreBuscar>listaBuscar[mitad]->getNombre()){
            izquierda=mitad+1;
            }
         }
        return -1; 
    }
       
};
#endif