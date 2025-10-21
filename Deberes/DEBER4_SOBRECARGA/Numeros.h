#ifndef NUMEROS_H
#define NUMEROS_H

class Numeros {
private:
    double valor;

public:
    // Constructor
    Numeros(double v = 0);

    // Setter
    void setValor(double v);

    // Getter
    double getValor();

    // Métodos para ingresar y sumar tres números
    void ingresarYSumarInt();
    void ingresarYSumarFloat();
    void ingresarYSumarDouble();
    void ingresarYSumarMixto(); // int, float, double
};

#endif