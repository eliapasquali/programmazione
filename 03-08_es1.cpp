#include<iostream>
using namespace std;
main()
{
    int A[20];
    int i=0, pos=0, neg=0;
    while(i<20)
    {
        cin >> A[i];
        if(A[i]<0) neg=neg+1;
        if(A[i]>=0) pos=pos+1;
        i++;
    }
    
    cout << pos << " " << neg;
    
}


/** TESTO
Scrivere un programma che legge 20 interi e calcola il numero di questi valori che sono maggiori o uguali a
0 ed il numero di quelli minori a 0. Infine stampa i 2 valori calcolati.
**/
