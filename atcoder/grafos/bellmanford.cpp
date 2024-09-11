#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second
#define sz size
#define in insert

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;


int n, m; // n = numero de vertices, m = numero de arestas
int d[MAX]; // distancia de um vertice a outro
vii ar; // arestas, first = vertice de origem, second = vertice de destino
vector<int> w; // peso das arestas

bool BellmanFord(int a){
    for(int i = 0; i < n;i++)d[i] = MAX; // inicializa as distancias
    d[a] = 0; // distancia do vertice de origem a ele mesmo é 0

    for(int i = 0; i <= n;i++){ // roda n vezes, pois o caminho mais longo entre dois vertices é n-1 arestas
        for(int j = 0; j < m;j++){
            if( d[ar[j].first] + w[j] < d[ar[j].second]){ // se a distancia do vertice de origem + o peso da aresta for menor que a distancia do vertice de destino
                if(i == n)return true; // se o algoritmo rodar n-1 vezes e ainda for possivel relaxar a aresta, tem ciclo negativo
                d[ar[j].second] = d[ar[j].first]+ w[j]; // atualiza a distancia do vertice de destino
            }
        }
    }
    return false; // se nao tiver ciclo negativo
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        ar.pb({a, b});
        w.pb(c);
    }
    if(BellmanFord(0))cout << "Ciclo negativo\n";
    else cout << "Nao tem ciclo negativo\n";
    return 0;
}