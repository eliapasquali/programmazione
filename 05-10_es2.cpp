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

//PRE: T e P sono liste ben formate
bool full_match(nodo* T, nodo* P)
{
	if(!P) return true;
	if(!T) return false;
	if(T->info != P->info) return false;
	return full_match(T->next, P->next);
}
//POST: ritorna true sse c'è un match completo di P in T

//PRE: T e P sono ben formate
nodo* match3b(nodo* &T, nodo* P)
{
	if(!P)
	{
		nodo* R = T;
		T = 0;
		return R;
	}
	if(!T) return 0;

	if(full_match(T, P))
	{
		return match3b(T->next, P->next);
	}	

	nodo* R = T;
	T=T->next;
	R->next = match3b(T, P);
	return R;
}
//POST: se c'è match restituisce il primo match P' con il parametro T e quello che resta di T col return
//		Se non c'è match il parametro T avrà valore 0 e la T originale verrà restituita col return

main()
{
	int m, z;
	cin >> m >> z;
	nodo* L=build1(m);
	stampa_LR_iter(L);
	nodo* P=build1(z);
	stampa_LR_iter(P);

	nodo* q= match3b(L,P);  
	stampa_LR_iter(q);
	stampa_LR_iter(L);
}

/** CORRETTEZZA
 * 
 * 	full_match() corretta già dimostrata
 * 
 * 	match3b()
 * 
 * 	Casi base:
 * 	!T : Sono arrivato alla fine di T e restuisco 0 ovvero cioè che resta di T col return
 * 	!P : Ho trovato un match completo di P in T. Allora dovendo restituire il resto di T tramite valore lo salvo
 * 		 in una variabile che passerò al return mentre modifico la variabile per riferimento con 0 per segnare
 * 		 l'arrivo alla fine della lista
 * 
 * 	Caso ricorsivo:
 * 	Verifico tramite full_match() se è presente un match completo e contiguo di P in T
 * 	Se il controllo è verificato allora continuo ad avanzare di nodi
 * 	Altrimenti devo "scambiare" la variabile passata per riferimento con la lista da ritornare per valore. Per fare ciò salvo
 * 	il nodo corrente nella variabile da restituire, modifico T per riferimento nel suo successivo.
 *  
 * 	Nota: la funzione restituisce il resto del match agendo come una ricorsione di tipo 1 e quindi devo ricollegare la lista
 * 		attuale da restituire al nodo ritornato dalla funzione. 
 * 
 **/