#pragma once
class Nodo
{
private:
	int valore; // valore assegnato al nodo;
	Nodo* nodoSx;//nodo alla sinistra;
	Nodo* nodoDx;//nodo alla destra;
public:
	Nodo(int newValore) :valore(newValore), nodoSx(nullptr), nodoDx(nullptr) {}; //costruttore, setta il valore assegnato al nodo e assegna nullptr ai due nodi sx e dx;
	void setSx(Nodo* sx);
	void setDx(Nodo* dx);
	Nodo* getSx();
	Nodo* getDx();
	int getValore();
	void setValore(int newValore);

};

