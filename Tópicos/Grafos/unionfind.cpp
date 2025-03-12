#include <bits/stdc++.h>
using namespace std;
// Union Find por classificação de rank

// DSU data structure
// path compression + rank by union

// My DSU
class UnionFind
{
public:
    void createset(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent[x]); // path compression
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    void unite(int x, int y)
    {
        parent[find(x)] = find(y);
    }

private:
    vector<int> parent;
};



// ------------------------------ // --------------------------




class DSU{
    int *parent; // Vetor de pais
    int *rank;   // Vetor de rank

public:
    DSU(int n){
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // Find function
    int find(int i){
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    // Union function
    void unite(int x, int y){
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2){
            if (rank[s1] < rank[s2]){ // Rank
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2]){ // Rank
                parent[s2] = s1;
            }
            else{
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};



// Union Find por tamanho de conjunto

// DSU data structure

struct dsu{
    vector<int> parent, size;
    dsu(int n) {
        parent.resize(n); // Vetor de pais
        size.resize(n, 1); // Vetor de tamanho
        iota(parent.begin(), parent.end(), 0); // Inicializa o vetor de pais
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]); // Path compression
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (size[x] < size[y]) swap(x, y); // por tamanho
            parent[y] = x;
            size[x] += size[y];
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int get_size(int x) {
        return size[find(x)];
    }
};


// DSU Bipartido 

/* Une dois vertices e acha a qual um vertice pertence
    * 0 -> A
    * 1 -> B
    * -1 -> Não foi definido
    
    * Se os dois vertices pertencem a um mesmo conjunto, o grafo não é bipartido
    * Se um dos vertices não foi definido, ele passa a pertencer ao conjunto do outro
    * Se os dois vertices não foram definidos, um deles passa a pertencer ao conjunto A e o outro ao conjunto B
    * Se os dois vertices pertencem a conjuntos diferentes, não faz nada
    * Se um dos vertices pertence a um conjunto e o outro não foi definido, o vertice não definido passa a pertencer ao conjunto do outro
    Informa se a componente de um vertice é bipartida
*/

struct dsu{
    vector<int> id, sz, bip, c;

    dsu(int n) {
        id.resize(n);
        sz.resize(n, 1);
        bip.resize(n, 1);
        c.resize(n);
        iota(id.begin(), id.end(), 0);
    }


    int find(int x) {
        return id[x] == x ? x : id[x] = find(id[x]);
    }
    int color (int x) {
        return x == id[x] ? c[x] : c[x]^color(id[x]);
    }

    void unite(int x, int y) {
        bool change = color(x) == color(y);
        x = find(x);
        y = find(y);
        if(x == y) {
            if (change)bip[x] = 0;
            return;
        }
    
        if (sz[x] < sz[y]) swap(x, y);
        if(change) c[y] = 1;
        sz[x] += sz[y];
        id[y] = x;
        bip[x] &= bip[y];
    }
};
