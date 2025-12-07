#ifndef INDICE_HPP
#define INDICE_HPP

class Indice {
private:
    int legajo;
    long posicion;

public:
    Indice();
    Indice(int l, long p);

    int getLegajo() const;
    long getPosicion() const;

    void setLegajo(int l);
    void setPosicion(long p);
};

#endif
