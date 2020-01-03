#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include "Mapa.h"
using namespace std;

Mapa::Mapa() {
}

void Mapa::generarMapa(int f, int c){
    m.generaMatriz(f,c);
    m.cargarMatriz();
    mostrarMapa();
    l.EliminarNodos();
}

void Mapa::mostrarMapa(){
    filas = m.obtenerCantFilas();
    columnas = m.obtenerCantColumnas();
    for (int f = 0; f < filas ; f++){
        for (int c = 0; c < columnas ; c++){
            cout<< m.obtenerNumero(f,c)<< " "; 
        }
            cout<< endl;
    }
}

int cont = 0;
void Mapa::recorreMapa(){
    for (int f = 0; f < filas ; f++){
        for (int c = 0; c < columnas ; c++){
            if(m.obtenerNumero(f,c) == 1 ){
                cont++;
                cuentaSuperficie(f,c);
                m.cambiarNumero(f,c, cont);
                cont = 0;
            }
            if(m.obtenerNumero(f,c) != 0 ){
                l.NuevoNodo(m.obtenerNumero(f,c), f,c);
            }
        }
    }
    mostrarMapa();
}
void Mapa::mostrarLista(){
    l.Ordenar();
    l.Mostrar();
}

void Mapa::cuentaSuperficie(int f, int c){
    if(c != columnas -1  && m.obtenerNumero(f,c+1)== 1){ // pregunta por superficie derecha
        cont++;
        m.cambiarNumero(f,c, 2);
        cuentaSuperficie(f,c+1);

    }if(f != filas -1 &&(m.obtenerNumero(f+1,c)== 1)){ // pregunta por superficie inferior
        cont++;
        m.cambiarNumero(f,c, 2);
        cuentaSuperficie(f+1,c);

    }if(c != 0 && (m.obtenerNumero(f,c-1)== 1)){ // pregunta por superficie izquierda
        cont++;
        m.cambiarNumero(f,c, 2);
        cuentaSuperficie(f,c-1);

    }if(f != 0 && (m.obtenerNumero(f-1,c)== 1)){ // pregunta por superficie superior
        cont++;
        m.cambiarNumero(f,c, 2);
        cuentaSuperficie(f-1,c);
    }
    m.cambiarNumero(f,c, cont);
    cambiaSuperficie(f,c,cont);// esta funcion hace que todas las tierras que forman una superficie tengan el numero que identifique esa superficie(en este caso la cantidad de tierras que lo forman
}

void Mapa::cambiaSuperficie(int f, int c, int num){
    if(c != columnas -1  && m.obtenerNumero(f,c+1)!= 0 && m.obtenerNumero(f,c+1)!= 1 && m.obtenerNumero(f,c+1)!= num){ // pregunta por superficie derecha
        m.cambiarNumero(f,c+1, num);
        cambiaSuperficie(f,c+1,num);

    }if(f != filas -1 && m.obtenerNumero(f+1,c)!= 0 && m.obtenerNumero(f+1,c)!= 1 && m.obtenerNumero(f+1,c)!= num){ // pregunta por superficie inferior
        m.cambiarNumero(f+1,c, num);
        cambiaSuperficie(f+1,c,num);

    }if(c != 0 && m.obtenerNumero(f,c-1)!= 0 && m.obtenerNumero(f,c-1)!= 1 && m.obtenerNumero(f,c-1)!= num){ // pregunta por superficie izquierda
        m.cambiarNumero(f,c-1, num);
        cambiaSuperficie(f,c-1,num);

    }if(f != 0 && m.obtenerNumero(f-1,c)!= 0 && m.obtenerNumero(f-1,c)!= 1 && m.obtenerNumero(f-1,c)!= num){ // pregunta por superficie superior
        m.cambiarNumero(f-1,c,num);
        cambiaSuperficie(f-1,c,num);
    }
}