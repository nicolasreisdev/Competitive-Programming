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
// #define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

bool checkIndependentSet(vector<bitset<41>> &adj, ll n, bitset<41> mask)
{
    for (int i = 0; i < n; i++)
    {
        if (mask[i])
        {
            bitset<41> helpMask = mask & adj[i];
            if (helpMask.any())
                return false;
        }
    }
    return true;
}

vector<bitset<41>> bitMask(vector<bitset<41>> &adj, ll start, ll end){
    vector<bitset<41>> subSet;
    for (int i = start; i < (1<<(end-start)); i++){
        bitset<41> mask;

        for(int j = 0; j < (end-start); j++){
            if((i >> j) & 1) mask.set(start + j);
        }

        if(checkIndependentSet(adj, mask.size() ,mask)){
            subSet.pb(mask);
        }
    }
    return subSet;
}

auto comparator = [](const bitset<41> &a, const bitset<41> &b){
    return a.count() < b.count();
};

int main(){
    fastio;

    int n, m;
    cin >> n >> m;
    vector<bitset<41>> adj(n);
    for (int i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].set(v);
        adj[v].set(u);
    }

    vector<bitset<41>> sub1 = bitMask(adj, 0, n/2);
    vector<bitset<41>> sub2 = bitMask(adj, n/2, n);

    sort(sub1.begin(), sub1.end(), comparator);
    sort(sub2.begin(), sub2.end(), comparator);

    ll valid = 0;
    bitset<41> ans;
    for (int i = sub1.size()-1; i >= 0 ; i--){
        if(sub1[i].count() + sub2[sub2.size()-1].count() <= valid) continue;
        for (int j = sub2.size()-1; j >= 0 ; j--){
            if (sub1[i].count() + sub2[j].count() <= valid) continue;

            bitset<41> newSet = sub1[i] | sub2[j];
            if(checkIndependentSet(adj, newSet.size(), newSet)){
                ans = newSet;
                valid = newSet.count();
            }
        }
    }

    cout << valid << endl;
    for(int i = 0; i < ans.size();i++){
        if(ans[i]) cout << i << " ";
    }
    cout << endl;

    return 0;
}