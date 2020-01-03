
#ifndef MATRIZ_H
#define	MATRIZ_H
class Matriz {
public:
	Matriz();
        void generaMatriz(int f, int c);
        void cargarMatriz();
        int obtenerNumero(int f, int c);
        int obtenerCantFilas();
        int obtenerCantColumnas();
        void cambiarNumero(int f, int c, int num);
private:
        int filas; 
        int columnas;
        int **mat;
};

#endif