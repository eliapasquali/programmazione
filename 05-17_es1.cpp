#include<iostream>
using namespace std;

struct nodo
{
	int info;
	nodo* next;
	nodo(int a=0, nodo* b=0)
	{
		info=a;
		next=b;
	}
};

nodo* faiL(int n)
{
    if(n)
    {
        int x;
        cin >> x;
        return new nodo(x,faiL(n-1));
    }
    return 0;
}

void stampa(nodo*L)
{
    if(L)
    {
        cout << L->info<<' ';
        stampa(L->next);
    }
    else cout<<endl;
}

nodo* clone(nodo*L)
{
    if(L) return new nodo(L->info,clone(L->next));
    return 0;
}

//PRE: Lista(L) ben formata e ordinata, x punta ad un nodo
nodo* insOrd_ric(nodo* L, nodo* x)
{
	if(!L) return x;

	if(L->info >= x->info)
	{
		x->next = L;
		return x;
	}

	L->next = insOrd_ric(L->next, x);
	return L;
}
//POST: restituisce vL(L) con x aggiunto in modo che la nuova lista sia ancora ordinata

int length(nodo* L)
{
  if(L) return 1 + length(L->next);
  return 0;
}

//PRE: Lista(L) ben formata e ordinata, x punta ad un nodo
nodo* insOrd_iter(nodo* L, nodo* x)
{	
	int len = length(L);
	if(!len) return x;

	if(L->info >= x->info)
	{
		x->next = L;
		return x;
	}

	nodo* aux = L;
	while(aux)
	{
		if(aux->info < x->info)
		{
			if(aux->next)
			{
				if(aux->next->info > x->info)
				{
					x->next = aux->next;
					aux->next = x;
				}
			}
			else aux->next = x;
		}
		aux = aux->next;
	}

	return L;
}
//POST: restituisce vL(L) con x aggiunto in modo che la nuova lista sia ancora ordinata

main()
{
    int m, x;
    cin >> m >> x;
    nodo*L=faiL(m);
    nodo*L1=clone(L);
  
    L=insOrd_ric(L,new nodo(x));
    L1=insOrd_iter(L1, new nodo(x));
    stampa(L);
    stampa(L1);
}