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

ll timer = 0;
void eulerTour(vector<vector<int>> &g, int v, int parent, vector<int> &start, vector<int> &end){
    start[v] = timer;
    timer++;
    for (int &u : g[v]){
        if (u != parent)
            eulerTour(g, u, v, start, end);
    }
    end[v] = timer;
}

int main(){
    fastio;

    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n + 1);
    vector<int> start(n + 1);
    vector<int> end(n + 1);
    for (int i = 1; i < n; i++){
        int parent;
        cin >> parent;
        g[parent - 1].push_back(i);
    }
    eulerTour(g, 0, -1, start, end);
    vector<vector<int>> conjunto(q);
    for (int i = 0; i < q; i++){
        int mj;
        cin >> mj;
        for (int j = 0; j < mj; j++){
            int funcionario;
            cin >> funcionario;
            conjunto[i].push_back(funcionario - 1);
        }
        sort(conjunto[i].begin(), conjunto[i].end());
        ll sum = 0;
        for (int j = 0; j < mj; j++){
            bool isParent = false;
            for (int k = j; k < mj; k++){
                if (conjunto[i][k] != conjunto[i][j]){
                    if ((start[conjunto[i][j]] < start[conjunto[i][k]] && end[conjunto[i][j]] >= end[conjunto[i][k]])){
                        isParent = true;
                    }
                }
            }
            if (!isParent)
                sum++;
        }
        cout << sum << endl;
    }

    return 0;
}