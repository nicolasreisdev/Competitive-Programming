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

typedef long long ll;
typedef pair<ll, ll> p;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

int main()
{
    fastio;

    int n;
    cin >> n;
    map<ll, int> v;
    vector<p> vp;

    for (int i = 0; i < n; i++)
    {
        ll l, r;
        cin >> l >> r;
        v[l]++;
        v[r + 1]--;
        vp.pb({l, r});
    }

    ll ans = 0, maxinter = 0, maxinterpos = -1;

    for (auto [pos, delta] : v)
    {
        ans += delta;
        if (ans > maxinter)
            maxinter = ans, maxinterpos = pos;
    }

    cout << maxinter << endl;

    for (int i = 0; i < n; i++)
    {

        if (vp[i].f <= maxinterpos && maxinterpos <= vp[i].s)
        {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}