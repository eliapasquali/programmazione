#include <iostream>
#include "BST.h"
using namespace std;
using namespace BST;

main()
{
    //prepara un albero iniziale non triviale
  	nodo* r = new nodo(15, new nodo(7), new nodo(19));
	r->left->right=new nodo (9, new nodo(8));
	r->right->right=new nodo(25, new nodo(22));

	bool stop=false;
	while(!stop)
    {
		int operazione = 0;
		int y = 0;
		cin >> operazione;
		switch (operazione)
		{
			case 0 :
				stop = true;
				break;
			case 1 :
				stampa_l(r);
				break;
			case 2 :
				cin >> y;
				insert(r, y);
				stampa_l(r);
				cout<<endl;
				break;
			case 3 :
				cin >> y;
				if(search(r, y)) cout<<"valore "<<y<<" presente"<<endl;
				else cout<<"valore "<<y<<" non presente"<<endl;
				break;
			case 4 :
				cin >> y;
				if(y==1) cout<<max(r)->info<<endl;
				if(y==2) cout<<min(r)->info<<endl;
				break;
			case 5 :
				cout << altezza(r)<<endl;
				break;
			case 6 :
				cout << altMin(r)<<endl;
				break;
			default :
				cout<< "Errore" << endl;
		}
    }
}