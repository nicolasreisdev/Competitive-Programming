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

int main()
{
    ll x, cont = 10; cin >> x;
    for(int i = 0, j = 9; i < x; i++){
        if(i > 0) cont *= j;
    }
    cout << cont << "\n";

    return 0;
}