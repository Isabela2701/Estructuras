#include <iostream>

int sumarNumero(int);
int main(){
    int n;
    std::cout<<"Ingrese un numero por teclado"<<std::endl;
    std::cin>>n;
    std::cout<<"El factorial de "<<n<<" es "<<sumarNumero(n)<<std::endl;
}

int sumarNumero(int n){

    if(n>0){
        return n+sumarNumero(n-1);
    }
    else{
        return 0;
    }
}