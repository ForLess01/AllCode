#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int NUMNODOS=10;
const int INFINITO=-32768;

struct tipoNodo
{
      int info, sig;
};
tipoNodo nodos[NUMNODOS];// Lista como array de nodos
//funciones prototipo
void iniciarLista(tipoNodo nodos[]);
int obtenerNodo();
void liberarNodo(int p);
void insertarNodo(int x);
//variables globales
int i, disponible = NUMNODOS;
int bottom = NUMNODOS - 1;

int main(){
// TAD_Lista_Array	.cpp
    int x ;
    iniciarLista(nodos);
    //mostrando el array lista creado
    cout << "\nLa lista creada es:" << endl;
    cout << "indice\t\tinfo\tsig" << endl;
    for(i = 0;i < NUMNODOS; i++)
        cout << "Indice" << i << ":\t" << nodos[i].info << "\t" << nodos[i].sig << "\t" << endl;
    cout << endl << "Presione una tecla para continuar...";
        getchar();
    //insertando 15, 17, 1, 30, 49, 50,8 en el array lista
    // posicion inicial de la lista

    x=15;       insertarNodo(x);         x=17;   insertarNodo(x);
    x=10;       insertarNodo(x);         x=30;   insertarNodo(x);
    x=49;		insertarNodo(x);         x=50;   insertarNodo(x);
    x=80;		insertarNodo(x);         x=99;   insertarNodo(x);
    x=55;		insertarNodo(x);         x=88;   insertarNodo(x);

    //mostrando la lista actual
    cout << "\nLa lista es actual es:" << endl;
    for(i = 0; i < NUMNODOS; i++)
      cout << "Indice" << i << ":\t" << nodos[i].info << "\t" << nodos[i].sig << "\t" << endl;
    cout << endl << "Presione una tecla para continuar...";
    getchar();

    //Probando una nueva insercion
    insertarNodo(100);
    cout << "\nLa lista la nueva actual es:" << endl;
    for(i = 0;i < NUMNODOS; i++)
      cout << "Indice" << i << ":\t" << nodos[i].info << "\t" << nodos[i].sig << "\t" << endl;
    cout << "\nPresione una tecla para finalizar...";
    return 0;
}
void iniciarLista(tipoNodo nodos[])
{
    //creacion del array lista
    for(i=0;i<	NUMNODOS;i++)
    {
        nodos[i].sig = i+1;
        nodos[i].info=INFINITO;
    }
    nodos[NUMNODOS - 1].sig=-1;	// uItimo elemento
}
int obtenerNodo()
{
    int p=0;
    if (!disponible)
    {
        return -1;
    }
    --disponible;
    while(nodos[p].info != INFINITO)
    p++;
    return (p);
}
void liberarNodo(int p)
{
    nodos[p].info = INFINITO;
    nodos[p].sig = -1;
    bottom = p;
    ++disponible;
}

void insertarNodo(int x)
{
    int q;
    q = obtenerNodo();
    if(q == -1)
        {
            cout << "Insercion no efectuada...!" << endl;
            return;
        }
    nodos[q].info = x; //almacenar dato


}