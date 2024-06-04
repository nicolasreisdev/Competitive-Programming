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
    int n; cin >> n;
    while(n--){
        string x; cin >> x;
        if(x.size() > 10)cout << x[0] << x.size()-2 << x[x.size()-1] << endl;
        else cout << x << endl;
        
    }
    return 0;
}