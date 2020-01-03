
#include <stdlib.h>
#include <Time.h>
#include "Matriz.h"

Matriz::Matriz() {
}
void Matriz::generaMatriz(int f, int c){
    filas = f;
    columnas = c;
    mat = new int *[filas];
    for(int f = 0; f < filas ; f++){
      mat[f] = new int[columnas];
    }
}
void Matriz::cargarMatriz(){
    srand(time(NULL)); 
    for (int f = 0; f < filas; f++){
        for (int c = 0; c < columnas; c++){
            mat[f][c]= rand()% 2;
        }
    }
}
int Matriz::obtenerNumero(int f, int c){
    return (mat[f][c]); 
}
void Matriz::cambiarNumero(int f, int c, int num){
    mat[f][c] = num;
}
int Matriz::obtenerCantFilas(){
   return (filas); 
}
int Matriz::obtenerCantColumnas(){
   return (columnas); 
}