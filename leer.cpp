#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
int main()
{
    const int IGV=21;
    string ruc, producto;
    int unidades;
    double precio, neto, total, igv;
    char aux;
    ifstream archivo;
    int contador=0;
    archivo.open("compras.txt");
    if(archivo.is_open())
    {
        archivo>>ruc;
        while(ruc!="x")
        {
            archivo>>unidades>>precio;
            archivo.get(aux);
            getline(archivo, producto);
            contador++;
            neto=unidades*precio;
            igv=neto*IGV/100;
            total=neto+igv;
            cout<<"compra"<<contador<<".-"<<endl;
            cout<<"  "<<producto<<": "<<unidades<<" x "<<fixed<<setprecision(2)<<precio<<" = "<<neto<<" -I.G.V.:"<<igv<<"- total: "<<total<<endl;
            archivo>>ruc; 
        }
        archivo.close();
    }
    else
    {
        cout<<"error no se ha podido abrir el archivo"<<endl;
    }
    return 0;
}
