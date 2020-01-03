
#ifndef NODO_H
#define NODO_H

class Nodo {
public:
    Nodo(int v,int f, int c, Nodo *s = 0);
    Nodo *siguiente ;
    int valor ;
    int fila;
    int columna;
};
#endif /* NODO_H */