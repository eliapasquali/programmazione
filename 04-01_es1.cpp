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
	int righePiene=(dim/7)+1;
	//int resto=dim%7;

	for(int i=0; i < righePiene; i++)
	{
		for(int j=0; j<7; j++) cout << X[i][j] << ' ';
		cout << endl;
	}

	//for(int i=0; i<resto; i++) cout<< X[righePiene+1][i] << ' ';
}

bool calcB( int (*A)[7], int r, int c, int righeP)
{
    bool rigaValida = true;

    for(int w=0; w<7 && rigaValida; w++)
    {
        bool trovato = false;

        for(int z=0; z<righeP && !trovato; z++) if(A[r][w] == A[z][c]) trovato=true;

        if(!trovato) rigaValida=false;
    }

    return rigaValida;
}

bool calcBresto(int (*A)[7], int r, int c, int righeP, int resto)
{
	bool rigaValida = true;

    for(int w=0; w<resto && rigaValida; w++)
    {
        bool trovato = false;

        for(int z=0; z<righeP && !trovato; z++) if(A[r][w] == A[z][c]) trovato=true;

        if(!trovato) rigaValida=false;
    }

    return rigaValida;
}

main()
{
	int A[7][7], nelem;
	bool B[7][7], finitoR=false;
	leggi(*A,nelem);
	
	int righePieneA=nelem/7;
	int restoA=nelem%7;
	int righeB=righePieneA+1;

	for(int r=0; r<righePieneA; r++)
	{
		for(int c=0; c<7; c++) B[r][c]=calcB(A, r, c, righePieneA);
	}

	for(int c=0; c<7; c++) B[righePieneA+1][c]=calcBresto(A, righePieneA+1, c, righePieneA, restoA);

	stampa(B,nelem);
}
