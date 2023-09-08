//archivo listaprod.h
//enuncuado de la clase lista enlazada para productos.

#ifndef LISTAPROD_H
#define LISTAPROD_H

// declaracion de la estructura Nodo
struct Nodo
{
    char producto[20];
    float precio;
    struct Nodo *sig; //es recursiva
};
class Lista
{
    Nodo *primero; //Nodo distinguido puntero al primer nodo de la lista.
    public:
    Lista();
    ~Lista();
    void insertarNodo(); //insertar al comienzo
    void eliminarNodo(char prod[]);
    void imprimeLista();
    bool listaVacia();
    int cuentaNodos();
    void insertarNodoFin();
};

#endif //LISTAPROD_H