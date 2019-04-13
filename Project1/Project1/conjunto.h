#ifndef  CONJUNTO_H
#define	 CONJUNTO_H


const int MAX_INTERVALOS = 9;



typedef bool  tIntervalo[MAX_INTERVALOS];


typedef struct {
	tIntervalo intervalo;
}tConjunto;

void cjto_vacio(tConjunto & c);
void cjto_lleno(tConjunto & c);
bool pertenece(const tConjunto & c, int e);
void annadeElemento(tConjunto & c, int e);
void borraElemento(tConjunto & c, int e);
int numElems(const tConjunto & c);
bool esUnitario(const tConjunto & c, int & e);
void mostrar(const tConjunto & c);


#endif


