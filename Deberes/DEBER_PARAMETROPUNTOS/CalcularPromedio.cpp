#include <iostream>
#include <cstdarg>

double promedio(int cantidad, ...){
    va_list lista;
    va_start(lista, cantidad);
    double suma = 0;

    for(int i=0; i<cantidad; i++){
        suma +=va_arg(lista, double);
    }

    va_end(lista);
    return suma/cantidad;

}

int main(){
    std::cout<<"Promedio = "<<promedio(5,2.5,3.5,4.0,5.0,3.0)<<std::endl;

}