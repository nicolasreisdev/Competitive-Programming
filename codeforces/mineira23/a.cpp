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

int v[4];

int main(){
    int n; cin >> n;
    v[2] = 1; // local onde a peça está
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        swap(v[x], v[y]); // troca a peça de lugar
    }
    for(int i = 1; i <= 3; i++){
        if(v[i]){ 
            cout << i << endl; // imprime a posição da peça
        }
    }
    return 0;
}