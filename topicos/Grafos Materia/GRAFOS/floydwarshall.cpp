/*
README
Aluno: Nicolas Eliel dos Reis Silva - Matrícula: 112703
Fontes de consulta: nenhuma.
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
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

int main()
{
    fastio;

    int n, e;
    cin >> n >> e;
    int cont = 1;

    while (n != 0 && e != 0){
        map<string, int> m;
        vector<vector<int>> g(n, vector<int>(n, 0));
        for (int i = 0; i < e; i++){
            string a, b;
            int x;
            cin >> a >> b >> x;
            if (m.find(a) == m.end()){ // se nao existe
                m[a] = m.size();
                // cout << a << " " << m[a] << endl;
                g[m[a]][m[a]] = MAX; // distancia de um vertice para ele mesmo é MAX
            }
            if (m.find(b) == m.end()){ // se nao existe
                m[b] = m.size();
                // cout << b << " " << m[b] << endl;
                g[m[b]][m[b]] = MAX; // distancia de um vertice para ele mesmo é MAX
            }
            g[m[a]][m[b]] = x;
            g[m[b]][m[a]] = x;
        }
        for (int k = 0; k < n; k++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    g[i][j] = max(g[i][j], min(g[i][k], g[k][j])); // encontra a aresta de maior peso
                }
            }
        }
        string x, y;
        cin >> x >> y;
        cout << "Scenario #" << cont << endl;
        cout << g[m[x]][m[y]] << " tons" << endl;
    }

    return 0;
}