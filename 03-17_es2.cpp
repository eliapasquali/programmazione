#include<iostream>
using namespace std;

int leggi(int *X, int dimX)
{
	int n=0;
	cin>>n;
	while(n<1 || n>30) cin>>n;
	int i=0;
	while(i<n)
	{
		cin>>X[i];
		i=i+1;
	}
	return n;
}

void stampa(int *X, int lim)
{
	int i=0;
	while(i<lim)
	{
		cout<<X[i]<<" ";
		i=i+1;
	}
	cout<<endl;
}

main()
{
	int A[30];
	int nelemA= leggi(A,30);
	
	//PRE: 0<nelemA<=30 && assumiamo che A[0..nelemA-1] contiene solo 2 valori distinti,  il valore iniziale di A è A_orig
	int i=0, ultimax=0, x=A[0];
	
	while(i<nelemA) //R: 0<=i<=nelemA && A[0..ultimax-1] contiene solo valori==x==A[o]
	{
		if(A[i]==x)
		{
			A[i]=A[ultimax];
			A[ultimax]=x;
			ultimax=ultimax+1;
		}
		i=i+1;
	}
	//POST: A contiene gli stessi elementi di A_orig con i valori ==A[0] tutti all'inizio
	stampa(A,nelemA);
}