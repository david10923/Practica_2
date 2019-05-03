
#include"jugador.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>
#include"checkML.h"

using namespace std; 

string toString(const tJugador & jugador) {
	stringstream jugador1;


	jugador1 << setw(20) << left << jugador.id << setw(10) << right << jugador.puntos;

	return jugador1.str();
	
}

void modificarJugador(tJugador & jugador, int puntos){

	jugador.puntos += puntos;

}

bool operator<(const tJugador & opIzq, const tJugador & opDer) { 


	if (opIzq.id == opDer.id) { 
		return opIzq.puntos < opDer.puntos;				
	}
	else {
		return opIzq.id < opDer.id;
	}
	
	
}

bool menor(const tJugador & j1, const tJugador & j2) { // para que sirve esta funcion ?? 
	bool ok = false; 

	if (j1.puntos < j2.puntos || ( j1.puntos == j2.puntos && j2.id < j1.id)) ok = true;		

	return ok;
}
