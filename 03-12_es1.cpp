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
    //PRE= A[] è ben definito, i=0 e ok==true;
    while (ok && i<4) //R=(ok sse A[0..i-1]==reverse(A[8-i..7]) && 0<=i<=4)
    {
        if(A[i]!=A[7-i]) ok=false;
        i++;
    }
    //POST= ok sse A è palindromo;

    if(ok) cout <<"e’ un palindromo"<<endl;
    else cout<< "non e’ un palindromo"<<endl;
}

/** CORRETTEZZA

Prima del ciclo: ho ok=true, i=0
    PRE => R, ok sse A[0..-1]==reverse(A[8..7]) && 0<=0<=4
        i due array li considero vuoti e quindi vuoto=vuoto vero => true=>true

Durante il ciclo: verifico per casi
    se A[i]!=A[7-i] ok si nega e poi aumento i (sempre <=4), alla prossima iterazione avrò
    R : ok sse A[0..(i+1)-1]==reverse(A[8-(i+1)..7]) && 0<=i+1<=4,
        false sse false && true = true, R è ancora vero ed esco dal ciclo

    se A[i]==A[7-i] aumento i (sempre <=4), alla prossima iterazione avrò
    R : ok sse A[0..(i+1)-1]==reverse(A[8-(i+1)..7]) && 0<=i+1<=4,
        true sse true && true = true, R è ancora vero e rientro nel ciclo

Uscita dal ciclo: verifico i casi possibili
    posso avere ok=false e quindi un array non palindromo e un i<=4
    R : ok sse A[0..i-1]==reverse(A[8-i..7]) && 0<=i<=4,
        false sse false && true = true, R è ancora vero
    Ora R => POST? La POST è false sse false = true
        Quindi R => POST : true => true = true

    se invece ok=true allora i=4
    R : ok sse A[0..3]==reverse(A[4..7]) && 0<=4<=4
        true sse true && true = true
    Ora R => POST? La POST in questo caso è true sse true = true
        Quindi R => POST : true => true = true

Il ciclo è quindi corretto (e di conseguenza il programma) **/