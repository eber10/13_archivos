#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	string ruc, producto;
	int unidades;
	double precio;
	char aux;
	ofstream archivo;
	archivo.open("output.txt");
	cout<<"RUC del cliente (x para terminar):"; cin>>ruc;
	while(ruc !="x")
	{
		cin.get(aux);
		cout<<"producto:";
		getline(cin, producto);
		cout<<"unidades: ";
		cin>>unidades;
		cout<<"precio:";
		cin>>precio;
		archivo<<ruc<<" "<<unidades<<" "<<precio<<" "<<producto<<endl;
		cout<<" RUC del cliente (x para terminar): ";
		cin>>ruc;
		archivo<<"x";
	}
	archivo<<"x";
	archivo.close();
	return 0;
}

