#include<iostream>
#include<string>
#include"juego.h"
#include "listaSudokus.h"
#include"listaJugadores.h"


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

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	tJuego juego;
	tSudoku sudoku;
	tListaSudokus lista;
	tListaJugadores listaJ, listaCopia;

	listaJ.cont = 0; 
	lista.cont = 0;

	int opcion = 1;
	int puntos = 0;
	string nombre;
	bool ok = true;
	
	cargar(listaJ);


	while (opcion != 0) {

		opcion = menu();


		switch (opcion) {


		case 1:

			puntos = jugarUnSudoku(juego);			
			mostrar(listaJ);
			cout << endl;
			cout << "Estos son los jugadores que estan ya en la lista de jugadores " << endl;
			puntos = juego.sudoku.puntos;
			cout << endl;		
			puntuarJugador(listaJ, puntos);			

			
			break;
		case 2:
			
			cout << endl; 

			// al estar ordenada por identificador la lista no hace falta ordenarla  			
			mostrar(listaJ);			

			cout << endl; 
					
			break;
		case 3:

			cout << endl;
			// si que hay que ordenar la copia de la lista , pero en funcion de los puntos , ya que la lista original esta ordenada por identificador
			
			listaCopia = ordenarPorRanking(listaJ);
			mostrar(listaCopia);			

			cout << endl;
			
			break;
		case 4:
				

			if (registrarSudoku(lista) == true) {
				cout << endl; 

			}

			break;



		default:

			cout << "Has elegido la opcion de salir del juego " << endl;
		}

		cout << "--------------------------------------------" << endl; 


	}

	borrarListaJugadores(listaJ);

	system("pause");
	return 0;
}


