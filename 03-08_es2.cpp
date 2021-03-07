#include<iostream>
using namespace std;

main()
{
    int A[20];
    int i=0, uno=0, due=0, tre=0, quattro=0, cinque=0;
    while(i<20)
    {
        cin >> A[i];
        if(A[i]==1) uno++;
        else if (A[i]==2) due++;
        else if (A[i]==3) tre++;
        else if (A[i]==4) quattro++;
        else if (A[i]==5) cinque++;
        i++;
    }
    
    cout << uno <<" "<< due <<" "<< tre <<" "<< quattro <<" "<< cinque;
}


/** TESTO
Scrivere un programma che legge 20 interi e calcola quanti 1, 2, 3, 4 e 5 ci sono tra i 20 valori.
**/