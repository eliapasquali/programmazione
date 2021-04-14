#include<iostream>
using namespace std;

void leggi(int *A, int LA)
{
    for(int i=0; i<LA; i++) cin >> A[i];
}

//PRE: T ha LT elementi e P ne ha LP, LT e LP sono >0
int match(int*T, int LT, int*P, int LP)
{
    //PRE: T lungo LT e P lungo LP
    for(int t=0; t<LT; t++) //R2: t<=LT
    {
        if(T[t]==P[0])
        {
            bool ok=true;
            //PRE: ok=true, t inizio di un possibile match
            for(int p=1; p<LP && ok; p++) //R1: p<=LP && ok, t indice di inizio possibile match
            {
                if(T[t+p]!=P[p]) ok=false;
            }
            //POST: ok=true sse T[t..t+LP]==P[0..LP]
            if(ok) return t;
        }
    }
    //POST: restituisce t sse è l'indice minimo di un possibile match
    return -1;
}
//POST: se c’è un match di P in T, allora la funzione restituisce l’indice minimo di un tale match, altrimenti restituisce -1

main()
{
    int T[50], P[10], LT, LP;
    cin >> LT >> LP;
    leggi(T,LT);
    leggi(P,LP);
    cout << " inizio match="<<match(T,LT,P,LP)<<endl;  
}


/** CORRETTEZZA
 * 
 * R1: p<=LP && ok sse T[t..t+p]==P[0..p], t indice di inizio possibile match
 * 
 * Inizio del ciclo: posso ritrovarmi a tentare questo ciclo solo se l'if ha dato esito positivo e quindi t è l'indice di un
 * possibile inizio di match
 * Durante il ciclo: valuto se T[t+p]==P[p]. Se positivo continuo a ciclare mentre se trovo una differenza metto ok=false e quindi la condizione
 * di permanenza non è più verificata. Se esco perchè p=LP allora ho trovato un match e ok=true
 * All'uscita: entrambe le situazioni che mi portano ad uscire dal ciclo mi assicurano di avere ok==true sse ho trovato un match a partire da t
 * 
 * 
 * R2: t<=LT
 * La correttezza è semplice perchè questo ciclo serve solamente a scorrere i vari elementi di T che per ogni possibile inizio di match vengono valutati
 * dal secondo ciclo che è corretto per R1.
 * In caso non venga trovato nessun match allora si esce per condizione t=LT
 * 
 * Funzione match()
 * R2 assicura che durante la sua scansione di T può esserci il return solamente del primo indice di un match di P in T trovato nel ciclo descritto
 * dall'invariante R1. Se da questo ciclo non otteniamo risultati la funzione restituisce arbitrariamente -1 come richiesto dalla POST in caso di fallimento
 * 
 **/