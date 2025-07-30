#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

#define all(x) x.begin(), x.end()

struct block_cut_tree
{
    vector<vector<ll>> g, blocks, tree;
    vector<vector<pair<ll, ll>>> edgblocks;
    stack<ll> s;
    stack<pair<ll, ll>> s2;
    vector<ll> id, art, pos;

    block_cut_tree(vector<vector<ll>> g_) : g(g_)
    {
        ll n = g.size();
        id.resize(n, -1), art.resize(n), pos.resize(n);
        build();
    }

    ll dfs(ll i, ll &t, ll p = -1)
    {
        ll lo = id[i] = t++;
        s.push(i);

        if (p != -1)
            s2.emplace(i, p);
        for (ll j : g[i])
            if (j != p and id[j] != -1)
                s2.emplace(i, j);

        for (ll j : g[i])
            if (j != p)
            {
                if (id[j] == -1)
                {
                    ll val = dfs(j, t, i);
                    lo = min(lo, val);

                    if (val >= id[i])
                    {
                        art[i]++;
                        blocks.emplace_back(1, i);
                        while (blocks.back().back() != j)
                            blocks.back().push_back(s.top()), s.pop();

                        edgblocks.emplace_back(1, s2.top()), s2.pop();
                        while (edgblocks.back().back() != pair(j, i))
                            edgblocks.back().push_back(s2.top()), s2.pop();
                    }
                    // if (val > id[i]) aresta i-j eh ponte
                }
                else
                    lo = min(lo, id[j]);
            }

        if (p == -1 and art[i])
            art[i]--;
        return lo;
    }

    void build()
    {
        ll t = 0;
        for (ll i = 0; i < g.size(); i++)
            if (id[i] == -1)
                dfs(i, t, -1);

        tree.resize(blocks.size());
        for (ll i = 0; i < g.size(); i++)
            if (art[i])
                pos[i] = tree.size(), tree.emplace_back();

        for (ll i = 0; i < blocks.size(); i++)
            for (ll j : blocks[i])
            {
                if (!art[j])
                    pos[j] = i;
                else
                    tree[i].push_back(pos[j]), tree[pos[j]].push_back(i);
            }
    }

    ll bfs_res(ll s, ll e)
    {
        set<ll> not_ponte;
        for (auto e : pos)
            not_ponte.insert(e);
        vector<ll> d(tree.size(), INF), p(tree.size(), -1);
        d[s] = 0;
        queue<ll> q;
        q.push(s);

        while (q.size())
        {
            ll u = q.front();
            q.pop();
            // cout << "Visitando " << u << endl;

            for (auto v : tree[u])
                if (d[v] == INF)
                {
                    if (d[u] + 1 < d[v])
                        d[v] = d[u] + 1;
                    p[v] = u;

                    q.push(v);
                    // cout << "Adicionando " << v << endl;
                }
        }

        vector<ll> path;
        path.push_back(e);
        while (e != s)
        {
            if (not_ponte.find(p[e]) != not_ponte.end())
                path.push_back(p[e]);
            e = p[e];
        }
        return path.size();
    }
};