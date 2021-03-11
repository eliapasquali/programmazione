#include<iostream>
using namespace std;

main()
{
    char C[10];
    int i=0;
    while(i<10)
    {
        cin >> C[i];
        i=i+1;
    }

    int ok=0;
    i=0;
    //PRE= C[] è un array ben definito
    while(ok>=0 && i<10)
    {
        if(C[i]=='(') ok=ok+1;
        else ok=ok-1;
        i=i+1;
    }
    //POST= ok==0 sse la sequenza è bilanciata

    if(ok==0) cout << "bilanciato" << endl;
    else cout << "non bilanciato" << endl;
}
