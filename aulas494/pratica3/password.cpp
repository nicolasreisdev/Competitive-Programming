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

vector<int> z_function(string s){
    int n = s.size();
    vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; i++){
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}



int main(){
    fastio;

    string s; cin >> s;
    int n = s.size();
    vector<int> z = z_function(s);

    vector<int> freq(n + 1, 0);
    for (int i = 1; i < n; ++i){
        freq[z[i]]++;
    }

    vector<int> suffix(n + 1, 0);
    
    suffix[n] = freq[n];
    for (int i = n - 1; i >= 1; --i){
        suffix[i] = freq[i] + suffix[i + 1];
    }

    int ans = 0;
    for(int l = n-1; l >= 1; l--){
        if(z[n - l] == l and suffix[l] >= 2){ // verifica se o prefixo é sufixo e se possui outra ocorrência no meio
            ans = l;
            break;
        }
    }

    if(ans > 0) cout << s.substr(0, ans) << endl;
    else cout << "Just a legend" << endl;

    return 0;
}