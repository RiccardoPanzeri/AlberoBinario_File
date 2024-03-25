#include "AlberoBinario.h"

int main()
{
	AlberoBinario albero1;//istanzio albero vuoto;
	AlberoBinario albero2(25);//istanzio un secondo albero, con una root iniziale con valore 25;
	//richiamo la funzione statica appartente alla classe per riempire il file iniziale di numeri casuali;
	AlberoBinario::RiempiFile();
	//riempio entrambi gli alberi con i dati prelevati dal file;
	
	albero1.inserisci();
	//effettuo una ricerca:
	
	albero1.stampa();
	albero1.cerca(3);
}

