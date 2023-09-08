#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include"listaprod.h"

using namespace std;

Lista::Lista(){
	primero = NULL;
}
Lista::~Lista(){
	Nodo *p;
	Nodo *temp;
	p = primero;
	while (p!=NULL)
    {
		temp = p -> sig;
		delete p;
		p = temp;
	}
}
void Lista::insertarNodo()
{
	char nom[20];
	fflush(stdin);
	cout << "\nIngrese nombre del producto: ";  gets(nom);
	fflush(stdin);
	float pre;
	cout << "\nIngrese precio: ";   cin >> pre;
	fflush(stdin);
	Nodo *p;
	p = new Nodo;
	strcpy(p->producto, nom);
	p -> precio = pre;
	p -> sig=primero;
	primero = p;
}
void Lista::eliminarNodo(char prod[]){
	bool encuentra = false;
	Nodo *p;
	Nodo *antP;
	p = primero;
	antP = NULL;
	
	if(listaVacia())
		cout << "\nLista vacia no hay nodo a eliminar" << endl;
	else
    {
		while(!encuentra && p != NULL){
			if(strcmp( p -> producto, prod) == 0)
				encuentra = true;
			else
            {
				antP = p;
				p = p -> sig;
			}
			if(encuentra)
            {
				if(antP==NULL){
					primero = p -> sig;
					delete p;
				}
				else{
					antP -> sig = p -> sig;
					delete p;
				}
			}
			else
				cout << "\nEl producto " << prod << " no esta en la lista!" << endl;
		}
	}
}
void Lista::imprimeLista()
{
	Nodo *p;
	p = primero;
	if(!listaVacia())
    {
		while(p != NULL)
        {
			cout << p->producto << " s/." << p->precio << " -> ";
			p = p -> sig;
		}
		cout << "NULO" << endl;
	}
	else
		cout << "\nLa lista esta vacia...!" << endl;
}
bool Lista::listaVacia()
{
	if(primero == NULL)
		return true;
	else
		return false;
}
int Lista::cuentaNodos()
{
	int cont = 0;
	Nodo *p;
	p = primero;
	if(!listaVacia())
    {
		while(p != NULL)
        {
			p = p -> sig;
			cont++;
		}
		return cont;
	}
	else
		return 0;
}
void Lista::insertarNodoFin()
{
	Nodo *p;
	p = primero;
	if(!listaVacia())
    {
		while(p -> sig != NULL)
			p = p -> sig;
	}
	char nom[20];
	fflush(stdin);
	cout << "\nIngrese nombre del producto: ";
	gets(nom);
	fflush(stdin);
	float pre;
	cout << "Ingrese precio: ";
	cin >> pre;
	fflush(stdin);
	
	Nodo *q;
	q = new Nodo;
	strcpy(q -> producto, nom);
	q -> precio = pre;
	q -> sig = NULL;
	if(p == NULL)
		primero = q;
	else
		p -> sig = q;
}