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
	while(aux && aux->info < x->info) //R: aux && aux->info < x->info allora x non può essere inserito prima di aux
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

/** CORRETTEZZA
 * 
 * 	indOrd_ric()
 * 
 * 	Casi base:
 * 	!L : Se sono arrivato alla fine di L senza aver già inserito il nuovo nodo, allora ritorno quel nodo
 * 
 * 	Caso ricorsivo:
 * 	Verifico se il campo info del nodo corrente di L è maggiore o uguale di quello da inserire
 * 	Se il controllo è vero allora il nodo da inserire deve essere inserito prima dell'attuale L allora collego L
 * 	come campo next del nuovo nodo e restituisco il nuovo che ora costituisce il resto della mia lista con x
 * 	inserito nel punto corretto  
 * 	
 * 	Essendo una funzione ricorsiva di tipo 1 se questo controllo non è verificato richiama se stessa sul successivo
 * 	nodo di L e al ritorno si occuperà di collegare il valore ricevuto con il nodo corrente
 *  
 **/