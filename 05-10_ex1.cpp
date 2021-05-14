#include<iostream>
using namespace std;
struct nodo
{
	int info;
	nodo* next;
	nodo(int a=0, nodo* b=NULL)
	{
		info=a;
		next=b;
	}
};
	
int length(nodo* L)
{
	if(L) return 1 + length(L->next);
	return 0;
}

void stampa_LR_iter(nodo* L)
{	
	int k=length(L);
	for(int i=0; i<k; i++)
	{
		cout<<L->info<<' ';
		L=L->next;
	}
	cout<<endl;
}

nodo* build1(int m)
{
	if(m==0) return 0;
	int s;
	cin >>s;
	return new nodo(s, build1(m-1));
}
 
struct doppiaL
{
	nodo*L, *S;
	doppiaL(nodo* a=0, nodo* b=0)
	{
		L=a;
		S=b;
	}
};

nodo* clone(nodo*L)
{
	if(!L) return 0;
	return new nodo(L->info, clone(L->next));
}

//PRE: T e P sono liste ben formate
bool full_match(nodo* T, nodo* P)
{
	if(!P) return true;
	if(!T) return false;
	if(T->info != P->info) return false;
	return full_match(T->next, P->next);
}
//POST: ritorna true sse c'è un match completo di P in T

//PRE: T e P sono liste ben definite
doppiaL match1(nodo* T, nodo* P)
{
	if(!P) return doppiaL(T, 0);
	if(!T) return doppiaL(0, 0);

	if(full_match(T, P))
	{
		doppiaL q = match1(T->next, P->next);
		T->next = q.S;
		q.S = T;
		return q;
	}
	
	doppiaL q = match1(T->next, P);
	T->next = q.L;
	q.L = T;
	return q;
}
//POST: se in T c'è un match di P, la funzione restituisce doppiaL q con q.S=P' e q.L=quello che resta di dopo P'. Si considera
//		il match più a sx. Se non c'è match allora restituisce doppiaL q con q.L=T e q.S=0

//PRE: T e P sono ben formate
nodo* match3(nodo* &T, nodo* P)
{
	if(!T) return 0;
	if(!P) return 0;

	if(full_match(T, P))
	{
		nodo* M = T;
		T = T->next;
		M->next = match3(T, P->next);
		return M;
	}

	return match3(T->next, P);
}
//POST: se c'è match restituisce il primo match P' con return e quello che resta di T nel parametro T
//		se non c'è match T resta inviariata e ritorna 0 col return

main()
{
	int m, z;
	cin >> m >> z;
	nodo* L=build1(m);
	stampa_LR_iter(L);
	nodo* P=build1(z);
	stampa_LR_iter(P);
	nodo* L1=clone(L);
	nodo* P1=clone(P);
	doppiaL D= match1(L,P);  
	stampa_LR_iter(D.L);
	stampa_LR_iter(D.S);
	nodo* q= match3(L1,P1);  
	stampa_LR_iter(L1);
	stampa_LR_iter(q);
}