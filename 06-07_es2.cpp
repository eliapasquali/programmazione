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

int height(nodo* root) {
	if(!root) {
		return -1;
	}
	return 1 + max(height(root->left), height(root->right));
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

struct nodoE{nodo*info; nodoE* next; nodoE(nodo*a=0, nodoE*b=0){info=a; next=b;}};

void stampaE(nodoE*x)
{
	if(x)
	{
		cout << x->info->info<<' ';
		stampaE(x->next);
	}
	else cout << endl;
}

nodoE* match_cam(nodo* T, int* P, int dimP)
{
	// CASI BASE
	// Albero non abbastanza alto per un match completo
	if(height(T)+1 < dimP) return 0;
	// T != match
	if(T->info != *P) return 0;
	
	// Ultimo nodo da controllare
	// Per primo caso base so che esiste
	// Per secondo caso base so che è giusto
	if(dimP == 1) return new nodoE(T);

	// Per casi base so di essere in nodi validi
	// Per if precedente so che ho altri elementi di P da valutare
	nodoE* match = match_cam(T->left, P+1, dimP-1);
	// Se match è un nodoE valido allora è stato trovato un match
	if(match) return new nodoE(T, match);
	// Altrimenti devo provare a destra di T
	else match = match_cam(T->right, P+1, dimP-1);
	// Se match è un nodoE valido allora è stato trovato un match
	if(match) return new nodoE(T, match);
	// Altrimenti non è stato trovato e devo ritornare un match nullo
	else return 0;
}

//PRE: Albero(T) ben formato, P contiene dimP>=0 elementi
nodoE* PM1(nodo* T, int* P, int dimP)
{
	// CASI BASE
	// Lista finita 
	if(!T) return 0;
	// Albero non ha abbastanza alto per un match completo
	if(height(T)+1 < dimP) return 0;

	nodoE* match=match_cam(T, P, dimP);
	if(match) return match;
	// Se non ho trovato match dalla radice continuo la ricerca
	nodoE* left=match_cam(T->left, P, dimP);
	if(left) return left;
	// Se non ho trovato nemmeno a sinistra cerco a destra
	// Posso ritornare direttamente dato che è l'ultima possibilità
	// Se non trova nemmeno qui ritorna 0
	return match_cam(T->right, P, dimP);
}
//POST: se in T esiste un cammino che contiene un match di P completo e contiguo, allora PM1 restituisce una lista
//		di dimP nodi di tipo nodoE che puntano ai nodi del cammino più a sinistra su cui esiste un tale match di P,
//		altrimenti PM1 restituisce 0

int main()
{
	int dim, dimP;
	cin >> dim >> dimP;
    nodo* r=0;
    int* A = new int[dim];
    for(int i=0; i<dim; i++)
    {
    	cin >> A[i];
    	r=buildTree(A,0,dim);
    }
	stampa_l(r);
    int* P = new int[dimP];
    for(int i=0; i < dimP; i++) cin>>P[i];
    nodoE* z = PM1(r, P, dimP);
    if(z)
    {
		cout<<"trovato match: ";
		stampaE(z);
    }
    else cout<<"nessun match"<<endl;
}