#pragma once
#include "Nodo.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
using namespace std;

class AlberoBinario
{
private:
	Nodo* root;
	vector<int> ripetuti;
	//Metodo privato  ricorsivo per l'inserimento di un nuovo nodo;
	Nodo* inserisciNodo(int valore, Nodo* root);
	//metodo ricorsivo per la ricerca di un valore;
	bool ricerca(Nodo*, int valore);
	void stampaOrdinata(Nodo* root);// funzione che stampa i dati e li copia su un secondo file di testo;


public:
	AlberoBinario() :root(nullptr) {};//costruttore di base che crea un albero vuoto;
	AlberoBinario(int valore);//costruttore alternativo, in modo da poter istanziare un albero che ha già una root a scelta.
	//metodi publici che permettono all'utente di utilizzare il metodo privato:
	void cerca(int valore);
	void inserisci();
	void stampa(); 
	//funzione statica per riempire il file di testo da cui verranno prelevati i valori;
	static void RiempiFile();
	Nodo* getRoot();

};

