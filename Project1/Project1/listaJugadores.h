#ifndef LISTA_JUGADORES_H
#define LISTA_JUGADORES_H


#include<iostream>
#include"jugador.h"

	const int MAX_JUGADORES = 10;

	typedef tJugador tArrayJugador[MAX_JUGADORES];

	typedef struct {
		tArrayJugador jugador;
		int cont;

	}tListaJugadores;

	void creaListaVacia(tListaJugadores & lista);
	bool cargar(tListaJugadores & lista);
	void mostrar(const tListaJugadores & lista);
	bool guardar(const tListaJugadores & lista);
	void puntuarJugador(tListaJugadores & lista, int puntos);
	bool buscar(const tListaJugadores & lista, std::string id, int & pos);
	tListaJugadores ordenarPorRanking(const tListaJugadores & lista);





#endif