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

/** CORRETTEZZA
 * 
 * 	full_match()
 * 
 * 	Casi base:
 * 	!P : Se sono arrivato alla fine di P allora ho trovato un match completo e contiguo di P in T e restituisco true
 * 	!T : Se sono arrivato alla fine di T e il caso base precedente non è verificato allora T non contiene un match
 * 		 di P e quindi restituisco false
 * 	Caso ricorsivo:
 * 	Verifico se il nodo corrente di T e quello di P sono uguali, se il controllo fallisce restituisco false
 * 	Se invece è vero continuo a cercare il match completo di P richiamando full_match sui successivi nodi di entrambe le liste
 * 
 *	match1()
 *
 * 	Casi base:
 * 	!P : Ho trovato un match completo e contiguo di P in T quindi devo restituire una struttura doppiaL con primo campo
 * 		 contenente il resto di T dopo il match e come secondo campo il restante del match di P (cioè 0)
 * 	!T : Sono arrivato alla fine di T e quindi devo restituire una struttura doppiaL con primo campo contenente
 * 		 il resto di T dopo il match (cioè 0 essendo alla fine) e come secondo campo il restante del
 * 		 match di P (cioè 0 non essendoci match)
 * 	Caso ricorsivo:
 * 	Verifico a partire dal nodo corrente di T c'è un match completo e contiguo di P tramite la funzione full_match()
 * 	Se è verificata invoco la funzione match1() sui nodi successivi di entrambe le liste, altrimenti solo sul prossimo
 *	nodo di T. Al ritorno dalle ricorsioni la mia struttura doppiaL contiene:
 * 	Se il match era presente allora metto come primo campo di doppiaL il nodo di T (cioè il match) 
 * 	Altrimenti inserisco il nodo corrente di T nel secondo campo di doppiaL (cioè il resto di T che non fa parte del match)
 * 	
 * 	Nota: Essendo una funzione ricorsiva di tipo 1 ogni volta devo ricollegare il valore ritornato con il nodo corrente 
 * 
 * 	match3()
 * 
 * 	Casi base:
 * 	!T : Sono arrivato alla fine della lista e ritorno 0 per indicare la fine. Se è stato trovato un match che si conclude alla
 * 		 fine di T allora questo valore ritornato rispetta la POST e lo fa anche nel caso non fosse stato trovato un match
 * 	!P : Ho trovato un match completo di P in T e quindi tramite return posso restituire 0 ovvero la fine del match
 * 
 * 	Caso ricorsivo:
 * 	Verifico sempre tramite full_match() la presenza di un match completo e contiguo di P in T
 * 	Se questo è vero allora salvo il nodo in una variabile che mi servirà per ritornare la parte del match estratta da T
 * 	Modifico T nel suo successore e richiamo quindi match3() su T e sul prossimo nodo di P
 * 	Altrimenti continuo a cercare solo sul prossimo nodo di T
 * 
 * 	Nota: la funzione restituisce la parte di T con il match agendo come una ricorsione di tipo1, quindi la variabile che creo
 * 		serve a gestire i valori di ritorno che vengono sempre ricollegati 
 * 
 **/