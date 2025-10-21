#include "CLASES.H"
#include <iostream> 
using namespace std;

CLASES::CLASES() {
   x=0;
   y=0.0f;
   z=0.0;
   letra='a';
   grande=0;
   pequeno=0;
}

CLASES::CLASES(int X, float Y, double Z, char Letra, long int Grande, short int Pequeno) {
   x=X;
   y=Y;
   z=Z;
   letra=Letra;
   grande=Grande;
   pequeno=Pequeno;
}

void CLASES::setX(int X) { x=X; }
void CLASES::setY(float Y) { y=Y; }
void CLASES::setZ(double Z) { z=Z; }
void CLASES::setLetra(char Letra) { letra=Letra; }
void CLASES::setGrande(long int Grande) { grande=Grande; }
void CLASES::setPequeno(short int Pequeno) { pequeno=Pequeno; }
int CLASES::getX(void) { return x; }
float CLASES::getY(void) { return y; }
double CLASES::getZ(void) { return z; }
char CLASES::getLetra(void) { return letra; }
long int CLASES::getGrande(void) { return grande; }
short int CLASES::getPequeno(void) { return pequeno; }
void CLASES::tamanoClase(void)
{
   cout<<"Tamanio de int: "<<sizeof(x)<<" bytes"<<endl;
   cout<<"Tamanio de float: "<<sizeof(y)<<" bytes"<<endl;
   cout<<"Tamanio de double: "<<sizeof(z)<<" bytes"<<endl;
   cout<<"Tamanio de char: "<<sizeof(letra)<<" bytes"<<endl;
   cout<<"Tamanio de long int: "<<sizeof(grande)<<" bytes"<<endl;
   cout<<"Tamanio de short int: "<<sizeof(pequeno)<<" bytes"<<endl;

   cout<<"Suma de todos los tamanos: "<<sizeof(x)+sizeof(y)+sizeof(z)+sizeof(letra)+sizeof(grande)+sizeof(pequeno)<<" bytes"<<endl;
   cout<<"Tamanio total de objeto: "<<sizeof(*this)<<" bytes"<<endl;
}