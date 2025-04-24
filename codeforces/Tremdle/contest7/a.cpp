#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
#define all(x) x.begin(), x.end()

int main(){
    fastio;
    vector<int> v(3);
    for(int i = 0; i < 3;i++)cin >> v[i];
    sort(all(v));
    cout << v[1]-v[0]+v[2]-v[1] << endl; // a menor distancia em que devem se encontrar vai ser a soma das duas menores
    cout << v[2]-v[0] << endl; // a maior distancia em que devem se encontrar vai ser a soma da maior com a menor


    return 0;
}
