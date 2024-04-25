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

int main(){
    int t, i, a, n, j, u; cin >> n;
    cin >> t >> i >> a;
    j /= t; 
    log10(j);
    u = j/(log((1+(a/i))));
    cout << round(u) << endl;


    return 0;
}