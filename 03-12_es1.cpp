#include<iostream>
using namespace std;

main()
{
    int A[8], i=0;
    while(i<8)
    {
        cin >> A[i];
        i=i+1;  
    }
    
    i=0;
    bool ok=true;
    //PRE= A[] è un array ben definito
    while(ok && i<4)
    {
        if(A[i]!=A[7-i]) ok=false;
        i++;
    }
    //POST= ok sse A è palindromo

    if(ok) cout <<"e’ un palindromo"<<endl;
    else cout<< "non e’ un palindromo"<<endl;
}