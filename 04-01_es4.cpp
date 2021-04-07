#include<iostream>
using namespace std;

void leggi(int*X, int& nelem)
{
	cin >> nelem;
	for(int i=0; i < nelem; i++) cin >> X[i];
}

//PRE:
void stampaB(bool (*B)[5], int dim, int righe)
{

}
//POST:

main()
{
	int A[3][6][5], nelem;
	bool B[6][5];
	leggi(**A,nelem);
	
	stampaB(B,nelem,6); //da fare
}