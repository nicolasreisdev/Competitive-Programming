#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

typedef long long ll;
#define all(x) x.begin(), x.end()

const int MAX = 1e5+10;

bool visited[MAX];

vector<int> dfs(vector<vector<int>> &g, int i){
    visited[i] = true;
    for(auto e: g[i]){
        if(!visited[e]){
            vector<int> ans;
            ans = dfs(g, e);
            ans.push_back(i);
            return ans;
        }
    }
    vector<int> final;
    final.push_back(i);
    return final;
}

int main(){
    fastio;
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < m;i++){
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(m != 0){
        vector<vector<int>> times;
        int help = 0;
        vector<vector<int>> teamOne, teamTwo;
        for(int i = 0; i < n;i++){
            int qntd = 0;
            if(!visited[i]){
                vector<int> team;
                team = dfs(g, i);
                if(team.size() == 3){
                    times.push_back(team);
                    help+=3;
                }
                else if(team.size()==2) teamTwo.push_back(team);
                else if(team.size()==1) teamOne.push_back(team);
                else if(team.size() > 3){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
        if((n-help)%3!=0 or teamTwo.size() > teamOne.size() or (teamOne.size()-teamTwo.size())%3 != 0){
            cout << -1 << endl;
            return 0;
        }
        for(int i = 0; i < teamTwo.size();i++){
            vector<int> team;
            team.push_back(teamTwo[i][0]);
            team.push_back(teamTwo[i][1]);
            team.push_back(teamOne[i][0]);
            times.push_back(team);
        }
        for (int i = 0; i < times.size(); i++)
        {
            for (auto e : times[i])
                cout << e+1 << " ";
            cout << endl;
        }

        
    }
    if(m == 0){
        for(int i = 1; i <= n;i++){
            cout << i << " ";
            if(i%3==0)cout << endl;
        }
    }


    return 0;
}