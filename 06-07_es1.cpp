#include<iostream>
using namespace std;

struct nodo{int info; nodo*next; nodo(int a =0, nodo*b=0){info=a; next=b;}};

nodo* faiL(int arr[],int dim)
{
	if(dim) return new nodo(*arr, faiL(arr+1,dim-1));
	else return 0;
}

nodo* clone(nodo*L)
{
	if(!L) return 0;
	return new nodo(L->info,clone(L->next));
}

void stampaL(nodo*L)
{
	if(!L) cout <<endl;
	else
    {
    	cout << L->info << ' ';
    	stampaL(L->next);
    }
}
// PRE: L(L) ben formata, k>=y, vL=L
nodo* elimI(nodo* L, int &n, int k, int y)
{
	// CASI BASE:
	// Fine lista
	if(!L) return 0;
	// Trovati abbastanza nodi info==y da eliminare
    if(n == k) return L;
    
	if(L->info == y)
	{
		n = n+1;
		nodo* aux = elimI(L->next, n, k, y);
		if(n>=k)
		{
			delete L;
			return aux;
		}
	}
	else L->next = elimI(L->next, n, k, y);
	
	return L;
}
//POST: se vL contiene almeno k nodi con info=y, allora L è ottenuta da vL eliminando i primi k nodi con info=y di vL,
//		altrimenti L=vL && se nodi di vL vengono cancellati, essi vanno deallocati

// PRE: L(L) ben formata, k>=y, vL=L
nodo* elimF(nodo* L, int &n, int k, int y)
{
	// CASI BASE:
	// Fine lista
	if(!L)
	{
		// Se ci sono abbastanza nodi da eliminare allora n=nodi da eliminare
		if(n >= k) n = k;
		// altrimenti n=0
		else n = 0;
		return 0;
	}

	if(L->info == y)
	{
		n = n+1;
		nodo* aux = elimF(L->next, n, k, y);
		if(n > 0)
		{
			delete L;
			n = n-1;
			L = aux;
		}
		else L->next = aux;
		
		return L;
	}
	else L->next = elimF(L->next, n, k, y);
}
//POST: se vL contiene almeno k nodi con info=y, allora L è ottenuta da vL eliminando gli ultimi k nodi con info=y di vL,
//		altrimenti L=vL && se nodi di vL vengono cancellati, essi vanno deallocati

main()
{
	int dim;
	cin >> dim;
	int* arr= new int [dim];
	for(int i=0; i<dim; i++) cin >>arr[i];
	nodo*L=faiL(arr, dim);
	nodo*L1=clone(L);

	int n=0, k, y;
	cin >> k >> y;
	L=elimI(L,n,k,y);
	n=0;
	L1=elimF(L1,n,k,y);
	stampaL(L);
	stampaL(L1);
}
