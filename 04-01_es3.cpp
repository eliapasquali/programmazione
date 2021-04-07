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

main()
{
	int A[3][6][5];
	bool B[6][5];
	leggi(**A,90);
	//da fare  

	stampa(B,6);
}
