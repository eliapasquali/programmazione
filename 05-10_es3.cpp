#include <iostream>
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

int length(nodo*L)
{
  if(L) return 1 + length(L->next);
  return 0;
}

void stampa_LR_iter(nodo*L)
{
	int k=length(L);
	for(int i=0; i<k; i++)
	{
		cout<< L->info << ' ';
		L=L->next;
	}
	cout<<endl;
}

nodo* build1(int m)
{
	if(m==0) return 0;
	int s;
	cin >>s;
	return new nodo(s,build1(m-1));
}
 
struct doppiaL
{
	nodo* L, *S;
	doppiaL(nodo* a=0, nodo* b=0)
	{
		L=a;
		S=b;
	}
};

//PRE: T e P sono liste ben formate
bool full_match(nodo* T, nodo* P)
{
	if(!P) return true;
	if(!T) return false;

	if(T->info == P->info) return full_match(T->next, P->next);
	else return full_match(T->next, P);
}
//POST: ritorna true sse ogni valore di P è presente in T

//PRE: Lista(P) e Lista(T) sono ben formate, vT=T
doppiaL matchX1(nodo* T, nodo* P)
{
	if(!T) return doppiaL(0, 0);
	if(!P) return doppiaL(T, 0);

	if(full_match(T, P))
	{
	    if(T->info == P->info)
		{
			doppiaL q = matchX1(T->next, P->next);
			T->next = q.S;
			q.S = T;
			return q;
		}
		else
		{
			doppiaL q = matchX1(T->next, P);
			T->next = q.L;
			q.L = T;
			return q;
		}	
	}

	return doppiaL(T, 0);
}
//POST: La funzione restituisce sempre un valore doppiaL D come segue: se VT contiene m0,...,mk allora D.S=m0,...,mk e 
//		D.L contiene vT senza i nodi m0,...,mk. Mentre se vT non contiene m0,...,mk allora la funzione restituisce
//		D.S=0 e D.L=vT 

main()
{
	int m,z;
	cin >> m >> z;
	nodo* L=build1(m);
	stampa_LR_iter(L);
	nodo*P=build1(z);
	stampa_LR_iter(P);
	doppiaL D= matchX1(L,P);  
	stampa_LR_iter(D.L);
	stampa_LR_iter(D.S);
}

/** CORRETTEZZA
 * 
 * 	full_match()
 * 
 * 	Casi base:
 * 	!P : Se sono arrivato alla fine di P allora ho trovato un match completo di P in T e restituisco true
 * 	!T : Se sono arrivato alla fine di T e il caso base precedente non è verificato allora T non contiene un match
 * 		 di P e quindi restituisco false
 * 	Caso ricorsivo:
 * 	Verifico se il nodo corrente di T e quello di P sono uguali
 * 	Se il controllo è vero allora continuo a ricercare il match richiamando la funzione sui successivi nodi di entrambe le liste
 *  Altrimenti mi sposto solo sul successivo di T mantenendo invariato P 
 * 
 *	match1() corretta e già dimostrata
 * 
 **/