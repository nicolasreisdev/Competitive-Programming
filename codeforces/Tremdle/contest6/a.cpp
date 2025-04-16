#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;




int main(){
    ll a, b, c; cin >> a >> b >> c;
    
    cout << min((a+b+c), min(2*(a+b), min(2*(a+c), 2*(b+c)))) << endl;

    return 0;
}