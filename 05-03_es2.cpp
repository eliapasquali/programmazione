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
		cout << L->info << ' ';
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

//PRE_1: Lista(L) ben formata, vLista(L) = Lista(L)
nodo* del1(nodo* L, int z)
{
	if(!L) return 0;
	
	L->next = del1(L->next, z);

	if(L->info == z)
	{
		nodo* aux = L->next;
		delete L;
		return aux;
	}

	return L;
}
//POST_1: resistuisce una lista composta dai nodi di vLista(L) che non hanno campo info=z nell'rdine che hanno in vLista(L)
//			e dealloca gli altri nodi di vLista(L)

//PRE_2: Lista(L) ben formata, non vuota e L->info!=z, vLista(L) = Lista(L)
void del2(nodo* L, int z)
{
	if(L->next)
	{
		if(L->next->info == z)
		{
			nodo* aux = L->next->next;
			delete L->next;
			L->next = aux;
			del2(L, z);
		}
		else del2(L->next, z);
	}
}
//POST_2: Lista(L) è ottenuta da vLista(L) eliminando i nodi con info=z e tenendo gli altri mantenendo il loro ordine
//			e i nodi con info=z sono deallocati

//PRE_3: Lista(L) ben formata, vLista(L)=Lista(L)
void del3(nodo* &L, int z)
{
	if(L)
	{
		if(L->info == z)
		{
			nodo* aux = L;
			L = L->next;
			delete aux;
			del3(L, z);
		}
		else del3(L->next, z);
	}
}
//POST_3: Lista(L) è ottenuto da vLista(L) eliminando i nodi con info=z e mantenendo gli altri nello stesso ordine che 
//			avevano in vLista(L) e i nodi eliminati sono deallocati

main()
{
	int m, z;
	cin >> m;
	nodo* Y = build1(m);
	stampa_LR_iter(Y);
	cin >> z;
	Y = del1(Y,z);
	stampa_LR_iter(Y);
	cin >> z;
	del2(Y,z);
	stampa_LR_iter(Y);
	cin >> z;
	del3(Y,z);
	stampa_LR_iter(Y);
}

/** CORRETTEZZA

		del1()
	Caso base: se si verifica vuol dire che ho visitato ogni nodo quindi restituisco 0
	Caso ricorsivo: considero il nodo corrento e verifico se il campo info==z
		In caso di match salvo il resto della coda in una variabile temporanea, dealloco L e restituisco il resto della coda. Altrimenti restituisco direttamente L. 
		Al ritorno dalla chiamata di funzione L@resto avrà sempre il resto con tutti nodi che hanno campo info!=z
	Alla fine della funzione anche se avrò fatto operazioni inutili per ricollegare elementi già collegati avrò la POST verificata e tutti i nodi da scartare deallocati
 
		del2()
	Caso base: dal ramo else implicito se L->next non esiste si ferma senza fare niente
	Caso ricorsivo: verifico se il nodo successivo all'attuale ha campo info==z
		In caso di match salvo il successivo del successivo, dealloco l'attuale next e lo scambio con quello salvato in precedenza. Per mantenere verificata la PRE
		devo invocare la funzione sull'attuale L dato che non ho sicurezza sul fatto che L->next->info non sia == z
		In caso contrario vado avanti ed invoco del2 su L->next
	Alla fine della ricorsione (ovvero quando non ho un L->next valido) mi ritrovo alla fine della lista con tutte i nodi nella stessa posizione di vLista a meno di 
	quelli con campo info==z che sono stati deallocati

		del3()
	Caso base: in modo analogo alla del2 in caso di nodo non valido si ferma senza eseguire nulla
	Caso ricorsivo: tramite il passaggio per riferimento di L posso modificare anche il nodo chiamante e non ho limitazioni sul fatto che sia L->info!=z
		Verifico se mi trovo in un nodo da eliminare. In questo caso allora in modo simile alla del2 salvo il nodo attuale, lo riassegno con il successivo e poi 
		lo elimino e richiamo la funzione su nodo attuale appena modificato. In caso di nodo valido scorro avanti chiamando del3 su L->next.
	Alla fine avrò una lista formata secondo le specifiche richieste dalla POST
	
**/