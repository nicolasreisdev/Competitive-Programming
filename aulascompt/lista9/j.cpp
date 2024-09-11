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

    int main(){
        fastio;

        int n; cin >> n;
        vector<vector<int>> g(n+2, vector<int>(n+2));
        vector<ll> ans;
        for(int i = 1; i <= n;i++){
            for(int j = 1; j <= n;j++){
                cin >> g[i][j];
            }
        }
        int delet[n+1]; // vertices deletados
        bool flag[n+1]; // flag para saber se o vertice foi deletado
        memset(flag, false, sizeof(flag));
        for(int i = 1; i <= n;i++){
            cin >> delet[i];
        }
        ll sum = 0;
        for(int k = n; k > 0;k--){
            int u = delet[k];
            flag[u] = true; // vertice foi deletado
            sum = 0;
            for(int i= 1; i <= n;i++){
                for(int j = 1; j <= n;j++){
                    g[i][j] = min(g[i][j], g[i][u] + g[u][j]); // utilizando o vertice deletado 
                    if(flag[i] && flag[j]){ // se os dois vertices foram deletados
                        sum += g[i][j];
                    }
                }
            }
            ans.pb(sum);
        }
        for(int i = ans.size()-1; i >= 0;i--){
            cout << ans[i] << " ";
        }


        return 0;
    }