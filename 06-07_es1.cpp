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

}
//POST: se vL contiene almeno k nodi con info=y, allora L è ottenuta da vL eliminando i primi k nodi con info=y di vL,
//		altrimenti L=vL && se nodi di vL vengono cancellati, essi vanno deallocati


// PRE: L(L) ben formata, k>=y, vL=L
nodo* elimI(nodo* L, int &n, int k, int y)
{

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
