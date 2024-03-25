#include "AlberoBinario.h"


AlberoBinario::AlberoBinario(int valore) {
	root = new Nodo(valore);
	
}




void AlberoBinario::RiempiFile() {
	list<int>listaOrdinata;
	ofstream file1("testo1.txt");
	if (file1.is_open()) {//controllo in apertura
		srand(time(0));
		int valori = (rand() % 11) + 3;//numero divalori totali nel file;
		int x = 0;
		for (int i = 0; i < valori; i++) {
			x = rand() % 10;
			listaOrdinata.push_back(x);//inserisco i valori generati in una lista;

		}
		listaOrdinata.sort();//ordino la lista;

		for (int x : listaOrdinata) {
			file1 << x << endl;//scrivo i numeri della lista sul file;
		}

		file1.close();
	}
	else {
		cout << "Errore nell'apertura del file" << endl;
	}
}



Nodo* AlberoBinario::inserisciNodo(int valore, Nodo* nodo) {
	if (nodo == nullptr) {
		return new Nodo(valore);
	}
	else {
		if (valore > nodo->getValore()) {
			nodo->setDx(inserisciNodo(valore, nodo->getDx())); // Aggiungi come figlio destro
		}
		else if (valore < nodo->getValore()) {
			nodo->setSx(inserisciNodo(valore, nodo->getSx())); // Aggiungi come figlio sinistro
		}
		else {
			ripetuti.push_back(valore);
		}
		return nodo;
	}
}
		
	



bool AlberoBinario::ricerca(Nodo* root, int valore) {
	if (root == nullptr) {//se raggiungo la fine dell'albero, o se l'albero è vuoto;
		return false; //il valore non è presente;

	}
	else if (root->getValore() == valore) {//se trovo un valore corrispondente
		return true;//il valore è presente;
	}
	else if(valore < root->getValore()){//se il valore inserito è minore del valore del nodo
		ricerca(root->getSx(), valore);//chiamo la funzione ricorsiva sul nodo di sinistra;
	}
	else {//se invece è maggiore
		ricerca(root->getDx(), valore);//la chiamo su quello di destra;
	}
	

}

void AlberoBinario::stampaOrdinata(Nodo* root)
{
		
	ofstream file2("testo2.txt", ios::app);//apro lo stream in append;
	if (root != nullptr) {//se non ho raggiunto la fine dell'albero
		if (root->getSx() != nullptr) {
			stampaOrdinata(root->getSx());
		}
		cout << endl<< root->getValore() << endl;
		if (file2.is_open()) {
				file2 << root->getValore() << endl;
			}
			else {
				cout << "errore";
			}
			file2.close();
		
		if (root->getDx() != nullptr) {
			stampaOrdinata(root->getDx());
		}
	}

	
}



//funzioni pubbliche perl'utente;

void AlberoBinario::inserisci() {
	int valore = 0;
	ifstream file1("testo1.txt");
	if (file1.is_open()) {
		while (file1 >> valore) {
			root = inserisciNodo(valore, root);
		}
	}

	file1.close();
}


void AlberoBinario::cerca(int valore)
{
	if (ricerca(root, valore)) {
		cout << endl << "Il valore " << valore << " è presente all'interno dell'albero." << endl;
	}
	else {
		cout << endl << "Il valore " << valore << " non è presente all'interno dell'albero." << endl;
	}
	
}

void AlberoBinario::stampa() {
	ofstream file2("testo2.txt");
	file2.clear(); // svuoto il file ogni volta che richiamo la funzione
	cout << endl << "Elementi presenti nell'albero: " << endl;
	stampaOrdinata(root);
	file2.close();
	

	
}



Nodo* AlberoBinario::getRoot() {
	return root;
}

void AlberoBinario::mostraRipetuti() {
	for (int valore : ripetuti) {
		cout << endl << valore << endl;
	}
}