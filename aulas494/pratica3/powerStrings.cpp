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

    string s;
    while(cin >> s and  s != "."){

        vector<int> z = z_function(s);
        int n = s.size();

        int ans = 1; // ela mesma

        for (int i = 1; i < n; i++){
            if (n % i == 0){
                if (i + z[i] == n){
                    ans = n / i;
                    break;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}