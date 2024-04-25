#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5 + 10;

int main(){
    int d, c, r, cont = 0, x; cin >> d >> c >> r;
    int g[r];
    vector<int>v;
    for(int i = 0; i < c;i++){
        cin >> x;
        v.pb(x);
    }
    for(int i = 0; i < r;i++){
        cin >> g[i];
        d+=g[i];
        cont++;
    }
    for(int i = 0; i < c;i++){
        if(d >= v[i]){
            d-=v[i];
            cont++;
        }
        else if (d < v[i]){
            break;
        }
    }
    cout << cont << endl;

    return 0;
}   