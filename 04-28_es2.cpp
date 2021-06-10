#include<iostream>
using namespace std;

void leggi_ric(int *A, int LA)
{
    if (LA==1) cin >> A[0];
    else
    {
        cin >> A[0];
        leggi_ric(A+1, LA-1);
    } 
}

int match_ric(int*T, int LT, int*P, int LP)
{
    if (LT==0) return -1;
    if (LP==0) return LT;

    if (T[0]==P[0]) match_ric(T+1, LT-1, P+1, LP-1);
    else match_ric(T-(LP%3)+1, LT+(LP%3)-1, P-(LP%3), LP+(LP%3));
    
}

void stampa(int *A, int LA)
{
    for(int i=0; i<LA; i++) cout << A[i] << ' ';
    cout << endl;
}

main()
{
    int T[50], P[10], LT, LP;
    cin >> LT >> LP;
    leggi_ric(T, LT);
    leggi_ric(P, LP);
    stampa(T, LT);
    stampa(P, LP);
    cout << "inizio match=" << match_ric(T,LT,P,LP) << endl;  
}   