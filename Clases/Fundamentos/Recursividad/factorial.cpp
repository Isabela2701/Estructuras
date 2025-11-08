#include <iostream>

int factorial_bucle(int n);
int factorial_recursivo(int n);

int main(){
    int n;
    std::cout<<"Ingrese un numero por teclado"<<std::endl;
    std::cin>>n;
    std::cout<<"El factorial de "<<n<<" es "<<factorial_bucle(n)<<std::endl;

    std::cout<<"El factorial de "<<n<<" es "<<factorial_recursivo(n)<<std::endl;
}

int factorial_bucle(int n){

    int factorial=1;
    for(int i=n; i>0; i--){
        factorial=factorial*i;  
    }
    return factorial;
}

int factorial_recursivo(int n){
    if (n > 0) {
        std::cout << "factorial(" << n << ")=" << n << "*" << "factorial(" << n - 1 << ")" << std::endl;
        return n * factorial_recursivo(n - 1);
    }
    else {
        std::cout << "factorial(" << n << ") = 1" << std::endl;
        return 1;
    }
}
