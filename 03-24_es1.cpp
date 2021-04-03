#include<iostream>
using namespace std;

void leggi(int *X, int k)
{
	int i=0;
	while(i<k)
	{
		cin >> X[i];
		i=i+1;
	}
}

void stampaMat(bool (*X)[8], int righe)
{
	for(int i=0; i < righe; i++)
	{
		for(int j=0; j<8; j++)
		{
			cout << X[i][j] << ' ';
		}
		cout << endl;
	}
}

bool calcB( int (*A)[8], int r, int c)
{
    int w = 0;
    bool rigaValida = true;

    //PRE1: w=0 e rigaValida=true
    while(w<8 && rigaValida) //R1: w<=8 && rigaValida==true sse A[r][w] è contenuta in colonna c 
    {
        bool trovato = false;
        int z=0;

        //PRE2: z=0 e trovato=false
        while(z<7 && !trovato) //R2: z<=7 && trovato==false sse A[0..z-1][c] non contiene A[r][w]
        {
            if(A[r][w] == A[z][c]) trovato=true;
            z=z+1;
        }
        //POST2: trovato=true sse A[r][w] contenuto in colonna c

        if(!trovato) rigaValida=false;
        w=w+1;
    }
    //POST1: rigaValida=true sse colonna c contiene riga r 

    return rigaValida;
}

main()
{
	int A[7][8];
	bool B[7][8];

	leggi(*A, 56); //lo leggiamo come se avesse 1 dimensione

    for(int r=0; r<7; r++)
    {
        for(int c=0; c<8; c++)
        {
            // devo controllare riga A[r][0..7] è contenuta in A[0..6][c]
            B[r][c] = calcB(A, r, c);
        }
    }

	stampaMat(B, 7);
}

/** CORRETTEZZA
 * 
 * Ciclo interno
 * 
 * Prima di entrare nel ciclo PRE2=>R2
 *  z=0<=7 && trovato=false banalmente
 * Durante il ciclo
 *  - Se trovo un valore uguale a A[r][w] durante la scansione di A[0..z-1][c] allora trovato=true ed esco dal ciclo
 *  - Se trovo non trovo alcun valore uguale dopo aver passato tutte le 6 celle allora z+1=7 e trovato è ancora false, quindi
 *  esco dal ciclo ed R2 rimane verificato
 * Posso uscire dal ciclo per queste due condizioni che
 *  - trovato=true e z<=7 quindi R2 verificato perchè A[0..z-1][c] contiene A[r][w] e quindi R2=>POST
 *  - trovato=false e z=7 quindi R2 verificato perchè in tutta A[0..z-1][c] non è contenuto A[r][w] e quindi R2=>POST
 * 
 * Ciclo esterno
 * 
 * Prima di entrare nel ciclo PRE1=>R1
 *  w=0<=8 && rigaValida==true banalmente
 * Durante il ciclo
 *  - Per POST2 so che trovato==true sse A[r][w] è contenuto in colonna c
 *  - Nel caso trovassi una corrispondenza per ogni w arriverei a w=8, uscirei dal ciclo e R1 continua ad essere vero
 *  - Al primo w<=8 che non è contenuto in c per POST2 ottengo trovato==false quindi metto rigaValida=false e rimango
 *  in una condizione per cui esco dal ciclo con R1 verificato
 * Per qualsiasi causa di uscita dal ciclo R2 mi assicura che rigaValida indica se la mia riga r è contenuta nella
 *  colonna c, quindi R2=>POST 
 * 
 **/