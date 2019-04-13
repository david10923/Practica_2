#ifndef JUEGO_H
#define JUEGO_H

#include<string>
#include"tablero.h"


typedef struct {
	int puntos;
	std::string nombreArchivo;
}tSudoku;

typedef struct {
	tSudoku sudoku;
	tTablero tablero;
	bool lleno;
}tJuego;


void inicializaJuego(tJuego & juego, const tSudoku & sudoku);
void mostrarJuego(const tJuego & juego);
bool cargaJuego(tJuego & juego, const tSudoku & sudoku);
int jugarUnSudoku(tJuego & juego);
int menu2();

#endif
