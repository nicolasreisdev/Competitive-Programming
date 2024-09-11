#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
#define f first
#define s second
//#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 2*1e5+1;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

int parent[MAX];
int tam[MAX];

void start(){ // inicializa o vetor de pais e o vetor de tamanhos
    for(int i = 1; i < MAX/2; i++){
        parent[i] = i;
        tam[i] = i;
    }
    for (int i = MAX/2+1; i < MAX; i++){
        parent[i] = 0;
        tam[i] = 0;
    }
}

int friends(int x){ // retorna o amigo de x
    return x;
}

int enimies(int x){ // retorna o inimigo de x
    return MAX/2 + x;
}

int find(int x){ // encontra o pai de x
    if(parent[x] == x || parent[x] == 0){ // se x é o pai de x ou x é 0
        return x;
    }
    return parent[x] = find(parent[x]);
}

int same(int x, int y){ // verifica se x e y são do mesmo grupo
    return (find(x) == find(y));
}

void merge(int x , int y){ // junta os grupos de x e y
    int a = find(x);
    int b = find(y);
    if(tam[a] < tam[b]){
        swap(a,b);
    }
    parent[b] = a;
    tam[a] += tam[b];
}

int main(){
    fastio;
    start();
    int n; cin >> n;
    int c, x, y;
    while(cin >> c >> x >> y && c || x || y){
        if(c == 1){ // se são amigos
            if(same(friends(x), enimies(y))){ //se os amigos de x são inimigos de y
                cout << -1 << endl;
            }
            else{ 
                merge(friends(x), friends(y)); // se não, x e y são amigos
                merge(enimies(x), enimies(y)); // e os inimigos de x são inimigos de y
            }
        }
        else if(c == 2){ // se são inimigos
            if (same(friends(x), friends(y))){ // se os amigos de x são amigos de y
                cout << -1 << endl;
            }
            else{
                merge(friends(x), enimies(y)); // se não, x e y são inimigos
                merge(enimies(x), friends(y)); // e os inimigos de x são amigos de y
            }
        }
        else if(c == 3){
            cout << same(friends(x), friends(y)) << endl;
        }
        else if(c == 4){
            cout << same(friends(x), enimies(y)) << endl;
        }
    }

    return 0;
}