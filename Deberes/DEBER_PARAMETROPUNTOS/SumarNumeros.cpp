#include <iostream>
#include <cstdarg>

int sumar(int cantidad, ...){
    va_list lista;
    va_start(lista, cantidad);
    int suma =0;


    for(int i=0; i<cantidad; i++){
        suma+=va_arg(lista, int);
    }

    va_end(lista);
    return suma;
}

int main(){
    std::cout<<"Suma = "<<sumar(4,10,20,30,40)<<std::endl;
}