#include"tablero.h"
#include<iostream>
#include<fstream>
using namespace std;




void actualizaRegion(tTablero & tablero, int row, int col, int numero) {

	int fila = row - row % 3;
	int columna = col - col % 3;


	for (int i = fila; i < fila + 3; i++) {
		for (int j = columna; j < columna + 3; j++) {

			//if (tablero[i][j].numero != numero);

				borraElemento(tablero[i][j].conjunto, numero);

			

		
		}
	}

}


void actualizaRegionBorraNum(tTablero & tablero, int row, int col, int numero) {

	int fila = row - row % 3;
	int columna = col - col % 3;

	for (int i = fila; i < fila + 3; i++) {
		for (int j = columna; j < columna + 3; j++) {
			
			if(!cuidadoBorraNumRegion(tablero,fila,col,numero)){
					annadeElemento(tablero[fila][j].conjunto, numero);
				
			}

			
		}
	}

}


void actualizaFilaCol(tTablero & tablero, int fila, int col, int numero) {
	int i = 0; int j = 0;

	while (j < DIM) {

		borraElemento(tablero[fila][j].conjunto, numero);
		j++;
	}


	while (i < DIM) {

		borraElemento(tablero[i][col].conjunto, numero);
		i++;
	}

}


void actualizaFilaColBorraNum(tTablero & tablero, int fila, int col, int numero) {

	int i = 0; int j = 0;	

	while (j < DIM) { // actualizas la fila 

		if(!cuidadoBorraNumFila(tablero, fila, col,numero)){
			if(!cuidadoBorraNumCol(tablero, fila, j, numero)) {
				annadeElemento(tablero[fila][j].conjunto, numero);
			}
		}

		j++;
	}

	while (i < DIM) { // actualizas la columna 

		if (!cuidadoBorraNumCol(tablero, fila, col,numero)) {
			if(!cuidadoBorraNumFila(tablero,i, col,numero)){
				annadeElemento(tablero[i][col].conjunto, numero);
			}

		}
		
		i++;
	}

	
}


void iniciaTablero(tTablero tablero) {

	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++) {
			inicializaCasilla(tablero[i][j]);
		}
	}
}


bool cargarTablero(string nombreFichero, tTablero& tablero) {

	iniciaTablero(tablero);


	ifstream archivo;
	bool ok = false;
	char c;

	archivo.open(nombreFichero);

	if (archivo.is_open()) {
		ok = true;

		for (int i = 0; i < DIM; i++) {
			for (int j = 0; j < DIM; j++) {
				archivo.get(c);

				if (c == '\n') { // hay que leer el salto de linea porque si no se descuadra el tablero 
					archivo.get(c);

				}
				if (c >= '1' && c <= '9') {
					rellenaCasilla(tablero[i][j], c, true);
				}
				else {
					rellenaCasilla(tablero[i][j], c);

				}

				if (tablero[i][j].estado != vacia) {

					actualizaFilaCol(tablero, i, j, tablero[i][j].numero);
					actualizaRegion(tablero, i, j, tablero[i][j].numero);


				}

			}


		}

		archivo.close();
	}


	return ok;
}


void dibujarTablero(const tTablero & tablero) {

	for (int i = 0; i < DIM; i++) {
		if (i % 3 == 0) {
			cout << "-------------------------------" << endl;
		}

		for (int j = 0; j < DIM; j++) {

			if (j % 3 == 0) {
				cout << "|" ;
			}
			dibujaCasilla(tablero[i][j]);
			 

		}
		cout << "|" << endl;
	}
	cout << "-------------------------------" << endl;

}


bool ponerNum(tTablero & tablero, int fila, int col, int c) {

	bool posible = false;


	if (tablero[fila][col].estado == vacia && pertenece(tablero[fila][col].conjunto, c)) {
		posible = true;


		actualizaFilaCol(tablero, fila, col, c);
		actualizaRegion(tablero, fila, col, c);
		annadeElemento(tablero[fila][col].conjunto, c);
		tablero[fila][col].estado = rellenada;
		tablero[fila][col].numero = c;


	}
	else {
		cout << "Ese numero no pertence al intervalo posible de valores de la casilla" << endl;

	}


	return posible;

}


bool borrarNum(tTablero & tablero, int fila, int col) {

	bool posible = false;
	int c = tablero[fila][col].numero;

	if (tablero[fila][col].estado == rellenada) {
		posible = true;


		tablero[fila][col].estado = vacia;
		tablero[fila][col].numero = ' ';


		actualizaFilaColBorraNum(tablero, fila, col, c);
		actualizaRegionBorraNum(tablero, fila, col, c);
		annadeElemento(tablero[fila][col].conjunto, c);	
		


	}
	return posible;
}


bool tableroLLeno(const tTablero & tablero) {
	bool lleno = true;
	int fila = 0; 
	int columna = 0; 

	while (fila < DIM && lleno){
		while(columna <DIM && lleno){

			if (tablero[fila][columna].estado == vacia) {				
				lleno = false;

			}
			
			columna++;
		}
		fila++;
	}

	return lleno;

}


void mostrarPosibles(const tTablero & tablero, int fila, int col) {

	if (tablero[fila][col].estado != rellenada) {

		mostrar(tablero[fila][col].conjunto);


	}
	else {
		cout << "La casilla que has introducido ha sido rellenada previamente por un valor" << endl; 
	}
	
}


void rellenarSimples(tTablero& tablero) {
	int numero;

	for (int i = 0; i < DIM; i++) { // recorre el tablero 
		for (int j = 0; j < DIM; j++) {

			if (esSimple(tablero[i][j], numero) == true) { // si la casilla vacia tiene un unico valor posible
				tablero[i][j].numero = numero;
				tablero[i][j].estado = rellenada;

				actualizaRegion(tablero, i, j, numero); // actualiza los posibles valores de la region 
				actualizaFilaCol(tablero, i, j, numero);// actualiza las filas y columnas 

			}
		}
	}




}

bool cuidadoBorraNumFila(tTablero & tablero, int fila, int col,int numero) {

	bool posibleFallo = false; 
	int i = 0;

	while (!posibleFallo && i < DIM){

		if (tablero[fila][i].numero == numero) {
			posibleFallo = true;			

		}
		i++;
	}
	return posibleFallo;

	
}

bool cuidadoBorraNumCol(tTablero & tablero, int fila, int col,int numero) {

	bool posibleFallo = false;
	int i=0;

	while(!posibleFallo && i < DIM){

		if (tablero[i][col].numero == numero) {
			posibleFallo = true;

		}
		i++;

	}
	return posibleFallo;


}

bool cuidadoBorraNumRegion(tTablero & tablero, int fila, int col,int numero) {

	bool posibleFallo = false;
	int i = 0;
	int j = 0 ;

	while (!posibleFallo && i < col +3) { // fallo de fila 

		if (tablero[fila][i].numero == numero) {
			posibleFallo = true;

		}
		i++;

	}
	while (!posibleFallo && j < fila + 3) { // fallo de columna 

		if (tablero[j][col].numero == numero) {
			posibleFallo = true;

		}
		j++;

	}

	return posibleFallo;
}