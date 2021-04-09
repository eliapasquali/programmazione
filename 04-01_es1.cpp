#include<iostream>
using namespace std;

void leggi(int* X, int & nelem)
{
	bool ok=false;
    while(!ok)
    {
        cin >>nelem;
        if(nelem>0 && nelem<=49) ok=true;
    }
    
	for(int i=0; i < nelem; i++) cin >> X[i];
}

void stampa(bool (*X)[7], int dim)
{
    int righe=0;
    if(dim<7) righe=1;
    else if(dim%7 != 0) righe=(dim/7)+1;
    else righe=dim/7;
    
	for(int i=0; i < righe; i++)
	{
		for(int j=0; j<7; j++) cout << X[i][j] << ' ';
		cout << endl;
	}
}

int lungR(int dim, int r) //lunghezza riga
{
	if (r<dim/7) return 7;
	else return dim%7;
}

int altC(int dim, int c) //altezza colonna
{
	if (c<dim%7) return (dim/7)+1;
	else return dim/7;
}

bool calcB(int (*A)[7], int r, int c, int dim) //calcola valore cella B
{
	bool rigaValida=true;

	for(int elemR=0; elemR<lungR(dim, r) && rigaValida; elemR++)
	{
		bool trovato=false;
		
		for(int elemC=0; elemC<altC(dim, c) && !trovato; elemC++)
		{
			if (A[r][elemR] == A[elemC][c]) trovato=true;
		}

		if (!trovato) rigaValida=false;
	}

	return rigaValida;
	
}

main()
{
	int A[7][7], nelem;
	bool B[7][7], finitoR=false;
	leggi(*A,nelem);

	int colA=7, rigA=nelem/7;
	if (nelem<7) colA=nelem; //nelem minore di riga
	if (nelem%7>0) rigA=rigA+1; //riga extra incompleta

	for(int r=0; r<rigA; r++) //scorri riga
	{
		for(int c=0; c<colA; c++) //scorri colonna
		{
			B[r][c]=calcB(A, r, c, nelem); //calcola valore
		}
	}

	stampa(B,nelem);
}

/** CORRETTEZZA
 * 
 * La correttezza dell'esercizio e data dalla correttezza del ciclo della funzione
 * calcB() che è corretta per la dimostrazione dell'esercizio 1 del 24/03
 * 
 * L'unica modifica sta nelle lunghezze di riga e colonna calcolate ad ogni chiamata di
 * calcB() tramite le funzioni lungR() e altC() che servono semplicemente e gestire la
 * presenza di righe e colonne non completamente riempite
 * 
 **/  