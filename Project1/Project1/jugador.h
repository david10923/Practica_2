#ifndef JUGADOR_H
#define JUGADOR_H


#include<string>
#include<iostream>
#include<sstream>

typedef struct {
	std::string id; 
	int puntos;
}tJugador;

typedef tJugador *tJugadorPtr;// puntero a jugador 


std::string toString(const tJugador & jugador);
void modificarJugador(tJugador & jugador, int puntos);
bool operator<(const tJugador & opIzq, const tJugador & opDer);
bool menor(const tJugador & j1, const tJugador & j2);




#endif