#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second
#define sz size
#define in insert
 

typedef pair<int,int>p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

int main(){
    int n; cin >> n;
    while(n--){
        int cont = 0;
        bool flag = false;
        p a, b; cin >> a.f >> a.s >> b.f >> b.s;
        for(int i = a.f;; i++){
            //cout << i << " ";
            if(i == b.f or i == b.s) cont++;
            if (i == a.s) break;
            if (i == 12 && !flag){
                flag = true;
                i = 0;
            }
        }
        //cout << endl;
        if(cont == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}