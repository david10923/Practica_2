#ifndef CASILLA_H
#define CASILLA_H

#include "conjunto.h"
#include <Windows.h>

typedef enum tEstado { vacia, fija, rellenada };

typedef struct {
	tEstado estado;
	int numero;
	tConjunto conjunto;
} tCasilla;


void inicializaCasilla(tCasilla  & casilla);
void rellenaCasilla(tCasilla & casilla, char c, bool fijas = false);
void dibujaCasilla(const tCasilla & casilla);
bool esSimple(const tCasilla & casilla, int &numero);
void colorFondo(int color);

#endif


