#include<iostream>
using namespace std;

void leggi(int*X, int nelem)
{
	for(int i=0; i < nelem; i++) cin >> X[i];
}

//PRE: T ha s strati ed è completamente definita, F e indf specificano una fetta esistente in T, k>=0 è un elemento esistente della fetta richiesta
int& FETTE(int (*A)[6][5], int s, char F, int indf, int k)
{
	if(F == 'V')
	{
		int nS=k/6; //strati da passare
		int resto=k%6; //elementi in strato
		return A[nS][resto][indf];
	}
	if(F == 'H')
	{
		int nS=k/5; //strati da passare
		int resto=k%5; //elementi in strato
		return A[nS][indf][resto];
	}
}
//POST: restituisce l'elemento k-esimo della fetta di T specificata da F e indf

main()
{
	int A[3][6][5], nelem;
	leggi(**A, 90);
	bool stop=false;
	while(!stop)
	{
    	char c;
    	cin >> c;
    	if(c =='S') stop=true;
    	else
		{
			int f,k;
	        cin>>f>>k;
	        cout << FETTE(A,3,c,f,k) << endl;
		}
    }
}

/**
 * Spiegazione FETTE
 * Per H-Fette:
 * 	In questo esercizio con una torta 3*6*5 in una HFetta i valori sono disposti orizzontalmente come 5_5_5 elementi di ogni strato
 * 	Dato un indice k della fetta per arrivare al valore richiesto mi devo spostare nello strato corrispondente (indice/colonne) e poi spostarmi
 * 	nella riga dello strato corretto di indice%colonne elementi.
 * Per V-Fette
 * 	La situazione è simile con gli elementi della VFetta disposti verticalmente 6_6_6 per ogni strato, uno per riga
 * 	Dato un indice k quindi mi sposto nello strato giusto, poi scendo di indice%righe righe e prendo il valore della colonna richiesta
 */ 