#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
double eps = 1e-9;

double f(double x, vector<int> &v){
    double ans = v[0];
    for(int i = 1; i < v.size(); i++){
        ans += v[i] / pow(1+x, i);
    }
    //cout << ans << " " << x << endl;
    return ans;
}


double binarySearch(double b, double e, vector<int> &v){
    while(e - b > eps){
        double m = (b + e) / 2;
        if (f(m, v) <= eps)e = m;
        else b = m;
    }
    return (b + e) / 2;
}


int main(){
    fastio;

    int t;cin >> t;
    while(t!=0){
        vector<int> v(t+1);
        for(int i = 0; i < t+1; i++){
            cin >> v[i];
        }
        double b = -1, e = numeric_limits<double>::max();
        double ans = binarySearch(b, e, v);
        if(abs(ans+1.00)<= eps) cout << "No" << endl;
        else cout << fixed << setprecision(2) << ans <<  endl;

        cin >> t;
    }

    return 0;
}