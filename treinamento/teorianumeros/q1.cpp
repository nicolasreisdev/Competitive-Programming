#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5 + 10;
const int MIN = 0;

bool eprimo(ll n){
    if (n == 1) return false;
    for (int i = 3; i <= sqrt(n); i+=2){
        if (n % i == 0) return false;
    }
    return true;
}


int main()
{
    ll x, n, cont = 0; cin >> x;
    for (int i = 0; i < x; i++){
        ll y; cin >> y;
        if(eprimo(y) && y != 0 && y > 0) cont++;

    }
    cout << cont << endl;



    return 0;
}