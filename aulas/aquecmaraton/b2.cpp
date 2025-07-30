#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, m , a; cin >> n >> m >> a;
    cout << ceil((double)n/a) * ceil((double)m/a) << endl;

    return 0;
}