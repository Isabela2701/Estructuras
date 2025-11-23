#include <iostream>
#include <string.h>
using namespace std;

class CuentaBancaria{

    private:
    
    string propietario;
    double saldo;
    string numeroCuenta;


    public:

    void retiro(double valor){
        if(saldo>=valor){
            saldo=saldo-valor;
            cout<<"\nEl retiro de $" << valor<< " se realizo exitosamente a la cuenta"<<numeroCuenta<<endl;
        }
        else{
            cout<<"\nSaldo insuficiente"<<endl;
        }   
    }
    void deposito (double valor){
        if(valor>0){
             saldo=saldo+valor;
             cout<<"\nEl deposito de $" << valor<< " se realizo exitosamente a la cuenta"<<numeroCuenta<<endl;
        }
        else{
            cout<<"\nValor a depositar invalido"<<endl;
        }
    }

    void setSaldo (double Saldo)
    {
        saldo=Saldo;
    }

    double getSaldo(){
        return saldo;
    }

    void setPropietario (string Propietario){
        propietario=Propietario;
    }

    string getPropietario(){
        return propietario;
    }
    
    void setNumeroCuenta(string NumeroCuenta){
        numeroCuenta=NumeroCuenta;
    }

    string getNumeroCuenta(){
        return numeroCuenta;
    }
    CuentaBancaria(double saldo, string propietario, string numeroCuenta){
        this->saldo=saldo;
        this->propietario=propietario;
        this->numeroCuenta=numeroCuenta;
    }
    void MostrarSaldo(){
        cout<<"\nEl saldo actual de la cuenta #" << numeroCuenta<<" es: "<<saldo;
    }
    

};

int main (){
    CuentaBancaria cuentaBancaria1(100,"Manuel", "123333333333333");
    cuentaBancaria1.retiro(50);
    cuentaBancaria1.MostrarSaldo();
    cuentaBancaria1.deposito(-10);
    cuentaBancaria1.MostrarSaldo();
    cuentaBancaria1.deposito(20);
    cuentaBancaria1.MostrarSaldo();

    //cuentaBancaria1
    //cuentaBancaria1.saldo=cuentaBancaria1.saldo+1000;
    cuentaBancaria1.MostrarSaldo();

}