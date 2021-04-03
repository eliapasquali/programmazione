#include<iostream>
using namespace std;

//PRE= X è un array e dimX la sua lunghezza massima
int leggi(int *X, int dimX)
{
	int n=0; //numero elementi effettivi
	cin>>n;
	while(n<1 || n>30) cin>>n; //controllo valore di n
	int i=0;
	//PRE= X è un array, 1<=n<=30 i=0 && i<=n
	while(i<n) // R=letti i<=n elementi e inseriti in X[0..i-1]
	{
		cin>>X[i];
		i=i+1;
	}
	//POST= X[0..n-1] contiene gli n elementi letti
	return n;
}
//POST= restituisce il numero effettivo di elementi dell'array

/**Correttezza ciclo funzione leggi()
	Prima di entrare ho un array X e un n valido, i=0 che verificano sia la pre che R (vettore vuoto)
	Durante il ciclo quando i<n entro nel ciclo, leggo un valore in X[i] e aumento i
	Ora R mi indica che ho letto i elementi sicuramente <=n e sono inseriti in X[0..i-1]
	Se i+1<n allora continuo e ripeto l'operazione 
	Quando i+1<n=false => i+1=n. Quindi R mi dice che ho letto n<=n elementi e sono inseriti in X[0..n-1]
	Uscito dal ciclo quindi ho R ancora vero e devo vedere se R=>POST, che è vero dato che POST è R nella
	situazione i=n
*/

//PRE= X è un array con lim valori validi
void stampa(int *X, int lim)
{
	int i=0;
	//PRE= X ben definito e i=0
	while(i<lim) //R= i<=lim && stampati tutti gli X[0..i-1] elementi
	{
		cout<<X[i]<<" ";
		i=i+1;
	}
	//POST= stampati lim valori da X[0..lim-1]
	cout<<endl;
}
//POST= sono stati stampati tutti i valori validi di X e una newline

/**Correttezza ciclo funzione stampa()
	Prima di entrare ho un array X e i=0 che verificano sia la pre che R (vettore vuoto)
	Durante il ciclo quando i<lim entro nel ciclo, stampo il valore di X[i] e aumento i
	Ora R mi indica che ho stampato gli i elementi sicuramente <=lim da X[0..i-1]
	Se i+1<lim allora continuo e ripeto l'operazione 
	Quando i+1<lim=false => i+1=lim. Quindi R mi dice che ho stampato lim<=lim elementi da quelli in [0..lim-1]
	Uscito dal ciclo quindi ho R ancora vero e devo vedere se R=>POST, che è vero dato che POST è R nella
	situazione i=lim
*/

main()
{
	int A[30];
	int nelemA= leggi(A,30);

	//PRE= (0<nelemA<=30) && (A[0..nelemA-1] = A_orig[0..nelemA-1])

	int y;
	cin >>y;

	int i=0, okFino=0;
	while(i<nelemA) //R= okFino<=i<=nelemA && A[0..okFino-1]==A_orig[0..i-1] senza y
	{
	    if(A[i]!=y)
	    {
	        A[okFino]=A[i];
	        i=i+1;
	        okFino=okFino+1;
	    }
	    else i=i+1;
	}
	
	stampa(A, okFino);
}
//POST=(A[0..okFino-1] e A_orig senza y)

/** Correttezza ciclo main()
	Prima del ciclo ho la pre verificata dato che A e A_orig sono ancora uguali ed essendo
	okFino=0 e i=0 anche R è verificato
	Durante il ciclo quando i<nelemA ed A[i]!=y allora copio A[i] in A[okFino] ed incremento le
	due variabili, se invece A[i] è l'elemento da rimuove mando avanti solo l'indice i
	Alla successiva iterazione se i<nelemA allora ho okFino<=i<=nelemA e tutti i valori senza y
	tra A_orig[0..i-1] in A[0..okFino]
	Se invece i<nelemA è falsa allora i è necessariamente nelemA, quindi esco dal ciclo e
	l'invariante continua ad essere vero.
	Inoltre anche la POST è vera dato che okFino è il numero di valori diversi da y, i è nelemA
	e A[0..okFino-1] è uguale ad a A[0..nelemA-1] (che è A_orig) senza i valori uguali a y.
*/