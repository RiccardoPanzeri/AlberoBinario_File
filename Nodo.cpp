#include "Nodo.h"
#include <iostream>
using namespace std;


void Nodo::setSx(Nodo* sx) {
	nodoSx = sx;
}

void Nodo::setDx(Nodo* dx) {
	nodoDx = dx;
}

Nodo* Nodo::getSx() {
	return nodoSx;
}

Nodo* Nodo::getDx() {
	return nodoDx;
}


int Nodo::getValore() {
	
	return valore;
}

void Nodo::setValore(int newValore) {
	valore = newValore;
}