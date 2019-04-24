#include"jugador.h"

#include<iostream>
#include<string>
#include<iomanip>

using namespace std; 

string toString(tJugador jugador) {
	return "jugador.id +  jugador.puntos";
}

void modificarJugador(tJugador & jugador, int puntos) {

	jugador.puntos + puntos;

}

bool operator<(const tJugador & opIzq, const tJugador & opDer) { 


	if (opIzq.id == opDer.id) { 
		return opIzq.puntos < opDer.puntos;				
	}
	else {
		return opIzq.id < opDer.id;
	}
	
	
}

bool menor(const tJugador & j1, const tJugador & j2) {
	bool ok = false; 

	if (j1.puntos < j2.puntos || ( j1.puntos == j2.puntos && j2.id < j1.id)) ok = true;		

	return ok;
}
