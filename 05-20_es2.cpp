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
	    return 0;
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

bool foglia(nodo* r)
{
	if(!r->left && !r->right) return true;
	return false;
}

//PRE:	Albero(R) è ben formato e non vuoto, k>=0 e y valore qualsiasi. C ha almeno tanti elementi quanta è
//		l'altezza dell'albero
bool cerca_cam(nodo* r, int k, int y, int* C)
{
	//Caso base: sono in una foglia
	if(r && foglia(r))
	{
		//Foglia è ultimo y OR ho trovato già trovato k nodi==y 
		if((r->info==y && k==1) || (r->info!=y && k==0))
		{
			*C = -1;
			return true;
		}
		else return false;
	}

	if(r->info == y) k=k-1;
	if(k<0) return false; //più nodi y di k

	if(r->left && cerca_cam(r->left, k, y, C+1)) //cerco cammino a sx
	{
		*C = 0;
		return true;
	}
	if(r->right && cerca_cam(r->right, k, y, C+1)) //cerco cammino a sx se non esiste a dx
	{
		*C = 1;
		return true;
	}

	//Nessun cammino
	return false;
}
//POST:	restituisce true sse in Albero(R) esiste un cammino da r ad una foglia con esattamente k nodi con campo
//		info=y e false altrimenti && in caso restituisca true, C contiene una sequenza (anche vuota) di 0/1 seguita
//		da -1 che individua il cammino più a sx in Albero(R) con esattamente k nodi con campo info=y

int main() {
    int dim;
    cin >> dim;
    int* a = new int[dim];
    for (int i=0; i<dim; i++) cin >> a[i];

    nodo* root = NULL;
    root = buildTree(a, 0, dim);
    stampa_l(root);
    cout << endl;
    int h = height(root);
    int* C = new int[h];
   
    int k, val;  
    cin >> val >> k;    
    
    bool b = cerca_cam(root, k, val, C);
    cout<<endl;
    if(b)
    {
        cout<<"trovato  cammino= ";
        sc(C);
        cout<<endl;
    }
    else cout<<" nessun cammino con " << k << " valori=" << val << endl;
  
}