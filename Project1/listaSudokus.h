#ifndef LISTASUDOKUS_H
#define LISTASUDOKUS_H

#include"juego.h"

#include<string>
#include<iostream>
#include<iomanip>


const int MAX_SUDOKUS = 20;


typedef tSudoku tInformacionSudoku[MAX_SUDOKUS];

typedef struct {
	tInformacionSudoku sudoku;
	int cont;
}tListaSudokus;


void crearListaVacia(tListaSudokus & lista);
bool cargar(tListaSudokus &lista);
void mostrar(const tListaSudokus & lista);


bool cargarSudoku(const tListaSudokus & lista, tSudoku &sudoku);


//Version2

bool guardar(const tListaSudokus & lista);
bool registrarSudoku(tListaSudokus & lista);
bool buscarFichero(tListaSudokus & lista, std::string nombreFich);
int buscarPos(const tListaSudokus & lista, const tSudoku & sudoku);
bool moverLista(tListaSudokus & lista, tSudoku sudoku);


bool operator <(tSudoku izda, tSudoku dcha);

#endif
