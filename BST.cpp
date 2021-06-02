#include <iostream>
#include "BST.h"
using namespace std;
using namespace BST;

void BST::stampa_l(nodo* r)
{
	if(r)
    {
        cout<<r->info<<'(';
        stampa_l(r->left);
        cout<<',';
        stampa_l(r->right);
        cout<<')';
    }
    else cout<<'_';
}

nodo* BST::insert(nodo* r, int y)
{
	if(!r) return new nodo(y);
	if(y <= r->info) r->left=insert(r->left, y);
	else r->right=insert(r->right, y);
	return r;
}

bool BST::search (nodo* r, int y)
{
	if(!r) return false;
	if(r->info == y) return true;
	if(y <= r->info) return search(r->left, y);
	else return search(r->right, y); 
}

nodo* BST::max(nodo* r)
{
	if(!r->right) return r;
	return max(r->right);
}

nodo* BST::min(nodo* r)
{
	if(!r->left) return r;
	return min(r->left);
}

int BST::altezza(nodo* r)
{
	if(!r) return -1;
	int hL = altezza(r->left); // hL : altezza sottoalberto sinistro
	int hR = altezza(r->right); // hR : altezza sottoalbero destro
	if(hL >= hR) return 1 + hL;
	else return 1 + hR;
}

int BST::altMin(nodo* r)
{
	if(r)
	{
		if(!r->left && !r->right) return 0;
		int hL = altMin(r->left);
		int hR = altMin(r->right);
		if(hL <= hR) return 1 + hL;
		else return 1 + hR;
	}

}