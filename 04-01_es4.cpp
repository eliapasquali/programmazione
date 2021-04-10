#include<iostream>
using namespace std;

void leggi(int*X, int& nelem)
{
	cin >> nelem;
	for(int i=0; i < nelem; i++) cin >> X[i];
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

//lungH(numero elementi, indice HFetta)
int lungH(int dim, int h)
{
	int sPieni=dim/30;
	int lungH=sPieni*5;
	int ultimoS=dim%30;
	if(ultimoS)
	{
		if(h < ultimoS/5) lungH=lungH+5;
		if(h == ultimoS/5) lungH=lungH+(ultimoS%5); 
	}
	return lungH;
}

//altV(numero elementi, indice VFetta)
int altV(int dim, int v)
{
	int sPieni=dim/30;
	int altV=sPieni*6;
	int ultimoS=dim%30;
	if(ultimoS)
	{
		if(v < ultimoS%5) altV=altV+(ultimoS/5)+1;
		else altV=altV+(ultimoS/5);
	}
	return altV;
}

//calcB(torta, strati, tipoFetta, indice HFetta, indice VFetta )
bool calcB(int (*A)[6][5], int s, int dim, int h, int v)
{
	bool fettaValida=true;

	int dimHF=lungH(dim, h);
	int dimVF=altV(dim, v);

	for(int elemH=0; elemH<dimHF && fettaValida; elemH++)
	{
		bool trovato=false;

		for(int elemV=0; elemV<dimVF && !trovato; elemV++)
		{
			if(FETTE(A, 3, 'H', h, elemH)==FETTE(A, 3, 'V', v, elemV)) trovato=true;
		}

		if(!trovato) fettaValida=false;
	}

	return fettaValida;
}

//stampaB(bool (*B)[5], int dim, int righe)
void stampaB(bool (*B)[5], int righe, int colonne)
{
	for(int i=0; i<righe; i++)
	{
		for(int j=0; j<colonne; j++) cout<<B[i][j]<<' ';
		cout << endl;
	}
}

main()
{
	int A[3][6][5], nelem;
	bool B[6][5];
	leggi(**A,nelem);

	int HF, VF;
	//numero HFette
	if(nelem>6*5) HF=6;
	else if(nelem%5==0) HF=nelem/5;
	else HF=(nelem/5)+1;
	//numero VFette
	if(nelem>5) VF=5;
	else VF=nelem;
	 
	 for(int h=0; h<HF; h++) //scorre HFette
	{
		for(int v=0; v<VF; v++) //scorre VFette
		{
			B[h][v]=calcB(A, 3, nelem, h, v); //calcola cella B
		}
	}
	
	stampaB(B, HF, VF); //da fare
}