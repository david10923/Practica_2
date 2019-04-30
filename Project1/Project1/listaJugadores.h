#ifndef LISTA_JUGADORES_H
#define LISTA_JUGADORES_H


#include<iostream>
#include"jugador.h"

	const int MAX_JUGADORES = 10;

	/*typedef tJugador tArrayJugador[MAX_JUGADORES];*/
	

	typedef struct {
		tJugadorPtr *jugador; // array dinamico de datos dinamicos
		int cont;
		int dimension;
	}tListaJugadores;

	

	void creaListaVacia(tListaJugadores & lista);
	bool cargar(tListaJugadores & lista);
	void mostrar(const tListaJugadores & lista);
	bool guardar(const tListaJugadores & lista);
	void puntuarJugador(tListaJugadores & lista, int puntos);
	bool buscar(const tListaJugadores & lista, std::string id, int & pos);
	tListaJugadores ordenarPorRanking(const tListaJugadores & lista);

	bool insertar(tListaJugadores & lista, tJugador jugador);
	
	//VERSION 3
	 
	void ampliar(tListaJugadores & lista); // redimensiona el array al doble de lo que tiene
	void borrarListaJugadores(tListaJugadores & lista);// libera la memoria usada por la lista 




#endif