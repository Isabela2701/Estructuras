#include <iostream>
#include <string>
using namespace std;

int main (){
    int cantidad;
    string* nombres;
    string nom;
    string tmp[4]={"Juan","June","Maria","Jose"};
    tmp[2]="Miguel";

    cout<<"Ingrese el numero de empleados"<<endl;
    cin>>cantidad;
    nombres=new string[cantidad];

    for(int i=0; i<cantidad; i++){
        cout<<"Ingrese el nombre: "<<endl;
        cin>>nom;
        nombres[i]=nom;
        
    }

    for(int i=0; i<cantidad; i++){
        cout<<nombres[i]<<endl;
    }

    delete [] nombres;
    
    /*cout<<sizeof(nombres)<<endl;
    cout<<sizeof(nombres[0])<<endl;
    cout<<(sizeof(nombres[0]))/(sizeof(nombres));*/
}