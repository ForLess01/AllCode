#include <iostream>
#include <stdio.h>
#include "listaprod.h"
#include "listaprod.cpp"

using namespace std;

int main()
{
	int num=0, cont=0;
	Lista L;
	cout << "\nCuantos nodos va a insertar: " << endl;
	cin >> num;
	fflush(stdin);

	while(cont<num)
	{ ++cont;
        cout<<"\nIngreso de Nodo: ";
        L.insertarNodo();
	}
	cout << "\nEl contenido de la lista es: " << endl;
	L.imprimeLista();
	cout << "\nEl numero de nodos es " << L.cuentaNodos();
	char prod[20];
	cout << "\nQue producto desea borrar? ";
	gets(prod);
	L.eliminarNodo(prod);
	cout << "\nEl contenido de la lista es :" << endl;
	L.imprimeLista();
	cout << "Ingreso de un Nodo al final: ";
	L.insertarNodoFin();
	cout << "\nEl contenido de la lista es:" << endl;
	L.imprimeLista();

	return 0;
}
