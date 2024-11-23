#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct tRegistro {
    int id;
    char descripcion[50];
    float precio;
};

const int NUM_REGISTROS = 4;

int main() {
    // Crear archivo binario con std::ofstream.
    ofstream archivo("bd.dat", ios::binary);
    if (!archivo) {
        cerr << "Error: No se pudo crear el archivo 'bd.dat'." << endl;
        return 1;
    }

    // Datos de ejemplo para insertar en el archivo.
    tRegistro registros[NUM_REGISTROS] = {
        {12345, "Disco duro", 123.59},
        {32456, "Placa base core i7", 234.50},
        {2121, "Multipuerto USB", 15.00},
        {54354, "Disco externo 500 Gb", 97.80}
    };

    // Escribir los registros al archivo binario.
    for (int i = 0; i < NUM_REGISTROS; ++i) {
        archivo.write(reinterpret_cast<const char*>(&registros[i]), sizeof(tRegistro));
        if (!archivo) {
            cerr << "Error: No se pudo escribir el registro con ID " << registros[i].id << "." << endl;
            return 2;
        }
    }

    archivo.close(); // Se cierra el archivo automáticamente al salir del bloque.
    cout << "Archivo binario 'bd.dat' creado exitosamente con " << NUM_REGISTROS << " registros." << endl;

    return 0;
}

