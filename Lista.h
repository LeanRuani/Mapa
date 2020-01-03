#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
class Lista {
public:
    Lista();
    void NuevoNodo(int v,int f, int c);
    void Mostrar();
    void EliminarNodos(); 
    void Ordenar();
    Nodo *obtenerPrimero();
private:
    bool ListaVacia();
    Nodo *primero;
    Nodo *actual;
    void EliminarNodo(Nodo *nodo); 
};

#endif /* LISTA_H */



