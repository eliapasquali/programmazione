#include<iostream>
using namespace std;

void leggi(int*X, int k)
{
  it i=0;
  while(i<k)
    {
      cin >>X[i];
      i=i+1;
    }
}

void stampaMat(bool (*X)[8], int righe)
{
  for(int i=0; i < righe; i++)
    {
      for(int j=0; j<8; j++)
	     cout<<X[i][j]<<' ';
      cout << endl;
    }
  
}


main()
{

  int A[7][8];
  bool B[7][8];
  
  leggi(*A,56); //lo leggiamo come se avesse 1 dimensione
  
  //da fare
 
  stampaMat(B,7);
}



/**
Dato un array int A[7][8], vogliaom definire un array bool B[7][8] definito come segue: per ogni elemento B[i][j] di B
esso sra true sse la riga i di A è contenuta nella colonna j di A. Vediamo un esempio

2 3 2 1 0

0
3
1
2
5




*/