#include "Indice.hpp"

Indice::Indice() {
    legajo = 0;
    posicion = 0;
}

Indice::Indice(int l, long p) {
    legajo = l;
    posicion = p;
}

int Indice::getLegajo() const { return legajo; }
long Indice::getPosicion() const { return posicion; }
void Indice::setLegajo(int l) { legajo = l; }
void Indice::setPosicion(long p) { posicion = p; }
