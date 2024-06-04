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
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

int main(){
    ll g, d = 0, e = 0; cin >> g;
    string x; cin >> x;
    bool falg = false;
    for(int i = 0; i < x.size();i++){
        if(x[i] == 'E'){
            e+=g;
            d-=g;
        }
        else if(x[i] == 'D'){
            d+=g;
            e-=g;
        }
        if(d == 360 || e == 360 || d == -360 || e == -360){
            falg = true;
        }
    }
    if(falg)cout << "S" << endl;
    else cout << "N" << endl;
    return 0;
}