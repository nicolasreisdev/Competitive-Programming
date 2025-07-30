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
const int MAX = 2 * 1e5 + 1;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

int parent[MAX];
int tam[MAX];

void start(int n){
    for(int i = 0; i < n;i++){
        parent[i] = i;
        tam[i] = 1; // A principio, cada conjunto possui apenas ele mesmo
    }
}

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]); // Path compression
}

void merge(int x, int y){
    int a = find(x);
    int b = find(y);
    if(a == b) return; // se ja estiverem no mesmo conjunto
    if(tam[a] > tam[b]) swap(a, b); // garante que o conjunto de menor tamanho sera adicionado ao de maior tamanho
    parent[a] = b;
    tam[b] += tam[a];
}


int main(){
    fastio;



    return 0;
}