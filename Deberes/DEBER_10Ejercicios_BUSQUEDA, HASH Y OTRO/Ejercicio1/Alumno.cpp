#include "Alumno.hpp"

void Alumno::copiarCadena(char*& destino, const char* origen) {
    if (destino != nullptr) free(destino);

    if (origen == nullptr) {
        destino = nullptr;
        return;
    }

    int len = std::strlen(origen);
    destino = (char*) malloc(len + 1);
    char* pd = destino;
    const char* po = origen;
    for (int i = 0; i < len; i++) {
        *(pd + i) = *(po + i);
    }
    *(pd + len) = '\0';
}

Alumno::Alumno() {
    legajo = 0;
    nombre = nullptr;
    carrera = nullptr;
}

Alumno::Alumno(int leg, const char* nom, const char* car) {
    legajo = leg;
    nombre = nullptr;
    carrera = nullptr;
    setNombre(nom);
    setCarrera(car);
}

Alumno::~Alumno() {
    if (nombre != nullptr) free(nombre);
    if (carrera != nullptr) free(carrera);
}

int Alumno::getLegajo() const { return legajo; }
const char* Alumno::getNombre() const { return nombre; }
const char* Alumno::getCarrera() const { return carrera; }

void Alumno::setLegajo(int l) { legajo = l; }
void Alumno::setNombre(const char* nom) { copiarCadena(nombre, nom); }
void Alumno::setCarrera(const char* car) { copiarCadena(carrera, car); }

void Alumno::mostrar() const {
    std::cout << "Legajo: " << legajo << " | Nombre: " << (nombre ? nombre : "(vac)") 
              << " | Carrera: " << (carrera ? carrera : "(vac)") << std::endl;
}
