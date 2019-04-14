#include<iostream>
#include<string>
#include"juego.h"
#include "listaSudokus.h"


using namespace std;



int menu() {
	int opcion;

	do {
		cout << "ESTE ES EL JUEGO DEL SUDOKU " << endl;
		cout << "-------------------------------------------" << endl;

		cout << "1.-Jugar" << endl;
		cout << "2.-Ver jugadores ordenados por identidficador" << endl;
		cout << "3.-Ver jugadores ordenados por puntos" << endl;
		cout << "4.-Incorporar sudoku" << endl;
		cout << "0.-Salir" << endl;

		cin >> opcion;

	} while (opcion < 0 || opcion >4);

	return opcion;

}




int main() {

	tJuego juego;
	tSudoku sudoku;
	tListaSudokus lista;


	int opcion = 1;
	int puntos = 0;
	string nombre;
	bool ok = true;


	while (opcion != 0) {

		opcion = menu();


		switch (opcion) {

		case 1:

			puntos = jugarUnSudoku(juego);

			cout << "La puntuacion ha sido de : " << puntos << endl;



			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			if (registrarSudoku(lista) == true) {
				cout << "Se ha podido registrar con exito el sudoku " << endl; 

			}

			break;



		default:

			cout << "Has elegido la opcion de salir del juego " << endl;
		}



	}


	system("pause");
	return 0;
}


