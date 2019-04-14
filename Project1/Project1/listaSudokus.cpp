#include"listaSudokus.h"

#include<iostream>
#include<fstream>
#include<string>

using namespace std;




void crearListaVacia(tListaSudokus & lista) {

	for (int i = 0; i < MAX_SUDOKUS; i++) {

		lista.sudoku[i].puntos = 0;
		lista.sudoku[i].nombreArchivo = " "; //inicializa el nombre del archivo de cada sudoku de la lista a vacio 		 
	}


	lista.cont = 0;
}



bool cargar(tListaSudokus &lista) {

	bool ok = false;
	ifstream archivo;
	int i = 0;
	string nombre;
	int p;
	crearListaVacia(lista);
	archivo.open("listaSudokus.txt");

	if (archivo.is_open()) {
		ok = true;

		while (i < MAX_SUDOKUS && !archivo.eof()) {

			archivo >> nombre;
			lista.sudoku[i].nombreArchivo = nombre;

			archivo >> p;
			lista.sudoku[i].puntos = p;

			lista.cont++;

			i++;

		}

		archivo.close();
	}
	return ok;

}


void mostrar(const tListaSudokus & lista) {

	int i = 0;

	//while (lista.sudoku[i].nombreArchivo  != " " && i < lista.cont) {
	while (i < lista.cont) {
		cout << lista.sudoku[i].nombreArchivo << " " << lista.sudoku[i].puntos << endl;

		i++;
	}



}

bool cargarSudoku(const tListaSudokus & lista, tSudoku & sudoku) {
	bool ok = false;
	string nombre;
	int i = 0;

	cout << "Introduce el nombre del sudoku al que quieres jugar : ";
	cin >> nombre;
	cout << endl;

	while ((i < lista.cont) && (!ok)) {

		if (lista.sudoku[i].nombreArchivo == nombre) { // poner nombre donde pone sudoku1.txt
			ok = true;
			sudoku.nombreArchivo = lista.sudoku[i].nombreArchivo;
			sudoku.puntos = lista.sudoku[i].puntos;
		}

		i++;
	}

	return ok;
}




bool guardar(const tListaSudokus & lista) {
	bool ok = false; 
	int i = 0;

	ofstream archivo; 

	archivo.open("listaSudokus.txt"); 

	if (archivo.is_open()) {
		ok = true; 


		while (i < MAX_SUDOKUS && ok) {
			archivo << lista.sudoku[i].nombreArchivo; 
			archivo << lista.sudoku[i].puntos; 
			archivo << endl;


			i++;

		}
		archivo.close();
	}
	return ok; 
}


void moverLista(tListaSudokus & lista, int posMover) {

	for (int i = lista.cont + 1; i < posMover; i--) { // empiezas en el contador +1 y mueves las posiciones desde el final para insertar 


		lista.sudoku[i] = lista.sudoku[i - 1];


	}



}



bool registrarSudoku(tListaSudokus & lista) {

	string nombre;
	int puntos, posInsertar;
	bool ok = false;
	tSudoku sudoku;


	cout << "Introduce los datos del nuevo sudoku (nombre del fichero y numero de puntos que permite conseguir : ";
	cin >> nombre >> puntos;
	cout << endl;
	
	cout << lista.cont; 


	if (lista.cont < MAX_SUDOKUS) {

		if (!buscarFichero(lista, nombre)) {
			ok = true;

			sudoku.nombreArchivo = nombre;
			sudoku.puntos = puntos;

			posInsertar = buscarPos(lista, sudoku);

			if (posInsertar != -1) {			


				moverLista(lista, posInsertar);

				lista.sudoku[posInsertar].nombreArchivo = nombre;
				lista.sudoku[posInsertar].puntos = puntos;
			

				lista.cont++;
			}


			




		}
		guardar(lista);
		mostrar(lista);


	}
	
	else {

		cout << "Error, la lista ya ha alcanzado el maximo de sudokus permitidos " << endl;

	}
		

	return ok;

}


bool buscarFichero(tListaSudokus & lista, string nombreFich) {
	bool existe = false;
	int i = 0;

	while (i < lista.cont && existe) {

		if (lista.sudoku[i].nombreArchivo == nombreFich) {
			existe = true;

		}

		i++;
	}

	return existe;
}


int buscarPos(const tListaSudokus & lista, const tSudoku & sudoku) {

	int posicion = -1, final = lista.cont - 1, ini = 0, mitad;
	bool encontrado = false;

	while (ini <= final && !encontrado) {
		mitad = (ini + final) / 2;

		if (lista.sudoku[mitad].puntos == sudoku.puntos && lista.sudoku[mitad].nombreArchivo == sudoku.nombreArchivo){

			encontrado = true;

		}
		else if (sudoku.puntos < lista.sudoku[mitad].puntos && lista.sudoku[mitad].nombreArchivo == sudoku.nombreArchivo){
			final = mitad - 1;

		}
		else {
			ini = mitad + 1;
		}

		if (encontrado)
			posicion = mitad;

	}
	return posicion;

}

bool  operator>(tSudoku izda, tSudoku dcha) {
	return izda.nombreArchivo > dcha.nombreArchivo && izda.puntos > dcha.puntos;
}




