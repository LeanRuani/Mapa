
#ifndef MAPA_H
#define	MAPA_H
#include "Matriz.h"
#include "Lista.h"

class Mapa {
public:
    Mapa();
    void generarMapa(int f, int c);
    void mostrarMapa();
    void recorreMapa();
    void mostrarLista();

private:
    void cuentaSuperficie(int f, int c);
    void cambiaSuperficie(int f, int c, int num);
    Matriz m;
    int filas;
    int columnas;
    Lista l;
};

#endif	/* MAPA_H */
