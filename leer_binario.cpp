#include <iostream>
#include <fstream>

using namespace std;

struct tRegistro {
    int id;
    char descripcion[50];
    float precio;
};

int main() {
    ifstream archivo("bd.dat", ios::binary);
    if (!archivo) {
        cerr << "Error: No se pudo abrir el archivo 'bd.dat'." << endl;
        return 1;
    }

    tRegistro registro;

    cout << "Contenido del archivo 'bd.dat':" << endl;
    cout << "-----------------------------------" << endl;

    while (archivo.read(reinterpret_cast<char*>(&registro), sizeof(tRegistro))) {
        cout << "ID: " << registro.id << endl;
        cout << "Descripción: " << registro.descripcion << endl;
        cout << "Precio: " << registro.precio << endl;
        cout << "-----------------------------------" << endl;
    }

    archivo.close();
    return 0;
}

