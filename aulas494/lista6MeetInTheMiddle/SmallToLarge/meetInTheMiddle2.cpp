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

set<ll> subSum(vector<ll> &v, int start, int end, ll m){

    set<ll> sums = {0}; // vazio

    for (int i = start; i < end; i++){
        set<ll> help;
        for (ll s : sums){
            help.insert(s);               
            help.insert((s + v[i]) % m);
        }
        swap(sums, help);
    }
    return sums;
}

int main(){
    fastio;

    ll n, m;
    cin >> n >> m;

    vector<ll> v(n); 
    for (int i = 0; i < n; i++)
        cin >> v[i];

    set<ll> sums1 = subSum(v, 0, n/2, m);
    set<ll> sums2 = subSum(v, n/2, n, m);

    ll ans = 0;

    if (!sums1.empty())
        ans = max(ans, *sums1.rbegin());
    if (!sums2.empty())
        ans = max(ans, *sums2.rbegin());

    vector<ll> search(sums1.begin(), sums1.end());

    for (ll s2 : sums2){ // caso o maximo seja um elemento de sums1 + um elemento de sums2

        ll target = m - s2;
        int left = 0;
        int right = sums1.size() - 1;
        int idx = -1; 

        while (left <= right)
        {
            int mid = (right + left) / 2;

            if (search[mid] < target){
                idx = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        if (idx != -1){
            ans = max(ans, (s2 + search[idx]) % m);
        }
    }

    cout << ans << endl;

    return 0;
}