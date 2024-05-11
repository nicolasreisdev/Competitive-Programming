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
    while (n--){
        string x; cin >> x;
        bool flag = false, min = false;
        if(x.size() == 1){
            min = true;
        }
        if(!min){
            for(int i = 1; i < x.size();i++){
                if(x[i] != x[i-1]){
                    flag = true;
                    swap(x[i], x[i-1]);
                    break;
                }
            }
        }
        if(flag){
            cout << "YES" << endl;
            cout << x << endl;
        }
        else cout << "NO" << endl;
    }
    

    return 0;
}