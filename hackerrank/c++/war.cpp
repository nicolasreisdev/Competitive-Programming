#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
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

int pai[MAX];
int tam[MAX];   


int amigos(int x){
    return x;
}

int inimigos(int x){
    return x + MAX/2;
}


void init(){
    for(int i = 0; i < MAX/2; i++){ // metade do vetor é para os amigos
        pai[i] = i;
        tam[i] = 1;
    }
    for(int i = MAX/2 + 1; i < MAX; i++){ // metade do vetor é para os inimigos
        pai[i] = 0;
        tam[i] = 0;
    }
}


int find(int x){
    if(pai[x] == x || pai[x] == 0) return x;
    return pai[x] = find(pai[x]);
}

int same(int x, int y){
    return find(x) == find(y);
}

void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(tam[x] < tam[y]) swap(x, y);
    pai[y] = x;
    tam[x] += tam[y];
} 


int main(){
    fastio;

    int n, op, x, y;
    cin >> n;
    init();
    while(true){
        cin >> op >> x >> y;
        if(!op) break;
        if(op == 1){
            if(same(amigos(x), inimigos(y)) || same(amigos(y), inimigos(x))) cout << -1 << endl;
            else{
                merge(amigos(x), amigos(y));
                merge(inimigos(x), inimigos(y));
            }
        }
        else if(op == 2){
            if(same(amigos(x), amigos(y)) || same(inimigos(x), inimigos(y))) cout << -1 << endl;
            else{
                merge(amigos(x), inimigos(y));
                merge(inimigos(x), amigos(y));
            }
        }
        else if(op == 3){
            cout << same(amigos(x), amigos(y)) << endl;
        }
        else if(op == 4){
            cout << same(amigos(x), inimigos(y)) << endl;
        }
    }

    return 0;
}