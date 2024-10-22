#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
//#define f first
#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;


bool f(vector<int> &v,ll x, int mediana, ll sum, int n){
    double media = ((double)(sum+x)/(double)n);
    //cout << sum << " " << x << " " << media <<  endl;
    if(media > mediana) return false;
    return true;
}


ll binarySearch(ll l, ll r, vector<int> &v, int mediana, ll sum, double media, ll qntd){
    ll mid;
    
    while(l < r){
        mid = l+(r-l+1)/2;
        if(!f(v, mid, mediana, sum, qntd))r = mid-1;
        else l = mid;
    }
    return r+1;
}


int main(){
    fastio;


    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        ll sum = 0;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            sum += v[i];
        }
        sort(v.begin(), v.end());
        //cout << t << endl;
        if (n == 1 || n == 2){
            cout << -1 << endl;
            continue;
        }
        double media = ((double)sum/(double)(n*2));
        int mediana;
        if(n % 2 == 0) mediana = v[n/2];
        else mediana = v[n/2];
        //cout << media << " " << mediana << endl;
        if(media <= mediana){
            ll ans = binarySearch(0, 10000000000000000LL, v, mediana, sum, media, n*2);
            cout << ans << endl;
        }
        else cout << 0 << endl;
    }

    return 0;
}