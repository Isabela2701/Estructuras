#ifndef CLASES_H
#define CLASES_H

#include <cstddef> // para size_t

class CLASES{
    private:
    int x;
    float y;
    double z;
    char letra;
    long int grande;
    short int pequeno;

    public:
    CLASES();
    CLASES(int x, float y, double z, char letra, long int grande, short int pequeno);
    void setX(int X);
    void setY(float Y);
    void setZ(double Z);
    void setLetra(char Letra);
    void setGrande(long int Grande);
    void setPequeno(short int Pequeno);
    int getX(void);
    float getY(void);   
    double getZ(void);
    char getLetra(void);
    long int getGrande(void);
    short int getPequeno(void);     

    void tamanoClase(void);
   
};
 
template<typename T>
    size_t getSize(T dato)
    {
        return sizeof(dato);
    }

#include "CLASES.CPP"
#endif // CLASES_H