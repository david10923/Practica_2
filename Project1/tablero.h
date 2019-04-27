#ifndef TABLERO_H
#define TABLERO_H


#include "casilla.h"
#include<string>

const int DIM = 9;
typedef tCasilla tTablero[DIM][DIM];

void iniciaTablero(tTablero tablero);
bool cargarTablero(std::string nombreFichero, tTablero& tablero);
void dibujarTablero(const tTablero & tablero);
bool ponerNum(tTablero & tablero, int fila, int col, int c);
bool borrarNum(tTablero & tablero, int fila, int col);
bool tableroLLeno(const tTablero & tablero);
void mostrarPosibles(const tTablero & tablero, int fila, int col);
void rellenarSimples(tTablero& tablero);

//void actualizaTablero(tTablero & tablero, int numero);
//void indicaRegion(const tTablero & tablero, int fila , int columna);
void actualizaRegion(tTablero & tablero, int row, int col, int numero);
void actualizaFilaCol(tTablero & tablero, int fila, int col, int numero);
void actualizaRegionBorraNum(tTablero & tablero, int row, int col, int numero);
void actualizaFilaColBorraNum(tTablero & tablero, int fila, int col, int numero);// actualiza el valor de la fila y de la columna borrando  el numero de la fila y de la columna 
bool cuidadoBorraNumFila(tTablero & tablero , int fila, int col,int numero);
bool cuidadoBorraNumCol(tTablero & tablero, int fila, int col, int numero);
bool cuidadoBorraNumRegion(tTablero & tablero, int fila, int col, int numero);




#endif
