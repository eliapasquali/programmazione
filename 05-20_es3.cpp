#include<iostream>
using namespace std;

struct nodo{
	int info;
	nodo* left;
	nodo* right;

	nodo(int x=0, nodo* l=0, nodo* r=0){
		info = x;
		left = l;
		right = r;
	}
};

// FUNZIONI AUSILIARIE FORNITE
nodo* buildTree(int arr[], int i, int n)  {

    if (i >= n) {
    	return NULL;
    }
    nodo* root = new nodo(arr[i]);
    // insert left child
    root->left = buildTree(arr, 2 * i + 1, n);
    // insert right child
    root->right = buildTree(arr, 2 * i + 2, n);

    return root;

}

void stampa_l(nodo *r)
{
    if(r)
    {
        cout<<r->info<<'(';
        stampa_l(r->left);
    	cout<<',';
    	stampa_l(r->right);
    	cout<<')';
    }
	else cout<< '_';
}

void sc(int*C)
{
    cout<<*C<<' ';    
    if(*C!=-1) sc(C+1);
}

//PRE: Albero(R) ben formato, 0<=n<=k, k>0
int stampaASPre(nodo*r, int n, int k)
{
    if(!r) return n;

	int resto = 0;
    if(n==0)
	{
    	cout << r->info << ' ';
    	//reset numero di salti con k-1
    	resto = stampaASPre(r->left, k-1, k);
    	resto = stampaASPre(r->right, resto, k);
    }
	else
	{
        resto = stampaASPre(r->left, n-1, k);
        resto = stampaASPre(r->right, resto, k);
    }

	return resto;
}
//POST: considerando i nodi di Albero(R) in ordine prefisso, salta n nodi e poi stampa quello successivo  dopo
//		ne salta k-1 e poi stampa il succcessivo, restituisce col return un intero m tale che (k-1)-m è il numero
//		di nodi che sono stati saltati dopo l'ultimo stampato

//PRE: Albero(R) ben formato, 0<=n<=k, k>0
int stampaASInf(nodo*r, int n, int k)
{
	if(!r) return n;

	int resto = n;

	resto = stampaASInf(r->left, resto, k);
	if(resto==0)
	{
		cout<<r->info<<' ';
		resto = k;
	} 
	resto = stampaASInf(r->right, resto-1, k);

	return resto;
}
//POST: considerando i nodi di Albero(R) in ordine infisso, salta n nodi e poi stampa quello successivo, dopo
//		ne salta k-1 e poi stampa il succcessivo, restituisce col return un intero m tale che (k-1)-m è il numero
//		di nodi che osno stati saltati dopo l'ultimo stampato

int main() {
	int dim;
    cin >> dim;
    int* a = new int[dim];
    for (int i=0; i<dim; i++) cin >> a[i];
      
    nodo* root = NULL;
    root = buildTree(a, 0, dim);
    cout<<endl;
   
    int k;  
    cin>>k;    
    
	int a1 = stampaASPre(root, k-1, k);
	cout << " con avanzo "<< a1<<endl;
	int b1=  stampaASInf(root, k-1, k);
	cout << " con avanzo "<< b1 <<endl;
}

/** CORRETTEZZA
 * 
 * 	stampaASPre()
 * 
 * 	Caso base:
 *  !r : Sono arrivato alla fine dell'albero e devo ritornare il numero di nodi che mi sono rimasti da saltare
 * 
 * 	Caso ricorsivo:
 * 	All'inizio predispongo una variabile resto per salvarmi quanti nodi mi restano da saltare
 * 	Se la chiamata è stata fatta con n==0 allora devo stampare il campo info del nodo, per poi continuare secondo
 * 	l'ordine prefisso. Dopo aver finito di stampare il sottoalbero sinistro mi aspetto come valore di ritorno il 
 * 	numero di salti che mi restano da fare per quando valuterò il sottoalbero destro.
 * 	Dato che n è il parametro che uso per valutare il numero di salti da fare ho tre casi
 * 	Se è uguale a zero devo resettarlo richiamando la prossima funzione con k-1
 * 	Se non c'è uguaglianza continuo a chiamare la funzione su n-1 per decrementarlo
 * 	Dopo essere uscito dal sottoalbero sinistro richiamo la funzione con resto, ovvero il valore ritornato dalla chiamata
 * 	sul sottoalbero sinitro, come n
 * 	
 * 	Alla fine della ricorsione la funzione avrà stampato i nodi esatti e ritorna il numero di nodi che dovrebbe saltare
 *  
 * 	stampaASInf()
 * 	
 * 	Caso base:
 *  !r : Sono arrivato alla fine dell'albero e devo ritornare il numero di nodi che mi sono rimasti da saltare
 * 
 * 	Caso ricorsivo:
 * 	Secondo l'ordine infisso percorro l'albero stampando solo i nodi uno ogni k.
 * 	Se n==0 vuol dire che mi trovo in un nodo che devo stampare. Dopo averlo fatto resetto il mio contatore
 * 	n assegnandoli il valore k.
 * 	
 * 	Alla fine della ricorsione la funzione avrà stampato i nodi esatti e ritorna il numero di nodi che dovrebbe saltare
 * 
 **/