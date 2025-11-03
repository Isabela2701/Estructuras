#include <iostream>
using namespace std;

  class Empleado{
        private:
            int salario;
            string nombre;
            int edad;
            int numerodeHoras;
        public:
            Empleado(string nom, int sal, int ed, int numHoras){
                cout<<"Constructor con parametros"<<endl;
                salario=sal;
                nombre=nom;
                edad=ed;
                numerodeHoras=numHoras;   
            }
            Empleado(){
                cout<<"Constructor por defecto"<<endl;
            }
            int getSalario(){
                return salario;
            }
            string getNombre(){
                return nombre;
            }
            int getEdad();
            long getNumerodeHoras();

            void setSalario(int sal){
                salario=sal;
            }
            void setNombre(string Nombre){
                nombre=Nombre;
            }
            void setEdad(int Edad){
                edad=Edad;
            }
            void setNumerodeHoras(long Numerodehoras);
    };

int main(){

    Empleado emp1 ("Juan",28 , 3000, 440);
    Empleado emp2;

    /*emp1.setNombre("Juan");
    emp1.setSalario(3000);
    emp1.setEdad(28);
    emp1.setNumerodeHoras(440);

    emp2.setNombre("Manuel");
    emp2.setSalario(2000);
    emp2.setEdad(28);
    emp2.setNumerodeHoras(690);*/

    cout<<"Nombre:"<<emp1.getNombre()<<endl;
    cout<<"Edad:"<<emp1.getEdad()<<endl;
    cout<<"Salario: "<<emp1.getSalario()<<endl;
    cout<<"Numero de horas: "<<emp1.getNumerodeHoras()<<endl;

    /*cout<<"Nombre:"<<emp2.getNombre()<<endl;
    cout<<"Edad:"<<emp2.getEdad()<<endl;
    cout<<"Salario: "<<emp2.getSalario()<<endl;
    cout<<"Numero de horas: "<<emp2.getNumerodeHoras()<<endl;*/
    
    /*emp1.salario=3000;
    emp1.nombre="Juan";
    emp1.edad=28;

    emp2.salario=2000;
    emp2.nombre="Manuel";
    emp2.edad=34;

    cout<<"Nombre:"<<emp1.nombre<<endl;
    cout<<"Salario:"<<emp1.salario<<endl;
    cout<<"Edad:"<<emp1.edad<<endl;

    cout<<"Nombre:"<<emp2.nombre<<endl;
    cout<<"Salario:"<<emp2.salario<<endl;
    cout<<"Edad:"<<emp2.edad<<endl;*/


  
}
 int Empleado::getEdad(){

    return edad;

 }

 long Empleado::getNumerodeHoras(){
    return numerodeHoras;
 }

 void Empleado::setNumerodeHoras(long NumerodeHoras){
    numerodeHoras=NumerodeHoras;
 }