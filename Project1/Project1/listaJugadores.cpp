#include "listaJugadores.h"

#include<iostream>
#include<string>
#include<fstream>
#include<ctype.h>
#include"checkML.h"

using namespace std;

void creaListaVacia(tListaJugadores & lista) {
	   
	lista.jugador = new tJugadorPtr[lista.dimension];

	for (int i = 0; i < lista.dimension;i++) {
		lista.jugador[i] = new tJugador;

	}
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

		while (i < lista.dimension && !archivo.eof()) {

	
			archivo >>lista.jugador[i]->id;	 
			archivo >>lista.jugador[i]->puntos;

			lista.cont++;

			i++;
			
			if (lista.cont == lista.dimension) {
				ampliar(lista);
			}
		}

		archivo.close();
	}

	return ok;

}

void mostrar(const tListaJugadores & lista) {
	int i = 0;

	while (i < lista.cont) {
		cout << lista.jugador[i]->id << " " << lista.jugador[i]->puntos << endl;
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

		while (i < lista.cont  && ok) {		
		
			archivo << toString(*(lista.jugador[i]));

			if (i < lista.cont -1) {
				archivo << endl;

			}

			i++;

		}
		archivo.close();
	}
	return ok;

}


bool buscar(const tListaJugadores & lista, string id, int ini, int fin, int & pos) {

	//int mitad, posicion = -1;
	bool encontrado = false;

	if (ini <= fin) {
		int mitad =(ini + fin) / 2;

		if (lista.jugador[mitad]->id == id) {
			pos = mitad;
			encontrado = true;

		}
		else if (id < lista.jugador[mitad]->id) {
			encontrado = buscar(lista, id,ini,mitad-1,pos);
		}
		else {
			encontrado = buscar(lista, id, mitad + 1 ,fin, pos);
			
		}
		if (!encontrado) {
			pos = ini;
		}

	}

	return encontrado;
}

void puntuarJugador(tListaJugadores & lista, int puntos) { // se tendra que invocar despues de ganar un sudoku ? 
	int pos;
	bool ok = false;

	string nombre;
	tJugador jugador;

	cout << "Introduce el id de un jugador : "; 
	cin >> nombre;

	jugador.id = nombre;
	jugador.puntos = puntos;

	ok = buscar(lista, nombre,0, lista.cont-1 ,pos);

	if (ok) {

		//lista.jugador[pos].puntos += puntos;
		modificarJugador(*(lista.jugador[pos]), puntos);
		cout << "Has sumado puntos a un jugador existente de la lista";
		cout << endl; 


	}
	else {

		if (insertar(lista, jugador)) {
			cout << "Se ha podido insertar con exito en la lista "<< endl;

		}

		/*else {
			cout << "La lista esta llena, no se puede insertar un jugador nuevo " << endl;
		}
		*/
		

		
	}
	cout << endl;
	guardar(lista);
	mostrar(lista);

}



tListaJugadores ordenarPorRanking(const tListaJugadores & lista) {

	bool inter = true; 
	int i = 0; 
	tJugador jugador; // jugador auxiliar 
	tListaJugadores listaCopia;  // lista auxiliar para devolver 

	listaCopia = lista; // copias la lista original en una lista auxiliar para devolver 
	// tienes tu lista original la cual no modificas y tienes la lista auxiliar la cual modificas y la ordenas por el metodo de la burbuja 



	while (i < MAX_JUGADORES -1 && inter) {

		inter = false;

		for (int j = lista.cont - 1; j > 0; j--) {

		
		//	if (menor(lista.jugador[j],lista.jugador[j-1])) {	
			
				if (listaCopia.jugador[j]->puntos > listaCopia.jugador[j - 1]->puntos) {
					
					jugador = *(listaCopia.jugador[j]); // copias el jugador de la lista en un jugador auxiliar 

					*(listaCopia.jugador[j]) = *(listaCopia.jugador[j - 1]); 
					*(listaCopia.jugador[j - 1]) = jugador; 
					inter = true; 

				}
		}

		if (inter) {
			i++;

		}	
	}

	return listaCopia;
}


bool insertar(tListaJugadores & lista, tJugador jugador) {// hay que cambiarlo 
	bool ok = true; 
	int pos = 0;

	if (lista.cont == MAX_JUGADORES) {

		ampliar(lista);
		 
	}	
		
	while (pos <lista.cont && *(lista.jugador[pos]) < jugador){
			pos++;

	}
	
	//ok = buscar(lista, lista.jugador[pos]->id, 0, lista.cont-1, pos);

	//insertamos en la posicion i(primer mayor o igual)
	for (int i = lista.cont; i > pos; i--) {
		*(lista.jugador[i]) = *(lista.jugador[i - 1]);
	}

	lista.jugador[pos] = new tJugador(jugador);
	lista.cont++;

	guardar(lista);
	return ok;

}


void ampliar(tListaJugadores & lista) {

	tListaJugadores Aux; 

	Aux.dimension = lista.dimension; 

	creaListaVacia(Aux);

	Aux.cont = lista.cont;

	for (int i = 0; i < lista.cont; i++) {
		Aux.jugador[i]->id = lista.jugador[i]->id;
		Aux.jugador[i]->puntos = lista.jugador[i]->puntos;

	}

	borrarListaJugadores(lista);

	lista.dimension = lista.dimension * 2;

	creaListaVacia(lista);

	lista.cont = Aux.cont;

	for (int i = 0; i < lista.cont; i++) {
		lista.jugador[i]->id = Aux.jugador[i]->id;
		lista.jugador[i]->puntos = Aux.jugador[i]->puntos;
	}

	borrarListaJugadores(Aux);

}

	

void borrarListaJugadores(tListaJugadores & lista) {


	for (int i = 0; i < lista.cont; i++) {
		delete lista.jugador[i];

	}

	delete[] lista.jugador;
	//lista.cont = 0;

	   
}






