#include<iostream>
using namespace std;

void leggi(int*X, int nelem)
{
	for(int i=0; i < nelem; i++) cin >> X[i];
}

void stampa(bool (*B)[5],int righe)
{
	for(int i=0; i<righe; i++)
    {
    	for(int j=0;j<5; j++ ) cout<<B[i][j]<<' ';
    	cout<<endl;
    }
}

//FETTE(torta, numero strati, tipoFetta, indiceFetta, valoreInFetta)
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

//calcB(torta, numStrati, indiceHFetta, indiceVFetta)
bool calcB(int (*A)[6][5], int s, int h, int v) //calcola valore cella B
{
	bool fettaValida=true;

	int dimHF=5*3; //numHF=6
	int dimVF=6*3; //numVF=5
	
	for(int elemH=0; elemH<dimHF && fettaValida; elemH++) //R_est: 0<=elemH<=dimHF && fettaValida sse HFetta[0..elemH] contenuto in VFetta
	{
		bool trovato=false;

		for(int elemV=0; elemV<dimVF && !trovato; elemV++) //R_int: 0<=elemV<=dimVF && !trovato sse HFetta[elemH] non è contenuto in VFetta 
		{
			if(FETTE(A, 3, 'H', h, elemH)==FETTE(A, 3, 'V', v, elemV)) trovato=true;
		}
		//POST_int: trovato sse HFetta[elemH] è contenuto in VFetta

		if(!trovato) fettaValida=false;
	}
	//POST_est: fettaValida sse HFetta contenuto in VFetta

	return fettaValida;
}
//POTS calcB(): fettaValida==true sse HFetta è contenuta in VFetta

/** CORRETTEZZA
 * 
 * La funzione FETTE permette di vedere le HFette e le VFette come "array" e per scorrendoli tramite i due cicli for
 * Nel ciclo interno R_int abbiamo che scorriamo la VFetta per cercare un match dell'elemento elemH della HFetta h
 * fino a quando non abbiamo lo abbiamo trovato. A quel punto il R_int è verificato e implica POST_int. Nel caso non trovassi
 * un match arrivato a elemV=dimVF, trovato==false e R_int implica POST_int
 * 
 * Nel ciclo esterno R_est assicura di avere fettaValida se per ogni elemento elemH della HFetta h che è stato controllato dal
 * ciclo interno abbiamo trovato un match. Appena questa condizione non è rispettata si esce dal ciclo. In entrambi i casi R_est
 * implica POST_est
 * 
 * Abbiamo alla fine che POST_int => POST_est => POST_calcB() e quindi la matrice B viene costruita correttamente.
 **/

main()
{
	int A[3][6][5];
	bool B[6][5];
	leggi(**A,90);

	for(int h=0; h<6; h++) //scorre HFette
	{
		for(int v=0; v<5; v++) //scorre VFette
		{
			B[h][v]=calcB(A, 3, h, v); //calcola cella B
		}
	}

	stampa(B,6);
}