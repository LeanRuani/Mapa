#include "Lista.h"
#include "Nodo.h"
#include <iostream>
using namespace std;

Lista::Lista() {
    primero = NULL;   
    actual = NULL; 
}
bool Lista::ListaVacia(){
    return(primero == NULL); 
}
void Lista::NuevoNodo(int v, int f, int c){ 
    Nodo *n = new Nodo(v,f,c);
    if (ListaVacia()){
        primero = n;
    }else{ 
        actual->siguiente = n;
    }
    actual = n;
} 

void Lista::Mostrar(){ 
    Nodo *aux = primero;
    while(aux){
        int num = aux->valor;
        cout <<"Superficie: " << num <<" Coordenadas: " << aux->fila << "," << aux->columna;
        aux = aux->siguiente;
        if (aux){
            int num2 = aux->valor;
            if (num != 1){
                for (int x = 0; x < num2 - 1 ; x++){
                    cout<<";"<< aux->fila << "," << aux->columna;
                    aux = aux->siguiente;
                }
            }
        }
        cout<< endl;
    }
}
void Lista::EliminarNodos(){ 
    if (primero != NULL){
        this->EliminarNodo(primero); 
    }
}
void Lista::EliminarNodo(Nodo *nodo){ 
    Nodo *aux = nodo->siguiente;
    primero = aux;              
    if (aux != NULL){           
        delete nodo;            
        EliminarNodo(aux);      
    }else{                          
        delete nodo;            
    }                           
}
void Lista::Ordenar(){
    Nodo *aux = primero;
    Nodo *aux2 = primero->siguiente;
    bool swap = true;

    do{
        swap = false;
        while (aux2){
            if (aux->valor < aux2->valor ){
                int v = aux2->valor;
                int f = aux2->fila;
                int c = aux2->columna;

                aux2->valor = aux->valor;
                aux2->fila = aux->fila;
                aux2->columna = aux->columna;

                aux->valor = v;
                aux->fila = f;
                aux->columna = c;

                swap = true;
            }
            aux = aux->siguiente;
            aux2 = aux2->siguiente;
        } 
        aux = primero;
        aux2 = primero->siguiente;
        
    }while (swap);
    
}
Nodo * Lista::obtenerPrimero(){
    return(primero);
}

