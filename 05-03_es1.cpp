#include<iostream>
using namespace std;

struct stringa
{
    int lung; char S[20];
    stringa(int a =0, char* b=0)
    {
        lung=a;
        for(int i=0; i<lung; i++) S[i]=b[i];
    }
    bool operator<=(const stringa &);
};

bool stringa::operator<= (const stringa &dx)
{
    bool sx = true;
    for(int i=0; i<dx.lung && sx; i++)
    {
        if(S[i]>dx.S[i]) sx=false;
    }
    return sx;
}

std::istream& operator>>(std::istream& is, stringa& obj)
{
	is >> obj.lung;
	for(int i=0; i<obj.lung; i++) is >> obj.S[i];
	return is;
}

std::ostream& operator<<(std::ostream& os, const stringa& obj)
{
    os << "la stringa e’:\n";
	for(int i=0; i<obj.lung; i++) os << obj.S[i];
	os << endl;
    return os;
}

main()
{
    stringa X, Y, Z, W;
    cin >> X >> Y >> Z >> W;

    if(X <= Y) cout << X;
    else cout<< Y;

    if(Y <= X) cout << Y;
    else cout<< X;

    if(X <= Z) cout<< X;
    else cout << Z;

    if(X <= W) cout << X;
    else cout<< W;

    if(!(Z<=W)) cout<< Z;
    else cout<<W;
}