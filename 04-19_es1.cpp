#include<iostream>
using namespace std;

//PRE: B vista come array di nelem
void leggi(bool*B, int nelem)
{
    for(int i=0; i<nelem; i++) cin >> B[i];
}
//POST: B contiene gli nelem letti

//PRE: La coppia (i, X[i]) è la posizione del passo (riga, colonna) più a sinistra possibile in B
void print_path(int*X, int righe)
{
    for(int i=0; i<righe; i++) cout<<'('<<i<<','<<X[i]<<')'<<' ';
    cout <<endl;
}
//POST: stampato le coppie (riga, colonna) di B con passi più a sinistra possibili 

//PRE: B matrice 8x8 di booleani ben definita
bool trasformaMat(bool (*B)[8], int righe)
{
    for(int r=1; r<righe; r++)
    {
        //PRE: r=1 per definizione di algoritmo
        for(int c=0; c<8; c++) //R1: B[r][c] sse esiste cammino passando per lui
        {
            if(B[r][c])
            {
                if( c-1 == -1 ) B[r][c] = B[r-1][c] || B[r-1][c+1];
                else if ( c+1 == 8 ) B[r][c] = B[r-1][c-1] || B[r-1][c];
                else B[r][c] = B[r-1][c-1] || B[r-1][c] || B[r-1][c+1];
            }
        }
        //POST: B contiene 1 solo dove è possibile passare
    }
    
    bool rigaZeri=true;
    for(int p=0; p<8 && rigaZeri; p++) //R2: rigaZeri sse non c'è un passo possibile nell'ultima riga 
    {
        if(B[7][p]) rigaZeri=false;
    }
    //POST: rigaZeri sse non esiste cammino
    
    return rigaZeri;
}
//POST: rigaZeri sse non esiste un cammino

//PRE: B matrice trasformata secondo l'algoritmo
void build_path(bool (*B)[8], int righe, int* Path)
{
    for(int r=0; r<righe; r++)
    {
        bool trovato=false;
        //PRE: trovato=false
        for(int c=0; c<8 && !trovato; c++) //R: trovato sse B[r][0..c-1] contiene un passo valido
        {
            if(B[r][c])
            {
                Path[r]=c;
                trovato=true;
            }
        }
        //POST: trovato sse trovato un passo valido
    }
}
//POST: X è formato in modo che le coppie (i, X[i]) siano i passi possibili in B

main()
{
    bool Palude[8][8];
    leggi(*Palude,64);
    bool stop=false;

    stop=trasformaMat(Palude, 8);
    cout<<"Stop "<<stop<<endl;
    //POST: stop sse non c'è cammino
    
    if(!stop)
    {
        int Path[8];
        build_path(Palude,8,Path);
        print_path(Path,8);
    }
    else cout<<"nessun cammino"<<endl;
}

/** CORRETTEZZA build_path()
 * 
 * Data la PRE che assicura che B sia già stata trasformata secondo l'algoritmo sappiamo che
 * contiene 1 sse è possibile passare per quella cella
 * Dovendo cercare il cammino più a sinistra per ogni riga di B cerco la prima colonna contenente
 * un 1 e quindi costruisco X inserendo in X[i] l'indice della colonna di B,
 * In questo modo otteniamo che per ogni possibile passo trovato costruiamo X in modo che prendendo
 * le coppie (i, X[i]) indicano le celle (riga, colonna) dove è possibile passare.
 * 
 **/