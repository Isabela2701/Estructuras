#include <iostream>
#include <cstdarg>

int mayor(int cantidad, ...){
    va_list lista;
    va_start(lista, cantidad);
    int maximo=va_arg(lista, int);

    for(int i=1; i<cantidad; i++){
        int num=va_arg(lista, int);
        if(num>maximo) maximo=num;
    }

    va_end(lista);
    return maximo;
}

int main(){
    std::cout<<"El mayor es: "<<mayor(6,5,7,8,9,12,4,0)<<std::endl;
}