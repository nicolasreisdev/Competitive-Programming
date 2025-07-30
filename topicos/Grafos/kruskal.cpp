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

// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// DSU data structure
// path compression + rank by union
class DSU{
    int *parent; // Vetor de pais
    int *rank; // Vetor de rank

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

class Graph{
    vector<vector<int>> edgelist;
    int V;

public:
    Graph(int V) { this->V = V; }

    // Function to add edge in a graph
    void addEdge(int x, int y, int w){
        edgelist.push_back({w, x, y}); // {weight, from, to}
    } 

    void kruskals_mst(){
        // Sort all edges
        sort(edgelist.begin(), edgelist.end()); // Sort

        // Initialize the DSU
        DSU s(V); // DSU
        int ans = 0; // Cost of MST
        for (auto edge : edgelist){ // For all edges    
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // Take this edge in MST if it does
            // not forms a cycle
            if (s.find(x) != s.find(y)){ 
                s.unite(x, y);
                ans += w;
                cout << x << " -- " << y << " == " << w << endl;
            }
        }
        cout << "Minimum Cost Spanning Tree: " << ans;
    }
};




// Outro código

struct dsu{
    vector<int> parent, size;
    dsu(int n){
        parent.resize(n);                      // Vetor de pais
        size.resize(n, 1);                     // Vetor de tamanho
        iota(parent.begin(), parent.end(), 0); // Inicializa o vetor de pais
    }

    int find(int x){
        return parent[x] == x ? x : parent[x] = find(parent[x]); // Path compression
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if (x != y)
        {
            if (size[x] < size[y])
                swap(x, y); // por tamanho
            parent[y] = x;
            size[x] += size[y];
        }
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    int get_size(int x){
        return size[find(x)];
    }
};

vector<tuple<int, int, int>> edges; // {weight, from, to}

pair<ll, vector<tuple<int, int, int>>> kruskal(int n){
    dsu dsu(n); // Inicializa a DSU
    ll cost = 0; // Custo total da MST
    vector<tuple<int, int, int>> mst; // Arestas da MST
    sort(edges.begin(), edges.end()); // Ordena as arestas de acordo com o peso
    for(auto [w, u, v] : edges){ // Para cada aresta
        if(dsu.find(u) != dsu.find(v)){ // Se u e v não estão na mesma componente
            dsu.unite(u, v); // Une u e v
            cost += w; // Adiciona o peso da aresta ao custo total
            mst.pb({w, u, v}); // Adiciona a aresta à MST
        }
    }
    return {cost, mst}; // Retorna o custo total e as arestas da MST
}


// Driver code
int main(){
    Graph g(11); 
    g.addEdge(0, 1, 10);// {weight, from, to}
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);

    // Function call
    g.kruskals_mst();

    return 0;
}