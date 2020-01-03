
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include "Mapa.h"
#include "Matriz.h"

using namespace std;

int main(int argc, char** argv) {
    int cont = 0;  
    int x;
    Mapa mapa;

    do{
        cout<< " 1-Crear Mapa"<<endl;
        cout<< " 2-Contar Superficies"<<endl;
        cout<< " 3-Mostrar Lista"<<endl; 
        cout<< " 4=Salir"<<endl; 
        cin>> x;
        cout<< endl;
        
        switch (x){
            case 1:{
                int num = 0;
                int filas;
                int columnas;
                cout<<"Ingrese el numero de filas"<< endl;
                cin>>filas;
                cout<<"Ingrese el numero de columnas"<< endl;
                cin>>columnas;
                mapa.generarMapa(filas,columnas);
                
                break;
            }
            case 2:{
                mapa.recorreMapa();
                
                break;
            }
            case 3:{
                mapa.mostrarLista();
                
                break;
            }
        }
    }while(x!=4);
    return(0); 
}

