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
double eps = 1e-9;


double f(double x, int p, int q, int r, int s, int t, int u){
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double binarySearch(double b, double e, int p, int q, int r, int s, int t, int u){
    while(e - b > eps){
        double m = (b + e) / 2.0;
        if (f(m, p, q, r, s, t, u) < eps)
            e = m;
        else b = m;
    }
    return (b + e) / 2.0;
}


int main(){
    fastio;
    double p, q, r, s, t, u;
    while(cin >> p >> q >> r >> s >> t >> u){
        double b = 0.0, e = 1.0;
        double ans = binarySearch(b, e, p, q, r, s, t, u);
        if (f(0, p, q, r, s, t, u) * f(1, p, q, r, s, t, u) > 0)cout << "No solution" << endl;
        else cout << fixed << setprecision(4) << ans << endl;
    }
    return 0;
}