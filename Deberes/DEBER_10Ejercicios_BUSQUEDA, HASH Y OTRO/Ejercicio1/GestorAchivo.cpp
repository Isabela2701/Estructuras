#include "GestorArchivo.hpp"
#include <iostream>
#include <cstring>

GestorArchivo::GestorArchivo(const char* nombre) {
    int n = strlen(nombre);
    archivo = (char*) malloc(n + 1);
    for (int i = 0; i < n; i++) *(archivo + i) = *(nombre + i);
    *(archivo + n) = '\0';

    indice = nullptr;
    cantidad = 0;
}

GestorArchivo::~GestorArchivo() {
    if (archivo) free(archivo);
    if (indice) free(indice);
}

char* GestorArchivo::leerLinea() {
    int cap = 16;
    char* buf = (char*) malloc(cap);
    int usados = 0;

    int c = std::cin.peek();
    if (c == '\n') std::cin.get();

    while (true) {
        int cc = std::cin.get();
        if (cc == '\n' || cc == EOF) break;

        if (usados + 1 >= cap) {
            cap *= 2;
            buf = (char*) realloc(buf, cap);
        }

        *(buf + usados) = cc;
        usados++;
    }

    *(buf + usados) = '\0';
    return buf;
}

void GestorArchivo::agregarAlumno() {
    std::ofstream out(archivo, std::ios::binary | std::ios::app);
    if (!out) {
        std::cout << "Error creando archivo.\n";
        return;
    }

    int leg;
    std::cout << "Legajo: ";
    std::cin >> leg;

    std::cout << "Nombre: ";
    char* nom = leerLinea();

    std::cout << "Carrera: ";
    char* car = leerLinea();

    long pos = out.tellp();

    int ln = strlen(nom);
    int lc = strlen(car);

    out.write((char*)&leg, sizeof(int));
    out.write((char*)&ln, sizeof(int));
    out.write(nom, ln);
    out.write((char*)&lc, sizeof(int));
    out.write(car, lc);

    free(nom);
    free(car);

    out.close();

    std::cout << "Alumno agregado.\n";
}

void GestorArchivo::cargarIndice() {
    std::ifstream in(archivo, std::ios::binary);
    if (!in) {
        std::cout << "Archivo inexistente. Se generará al agregar alumnos.\n";
        return;
    }

    cantidad = 0;
    int leg, ln, lc;

    while (true) {
        in.read((char*)&leg, sizeof(int));
        if (in.eof()) break;
        in.read((char*)&ln, sizeof(int));
        in.seekg(ln, std::ios::cur);
        in.read((char*)&lc, sizeof(int));
        in.seekg(lc, std::ios::cur);
        cantidad++;
    }

    in.clear();
    in.seekg(0);

    if (indice) free(indice);
    indice = (Indice*) malloc(sizeof(Indice) * cantidad);

    for (int i = 0; i < cantidad; i++) {
        long pos = in.tellg();
        in.read((char*)&leg, sizeof(int));
        in.read((char*)&ln, sizeof(int));
        in.seekg(ln, std::ios::cur);
        in.read((char*)&lc, sizeof(int));
        in.seekg(lc, std::ios::cur);

        (indice + i)->setLegajo(leg);
        (indice + i)->setPosicion(pos);
    }

    ordenarIndice();

    std::cout << "Índice cargado con " << cantidad << " registros.\n";
}

void GestorArchivo::ordenarIndice() {
    for (int i = 1; i < cantidad; i++) {
        Indice key = *(indice + i);
        int j = i - 1;

        while (j >= 0 && (indice + j)->getLegajo() > key.getLegajo()) {
            *(indice + j + 1) = *(indice + j);
            j--;
        }
        *(indice + j + 1) = key;
    }
}

int GestorArchivo::busquedaBinaria(int clave) {
    int ini = 0, fin = cantidad - 1;
    while (ini <= fin) {
        int mid = (ini + fin) / 2;
        int l = (indice + mid)->getLegajo();
        if (l == clave) return mid;
        if (clave < l) fin = mid - 1;
        else ini = mid + 1;
    }
    return -1;
}

void GestorArchivo::mostrarIndice() {
    if (cantidad == 0) {
        std::cout << "Índice vacío.\n";
        return;
    }

    for (int i = 0; i < cantidad; i++)
        std::cout << (indice + i)->getLegajo() << " -> " 
                  << (indice + i)->getPosicion() << "\n";
}

void GestorArchivo::buscar() {
    if (cantidad == 0) {
        std::cout << "Cargue el índice primero.\n";
        return;
    }

    int leg;
    std::cout << "Ingrese legajo a buscar: ";
    std::cin >> leg;

    int pos = busquedaBinaria(leg);
    if (pos < 0) {
        std::cout << "No encontrado.\n";
        return;
    }

    std::ifstream in(archivo, std::ios::binary);
    in.seekg((indice + pos)->getPosicion());

    int ln, lc;
    int legajo;
    in.read((char*)&legajo, sizeof(int));
    in.read((char*)&ln, sizeof(int));

    char* nom = (char*) malloc(ln + 1);
    for (int i = 0; i < ln; i++) *(nom + i) = in.get();
    *(nom + ln) = '\0';

    in.read((char*)&lc, sizeof(int));
    char* car = (char*) malloc(lc + 1);
    for (int i = 0; i < lc; i++) *(car + i) = in.get();
    *(car + lc) = '\0';

    Alumno a(legajo, nom, car);
    a.mostrar();

    free(nom);
    free(car);
}
