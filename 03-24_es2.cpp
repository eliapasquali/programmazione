#include<iostream>
using namespace std;

int leggi(int *X, int dimX)
{
	int k, i=0;
	bool ok=false;
	while(!ok)
	{
		//cout<<"dai intero k, 0 < k <"<< dimX << endl;
		cin >> k;
		if(0<k && k<dimX) ok=true;
	}
	
	while(i<k)
	{
		cin >> X[i];
		i=i+1;
	}

	return k;
}

void stampa(int *X, int lim)
{
	int i=0;
	while(i<lim)
	{
		cout << X[i] << ' ';
		i=i+1;
	}
	cout<<endl;
}

//PRE_del: T e dim valori validi, val elemento da eliminare
int delVal(int *T, int dim, int val)
{
	int i=0, okFino=0;
	bool primo=true;

	//PRE: i=0 && okFino=0 && primo==true, T_orig=T
	while(i<dim) //R: okFino<=i<=nelemA && T[0..okFino-1]==T_orig[0..i-1] senza val && primo==true sse primo elemento analizzato
	{
		if(T[i]!=val || primo)
		{
			T[okFino]=T[i];
			i=i+1;
			okFino=okFino+1;
			primo=false;
		}
		else i=i+1;
	}
	//POST: okFino numero di elementi tali che T[0..okFino-1]=T_orig[0..dim-1] senza val

	return okFino;
}
//POST_del: T[0..okFino-1] e T_orig senza val

//PRE_k: A ha dim elementi definiti, sia A_orig=A
int K(int *A, int dim)
{
	int w=0, valido=dim;

	//PRE: w=0 && valido=dim, A_orig=A
	while(w<valido) //R: w<=valido && A[0..valido-1] == A_orig[0..dim-1] senza ripetizioni di A[w-1]
	{
		valido=delVal(A+w, valido-w, A[w])+w;
		w=w+1;
	}
	//POST: valido== A[0..valido-1] == A_orig[0..dim-1] senza alcun elemento ripetuto

	return valido;
}
//POST_k: restituisce un intero n tale che A[0..valido-1] è ottenuto da A_orig mantenendo per ogni valore solo l'istanza più a sinistra 

main()
{
	int A[30];
	int elemA=leggi(A, 30);

	stampa(A, K(A, elemA));
}

/** CORRETTEZZA
 * 
 * Correttezza di funzione ausiliaria delVal()
 * 	Dipende dalla correttezza del ciclo interno che sappiamo essere corretto per la dimostrazione di correttezza dell'esercizio 1 del 17/03
 * 	Da questo ottengo che POST_del mi assicura di restituirmi tutti i valori diversi da val
 * 
 * Correttezza di funzione K()
 * 	Dipende dalla correttezza del suo ciclo
 * 	PRE=>R banalmente vera
 * 	Ad ogni iterazione del ciclo analizzo l'elemento di A[w]. Invoco la funzione delVal() partendo da A+w per farle eliminare ripetizioni di A[w]
 * 	La POST_del mi assicura che da A+w in poi non ho ripetizioni di A[w], "riporto" valido alla sua lunghezza effettiva e incremento w
 * 	Per uscire dal ciclo devo ritrovarmi con w=valido, cosa che mi mantiene l'invariante R vero e mi assicura che delVal() ha eliminato anche le
 * 	ripetizioni dell'ultimo valore di A, ovvero A[w-1].
 * 	Quindi ora R=>POST che mi conferma che il mio A[0..valido-1]=A[0..dim-1] senza alcun elemento ripetuto
 * 	La POST del mio ciclo inoltre POST=>POST_k che quindi implica anche la correttezza della funzione K()
 *
 **/