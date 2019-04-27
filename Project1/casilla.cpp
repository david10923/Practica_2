#include"casilla.h"
#include<string>
#include <iostream>

using namespace std;



void colorFondo(int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}

void inicializaCasilla(tCasilla  & casilla) {

	casilla.estado = vacia;
	cjto_vacio(casilla.conjunto);

}

void rellenaCasilla(tCasilla & casilla, char c, bool fijas) {

	if (c == ' ') {
		casilla.estado = vacia;
		casilla.numero = ' ';

	}
	else if (c >= '1' && c <= '9') {

		int x = (int)c - 48;


		if (fijas == true) {

			casilla.estado = fija;
			cjto_lleno(casilla.conjunto);
			casilla.numero = x;
			annadeElemento(casilla.conjunto, casilla.numero);

		}
		else {
			casilla.estado = rellenada;
			casilla.numero = x;
			annadeElemento(casilla.conjunto, casilla.numero);
		}


	}


}

void dibujaCasilla(const tCasilla & casilla) {	


	if (casilla.estado == fija) {
		colorFondo(1);
		cout << " " << casilla.numero << " ";


	}
	else if (casilla.estado == rellenada) {
		colorFondo(4);
		cout << " " << casilla.numero << " ";

	}
	else if (casilla.estado == vacia) {
		colorFondo(0);

		cout << " " << (char)casilla.numero << " ";
	
	}
	colorFondo(0);


	

}

bool esSimple(const tCasilla & casilla, int &numero) {// revisar ?¿ esUnitario 

	bool ok = false;
	int numero1;

	if (casilla.estado == vacia && esUnitario(casilla.conjunto, numero1)) {
		ok = true;
		numero = numero1;

	}

	return ok;
}

