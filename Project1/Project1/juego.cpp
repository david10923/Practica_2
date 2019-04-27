
#include"juego.h"
#include"listaSudokus.h"
#include<iostream>
using namespace std;



void inicializaJuego(tJuego & juego, const tSudoku & sudoku) {//falta incluir los puntos en algun lado 

	juego.sudoku.nombreArchivo = sudoku.nombreArchivo;
	juego.sudoku.puntos = sudoku.puntos;
	juego.lleno = false;

}

void mostrarJuego(const tJuego & juego) {

	cout << "Nombre del sudoku : " << juego.sudoku.nombreArchivo << endl;
	cout << "Numero de puntos del sudoku :" << juego.sudoku.puntos << endl;

	dibujarTablero(juego.tablero);
}

bool cargaJuego(tJuego &juego, const tSudoku & sudoku) {
	bool ok = false;


	if (cargarTablero(sudoku.nombreArchivo, juego.tablero) == true) {
		ok = true;
	}


	return ok;


}

int menu2() {


	int opcion;

	do {

		cout << "1.-Ver posibles valores de una casilla vacia" << endl;
		cout << "2.-Colocar valor en una casilla" << endl;
		cout << "3.-Borrar valor de una casilla" << endl;
		cout << "4.-Reiniciar el tablero" << endl;
		cout << "5.-Autocompletar celdas simples" << endl;
		cout << "0.-Abortar la resolucion y volver al menu principal " << endl;


		cin >> opcion;

	} while (opcion < 0 || opcion > 5);

	return opcion;


}



int jugarUnSudoku(tJuego & juego) {

	tListaSudokus sudokuLista;
	int opcion2 = -1;
	bool ok = true;
	int puntos = 0, fila = 0, col = 0;
	sudokuLista.cont = 0;


	if (cargar(sudokuLista)) {


		mostrar(sudokuLista);

		if (cargarSudoku(sudokuLista, juego.sudoku)) {

			inicializaJuego(juego, juego.sudoku);

			if (cargaJuego(juego, juego.sudoku)) {

				cout << "Se ha podido cargar el juego correctamente " << endl;
				cout << endl;
				dibujarTablero(juego.tablero);
				cout << endl;

			}

			else {

				cout << "No se ha podido cargar " << endl;
				cout << endl;
				ok = false;
			}

		}
		else {
			cout << "No se ha podido cargar " << endl;
			cout << endl;
			ok = false;
		}

	}


	else {
		cout << "No se ha podido cargar " << endl;
		cout << endl;
		ok = false;
	}


	while (opcion2 != 0 && ok == true) {


		opcion2 = menu2();

		switch (opcion2) {

		case 1: // ver posibles valores

			cout << "Indica una casilla para ver sus valores :" << endl;
			cout << "Fila:"; cin >> fila;
			cout << "Columna :"; cin >> col;

			if ((fila > 0 && fila < 9) && (col > 0 && col < 9)) {


				if (juego.tablero[fila - 1][col - 1].estado != fija) {

					cout << "Los posibles valores son:";
					cout << endl;
					mostrarPosibles(juego.tablero, fila - 1, col - 1);
				}
				else
					cout << "Esta casilla, tiene un valor fijo :" << juego.tablero[fila - 1][col - 1].numero << endl;

			}
			else {
				cout << "Los valores introducidos no se encuentran dentro de los limites del tablero" << endl;

			}

			cout << endl;

			break;

		case 2:  // colocar valor en una casilla
			int numero;

			cout << "Indica una casilla:" << endl;
			cout << "Fila:"; cin >> fila;
			cout << "Columna :"; cin >> col;


			if ((fila > 0 && fila < 9) && (col > 0 && col < 9)){


				if (juego.tablero[fila - 1][col - 1].estado == vacia) {

					cout << "Numero que quieres colocar en la casilla vacia (1-9) :";
						cin >> numero;
						cout << endl;

						if (numero > 0 && numero < 10) {

							if (ponerNum(juego.tablero, fila - 1, col - 1, numero)) { // porque es de tipo bool
								cout << "Se ha podido introducir con exito el numero " << endl;
								cout << endl;
							}


						}
						else {
							cout << "El numero es incorrecto , no pertence al rango descrito anteriormente" << endl;
						}


				}
				else {
					cout << "No se puede colocar un valor en esa casilla" << endl;

				}

				dibujarTablero(juego.tablero);
				cout << endl;

			}
			else {
				cout << "Los valores introducidos no se encuentran dentro de los limites del tablero" << endl; 
				cout << endl;
			}

			break;

		case 3: //borrar valor de una casilla

			cout << "Indica una casilla :" << endl;

			cout << "Fila:"; cin >> fila;
			cout << "Columna :"; cin >> col;
			cout << endl;

			if (juego.tablero[fila - 1][col - 1].estado == rellenada) {

				if (borrarNum(juego.tablero, fila - 1, col - 1)) { // porque es de tipo bool
					cout << "Se ha podido borrar con exito el numero indicado" << endl;
					cout << endl;

				}

			}

			dibujarTablero(juego.tablero);
			cout << endl;
			break;

		case 4: //reiniciar tablero

			cargaJuego(juego, juego.sudoku);
			dibujarTablero(juego.tablero);
			cout << endl;


			break;

		case 5: //autocompletar celdas simples

			rellenarSimples(juego.tablero);
			dibujarTablero(juego.tablero);
			cout << endl;



			break;

		default:
			cout << "Has elegido salir de la opcion jugar" << endl;


		}

	}

	if (tableroLLeno(juego.tablero)) {

		cout << "Has conseguido rellenar satisfactoriamente el sudoku " << endl;
		puntos = juego.sudoku.puntos;
	}
	else
		puntos = 0;


	return puntos;


}








