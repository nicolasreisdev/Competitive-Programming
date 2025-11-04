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

int main(){

    freopen("diamond.in", "r", stdin); 
    freopen("diamond.out", "w", stdout);

    fastio;

    int n, k; cin >> n >> k;
    vector<int> v(n);
    vector<int> left(n), right(n);
    for(int i = 0; i < n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    left[0] = 1;
    for(int r = 1, l = 0; r < n;r++){
        while(v[r] - v[l] > k) l++;
        left[r] = max(left[r-1], r-l+1);
    }
    right[n-1] = 1;
    for(int l=n-2, r=n-1; l >= 0;l--){
        while(v[r]-v[l] > k)r--;
        right[l] = max(right[l+1], r-l+1);
    }
    int ans = 0;
    for(int i= 0 ; i < n-1;i++) ans = max(ans, left[i] + right[i+1]);
    cout << ans << endl;

    return 0;
}