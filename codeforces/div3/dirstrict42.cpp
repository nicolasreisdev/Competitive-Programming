#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
#define f first
//#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

int main(){
    fastio;

    int n, ans = 0; cin >> n;
    string s;
    for(int i = 1; i <= n;i++){
        s += to_string(i);
    }
    for(int i = 1; i < s.size();i++){
        if(s[i] == '4' && s[i+1] == '2'){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}