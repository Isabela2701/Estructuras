#include <iostream>
#include <string>

using namespace std;

int main(){

    string Nombres[5]={"Juan","Maria", "Felipe", "Santiago","Jose"};
    int num[4]={3, 4,2 ,5};

    for(int i=0; i<5; i++){
        cout<<Nombres[i]<<endl;
    }

    Nombres[1]="Paula";
    
    for(string nombres: Nombres){
        cout<<nombres<<endl;
    }

    for(int numeros: num){
        cout<<numeros<<endl;
    }

}