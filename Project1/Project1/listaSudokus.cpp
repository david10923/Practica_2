#include"listaSudokus.h"

#include<iostream>
#include<fstream>
#include<string>

using namespace std;




void crearListaVacia(tListaSudokus & lista) {

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
	int i = 0;

	cout << "Introduce el nombre del sudoku al que quieres jugar  y los puntos del sudoku : ";
	cin >> sudoku.nombreArchivo >> sudoku.puntos;
	cout << endl;

	while ((i < lista.cont) && (!ok)) {

		if (lista.sudoku[i].nombreArchivo == sudoku.nombreArchivo && lista.sudoku[i].puntos == sudoku.puntos) { // poner nombre donde pone sudoku1.txt
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


		while (i < lista.cont && ok) {
			archivo << lista.sudoku[i].nombreArchivo; 
			archivo << " ";
			archivo << lista.sudoku[i].puntos; 
			archivo << endl;


			i++;

		}
		archivo.close();
	}
	return ok; 
}


bool moverLista(tListaSudokus & lista, tSudoku sudoku) {
	bool ok = false; 

	if (lista.cont <MAX_SUDOKUS ){
		ok = true; 

		int pos = buscarPos(lista, sudoku); // ya t dice la posicion en la que la tienes que insertar no hace falta buscar la posicion 

		if (pos != -1) {

			//insertamos en la posicion i(primer mayor o igual)

			for (int j = lista.cont; j > pos; j--) {

				lista.sudoku[j] = lista.sudoku[j - 1];

			}
			lista.sudoku[pos] = sudoku;
			lista.cont++;




		}
		else {
			cout << "No se ha podiod introducir el sudoku en el sitio indicado " << endl; 

		}
		
	}
	else {
		cout << "La lista ha alcanzado el numero maximo de sudokus permitidos " << endl; 
	}

	return ok; 

}



bool registrarSudoku(tListaSudokus & lista) {

 	string nombre;
	int puntos, posInsertar;
	bool ok = false;
	tSudoku sudoku;

	cargar(lista);
	mostrar(lista);


	cout << "Introduce los datos del nuevo sudoku (nombre del fichero y numero de puntos que permite conseguir ): ";
	cin >> nombre >> puntos;
	cout << endl;
	

		if (!buscarFichero(lista, nombre)) {			

			sudoku.nombreArchivo = nombre;
			sudoku.puntos = puntos;

			if (moverLista(lista, sudoku)) {
				ok = true; 


			}				   

		}
		guardar(lista);
		mostrar(lista);	
		

	return ok;

}


bool buscarFichero(tListaSudokus & lista, string nombreFich) {
	bool existe = false;
	int i = 0;

	while (i < lista.cont && !existe) {

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

		if (lista.sudoku[mitad].puntos == sudoku.puntos){
			encontrado = true;

		}
		else if (sudoku.puntos < lista.sudoku[mitad].puntos){
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

bool  operator<(tSudoku izda, tSudoku dcha) {
	if (izda.puntos == dcha.puntos) {
		return izda.nombreArchivo < dcha.nombreArchivo;
	}
	else {
		return izda.puntos < dcha.puntos;
	}
	
}




