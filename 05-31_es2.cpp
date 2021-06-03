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

    if(i >= n) return NULL;

    nodo* root = new nodo(arr[i]);
    // insert left child
    root->left = buildTree(arr, 2 * i + 1, n);
    // insert right child
    root->right = buildTree(arr, 2 * i + 2, n);
    
	return root;
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

void buildBST(nodo*&r,int x)
{
	cout << "inserisco "<<x<<endl;
	if(!r) {r=new nodo(x);return;}
	if(r->info>= x) buildBST(r->left,x);
	else buildBST(r->right,x);
}

void calcIntMin(nodo* r, int &l1, int &l2, int y)
{
	if(r)
	{
		if(r->info >= l1 && r->info <= y) l1 = r->info;
		if(r->info >= y && r->info <= l2) l2 = r->info;
		calcIntMin(r->left, l1, l2, y);
		calcIntMin(r->right, l1, l2, y);
	}
}

void calcIntMinBST(nodo* r, int &l1, int &l2, int y)
{
	nodo* aux = r;
	//cerco l1
	while(aux)
	{
		if(aux->info >= l1 && aux->info <= y) l1 = aux->info;
		if(aux->info >= y) aux = aux->left;
		else aux = aux->right; 
	}
	//reset aux e cerco l2
	aux = r;
	while(aux)
	{
		if(aux->info >= y && aux->info <= l2) l2 = aux->info;
		if(aux->info >= y) aux = aux->left;
		else aux = aux->right;
	}
}

int main()
{
	int dim;
    cin >> dim;
    nodo* r = 0;
    int* A = new int[dim];
    for(int i=0; i<dim;i++)
    {
		cin >> A[i];
		r = buildTree(A, 0, dim);
    }
    nodo*r1=0;

    for (int i=0; i<dim; i++) buildBST(r1,A[i]);
    
    stampa_l(r);
    cout<<endl;
    stampa_l(r1);
       
    bool basta = false;
    int l1, l2, y;
    while(!basta)
	{
		cin >> l1 >> l2 >> y;
		int z1=l1, z2=l2;
		if(y==-1) basta=true;
		else
		{
	    	calcIntMin(r, l1, l2, y);
	    	cout <<"l1="<<l1<<" l2="<<l2<<endl;
	    
	    	calcIntMinBST(r1, z1, z2, y);
	    	cout <<"l1="<<z1<<" l2="<<z2<<endl;
	  	}
	}
}
