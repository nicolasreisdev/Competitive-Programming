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
    int t; cin >> t;
    while(t--){
        int ans = 4;
        int r; cin >> r;
        for (int i = 1; i < r; i++){
            for (int j = 1; j < r; j++){
                if (sqrt(i * i + j * j) >= r && sqrt(i * i + j * j) < r + 1){
                    ans++;
                }
            }
        }
        ans *= 4; // considerando a simetria
        if(sqrt(pow(r, 2) + pow(r, 2)) < r+1) ans+=4;
        cout << ans << endl;
    }
    return 0;
}