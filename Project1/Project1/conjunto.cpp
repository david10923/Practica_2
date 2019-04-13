#include"conjunto.h"


#include <iostream>

using namespace std;

void cjto_vacio(tConjunto & c) {

	for (int i = 0; i < MAX_INTERVALOS; i++) {
		c.intervalo[i] = false;
	}

}

void cjto_lleno(tConjunto & c) {

	for (int i = 0; i < MAX_INTERVALOS; i++) {
		c.intervalo[i] = true;
	}

}

bool pertenece(const tConjunto & c, int e) {

	bool ok = false;
	if (c.intervalo[e - 1] == false) {
		ok = true;
	}
	return ok;

}

void annadeElemento(tConjunto & c, int e) {

	c.intervalo[e - 1] = false;
}

void borraElemento(tConjunto & c, int e) {

	c.intervalo[e - 1] = true;
}


int numElems(const tConjunto & c) {
	int contador = 0;
	for (int i = 0; i < MAX_INTERVALOS; i++) {
		if (c.intervalo[i] == false)
			contador++;
	}
	return contador;
}

bool esUnitario(const tConjunto & c, int & e) {

	bool unitario = false, encontrado = false;
	int i = 0, elementos;

	elementos = numElems(c);

	if (elementos == 1) {
		unitario = true;
		while ((i < MAX_INTERVALOS) && (!encontrado)) {
			if (c.intervalo[i] == false) {
				encontrado = true;
				e = i + 1;

			}
			i++;
		}
	}

	return unitario;
}

void mostrar(const tConjunto & c) {

	for (int i = 0; i < MAX_INTERVALOS; i++) {
		if (c.intervalo[i] == false) {
			cout << i + 1 << "  ";
		}
	}

}

