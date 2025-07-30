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

bool check(ll x, ll m, ll k, vector<ll> v){
    ll sum = 0;
    ll cnt = 1;
    for (int i = v.size() - 1; i >= 0; i--){
        if (sum + v[i] > x){
            cnt++;
            sum = v[i];
        }
        else sum += v[i];

    }
    return cnt <= k;
}

void binarySearch(ll l, ll r, vector<ll> v, ll m, ll k){
    // bool flag[m];
    while (l < r){
        ll mid = (l + r) / 2;
        if (check(mid, m, k, v))
            r = mid;
        else
            l = mid + 1;
    }
    ll sum = 0;
    bool flag[m + 1];
    k--;
    for (int i = v.size() - 1; i >= 0; i--){
        // cout << i << " " << k << endl;
        if (sum + v[i] > r){
            // ans += "/ ";
            flag[i] = true;
            sum = v[i];
            k--;
        }
        else if (i + 1 == k){
            // ans += "/ ";
            flag[i] = true;
            k--;
        }
        else{
            sum += v[i];
            flag[i] = false;
        }
        // ans += to_string(v[i]);
        // ans += ' ';
    }
    // reverse(ans.begin(), ans.end());
    for (int i = 0; i < v.size() - 1; i++){
        cout << v[i] << " ";
        if (flag[i])
            cout << "/ ";
    }
    cout << v[v.size() - 1] << endl;
}

int main(){
    fastio;

    int t;
    cin >> t;
    while (t){
        ll r = 0, l = 0;
        ll m, k;
        cin >> m >> k;
        vector<ll> v;
        for (int i = 0; i < m; i++){
            ll x;
            cin >> x;
            r += x;
            l = max(l, x);
            v.pb(x);
        }
        binarySearch(l, r, v, m, k);

        t--;
    }

    return 0;
}