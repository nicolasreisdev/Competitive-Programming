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

// typedef pair<int, int> p;
typedef long long ll;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e5 + 5;

int pref_hash[MAXN]; // pref_hash[i] = hash da substring s[0..i]
int cur_pot[MAXN];   // cur_pot[i] = p^i

const int m = 1e9 + 7;

int inv(int x)
{ // calcula o inverso de x mod m
    int res = 1;
    int y = m - 2;
    while (y)
    {
        if (y % 2)
            res = 1ll * res * x % m;
        x = 1ll * x * x % m;
        y /= 2;
    }
    return res;
}

int char_value(char c)
{
    if (islower(c))
        return c - 'a' + 1;
    else
        return c - 'A' + 27;
}

void pre_hash(string const &s, int p, int m)
{ // precalcula os hashes de todos os prefixos da string s
    pref_hash[0] = 0;
    cur_pot[0] = 1;
    for (int i = 0; i < s.size(); i++)
    {
        int prev_hash = i ? pref_hash[i - 1] : 0;
        pref_hash[i] = (prev_hash + (1ll * char_value(s[i]) * cur_pot[i] % m)) % m; // hash(s[0..i]) = hash(s[0..i-1]) + s[i]*p^i
        cur_pot[i + 1] = 1ll * cur_pot[i] * p % m;                                  // p^(i+1) = p^i * p
    }
}

int hash_interval(int l, int r, int m)
{                                                                    // calcula o hash da substring s[l..r]
    int res = ((pref_hash[r] - (l ? pref_hash[l - 1] : 0)) + m) % m; // Hash(l, r) = (PrefixHash(r) - PrefixHash(l-1))
    res = 1ll * res * inv(cur_pot[l]) % m;                           // divisão por p^l (aritmética modular)

    return res;
}

int main()
{
    fastio;

    string s;
    cin >> s;
    pre_hash(s, 53, m);
    int q;
    cin >> q;
    while (q--){
        int i, j;
        cin >> i >> j;
        int l = 0, r = s.size()-j, ans=0;
        while ( l <= r ){
            int mid = (l + r) / 2;
            if(mid == 0){
                l = mid+1;
                continue;
            }
            if(hash_interval(i, i+mid-1, m) == hash_interval(j,j+mid-1, m)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}