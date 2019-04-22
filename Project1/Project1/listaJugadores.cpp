#include "listaJugadores.h"

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void creaListaVacia(tListaJugadores & lista) {
	lista.cont = 0;
}

bool cargar(tListaJugadores & lista) {
	bool ok = false; 
	ifstream archivo;
	int i = 0;	
	creaListaVacia(lista);
	archivo.open("listaJugadores.txt");

	if (archivo.is_open()) {
		ok = true;

		while (i < MAX_JUGADORES && !archivo.eof()) {

			archivo >>lista.jugador[i].id;

			archivo >>lista.jugador[i].puntos;

			lista.cont++;

			i++;
		}

		archivo.close();
	}

	return ok;

}

void mostrar(const tListaJugadores & lista) {
	int i = 0;

	while (i < lista.cont) {
		cout << lista.jugador[i].id << " " << lista.jugador[i].puntos << endl;
		i++;
	}
}

bool guardar(const tListaJugadores & lista) {
	bool ok = false;
	int i = 0;

	ofstream archivo;

	archivo.open("listaJugadores.txt");

	if (archivo.is_open()) {
		ok = true;

		while (i < lista.cont && ok) {
			archivo << lista.jugador[i].id;
			archivo << " ";
			archivo << lista.jugador[i].puntos;
			archivo << endl;
			
			i++;

		}
		archivo.close();
	}
	return ok;


}

void puntuarJugador(tListaJugadores & lista, int puntos) {
	int pos;

	string nombre;

	cout << "Introduce el id de un jugador : "; 
	cin >> nombre;

	if (buscar(lista, nombre, pos)) {

		lista.jugador[pos].puntos += puntos;
		cout << "Has sumado puntos a un jugador existente de la lista";
		cout << endl; 


	}
	else {

		lista.jugador[lista.cont].puntos = puntos;
		lista.jugador[lista.cont].id = nombre;
	}

	guardar(lista);
	mostrar(lista);

}

bool buscar(const tListaJugadores & lista, string id, int & pos) {

	int mitad,posicion =-1, final = lista.cont - 1, ini = 0;
	bool encontrado = false;

	while (ini <= final && !encontrado) {
		mitad = final / 2;

		if (lista.jugador[mitad].id == id) {
			encontrado = true;

		}
		else if (id <lista.jugador[mitad].id ) {
			final = mitad - 1;
		}
		else {
			ini = mitad + 1;
		}
		if (encontrado) {
			pos = mitad;
		}

	}

	return encontrado;
}

tListaJugadores ordenarPorRanking(const tListaJugadores & lista) {

	bool inter = true; 
	int i = 0; 

	while (i < MAX_JUGADORES -1 && inter) {

		inter = false;

		for (int j = MAX_JUGADORES - 1; j > 1; j--) {
			if (lista.jugador[j] < lista.jugador[j - 1]) {
				int tmp; 
				tmp = lista.jugador[j]; 

			}
		}



		


	}
}