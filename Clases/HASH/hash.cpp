#include <iostream>
#include <string>
#include <cstdlib> // Necesario para malloc y free

using namespace std;

// Estructura para almacenar los datos de una persona y el puntero para el encadenamiento
struct Persona {
    string nombre;
    string apellido;
    string cedula;
    Persona* siguiente;

    Persona(string n, string a, string c) : nombre(n), apellido(a), cedula(c), siguiente(nullptr) {}
};

// Clase para la Tabla Hash
class TablaHash {
private:
    // Arreglo de punteros a Persona (nuestra tabla)
    Persona** tabla;
    int TAMANIO; // Tamaño de la tabla

    // Función Hash: convierte la cédula en un índice de la tabla
    int funcionHash(const string& cedula) {
        MD5 md5;
        unsigned char hash_char[16];
        md5.add(cedula.c_str(), cedula.length());
        md5.getHash(hash_char);

        // Tomamos los primeros 8 bytes del hash MD5 de 16 bytes y los convertimos a un número
        unsigned long long hash_numerico = *((unsigned long long*)hash_char);
        
        return hash_numerico % TAMANIO;
    }

public:
    // Constructor: inicializa la tabla
    TablaHash(int size) {
        this->TAMANIO = size;
        // Crea un arreglo de punteros a Persona y los inicializa a nullptr
        tabla = (Persona**)malloc(TAMANIO * sizeof(Persona*));
        for (int i = 0; i < TAMANIO; i++) {
            *(tabla + i) = nullptr;
        }
    }

    // Destructor: libera la memoria
    ~TablaHash() {
        for (int i = 0; i < TAMANIO; i++) {
            Persona* actual = *(tabla + i);
            while (actual != nullptr) {
                Persona* aBorrar = actual;
                actual = actual->siguiente;
                aBorrar->~Persona(); // Llama al destructor explícitamente por los std::string
                free(aBorrar);       // Libera la memoria de malloc
            }
        }
        free(tabla);
    }

    // Método para insertar un elemento en la tabla hash
    void insertar(const string& nombre, const string& apellido, const string& cedula) {
        int indice = funcionHash(cedula);
        
        cout << "-> Cedula '" << cedula << "' se inserta en el indice: " << indice << endl;
        
        // Reserva memoria con malloc y luego usa "placement new" para llamar al constructor
        void* mem = malloc(sizeof(Persona));
        Persona* nuevaPersona = new (mem) Persona(nombre, apellido, cedula);

        // Inserta al inicio de la lista enlazada (encadenamiento)
        if (*(tabla + indice) == nullptr) {
            *(tabla + indice) = nuevaPersona;
        } else {
            nuevaPersona->siguiente = *(tabla + indice);
            *(tabla + indice) = nuevaPersona;
        }
    }

    // Método para mostrar el contenido de la tabla hash
    void mostrarTabla() {
        cout << "\n--- Contenido de la Tabla Hash ---" << endl;
        for (int i = 0; i < TAMANIO; i++) {
            cout << "Indice " << i << ": ";
            Persona* actual = *(tabla + i);
            if (actual == nullptr) {
                cout << "[]" << endl;
            } else {
                while (actual != nullptr) {
                    cout << "[Cedula: " << actual->cedula << ", Nombre: " << actual->nombre << " " << actual->apellido << "] -> ";
                    actual = actual->siguiente;
                }
                cout << "NULL" << endl;
            }
        }
    }
};

int main() {
    int tamanioTabla;
    cout << "Ingrese el tamanio de la tabla hash: ";
    cin >> tamanioTabla;
    cin.ignore(); // Limpia el buffer de entrada

    if (tamanioTabla <= 0) {
        cout << "El tamanio debe ser un numero positivo." << endl;
        return 1;
    }

    TablaHash miTablaHash(tamanioTabla);

    char continuar = 's';
    while (continuar == 's' || continuar == 'S') {
        string nombre, apellido, cedula;

        cout << "\nIngrese el nombre: ";
        getline(cin, nombre);
        cout << "Ingrese el apellido: ";
        getline(cin, apellido);
        cout << "Ingrese la cedula: ";
        getline(cin, cedula);

        miTablaHash.insertar(nombre, apellido, cedula);

        cout << "\nDesea ingresar otra persona? (s/n): ";
        cin >> continuar;
        cin.ignore(); // Limpia el buffer de entrada
    }

    miTablaHash.mostrarTabla();

    return 0;
}
