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
    int sum = 0, saltos = 0;
    bool flag = false;
    for(int i = 0; i < x.sz();i++){
        if(x[i]=='.'){
            sum--;
            flag = true;
        }
        if(x[i]=='x'){
            if(flag){
                sum = 1;
                saltos++;
                flag = false;
            }
            else sum++;
        }
        if(sum < 0){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << saltos << endl;

    return 0;
}