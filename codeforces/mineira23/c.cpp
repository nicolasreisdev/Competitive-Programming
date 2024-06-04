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
    string x; cin >> x;
    set<char>s;
    int v[256];
    for(int i = 0; i < x.size();i++){
        if(s.find(x[i]) == s.end()){
            s.in(x[i]);
            v[x[i]] = 1;
        }
        else v[x[i]]++;
    }
    

    return 0;
}