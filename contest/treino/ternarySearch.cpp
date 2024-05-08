#include <bits/stdc++.h>
using namespace std;

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


double f(double x){
    return x*x + 2*x + 1;
}

double ternarySearch(double l, double r){
    double eps = 1e-9;
    while(r - l > eps){ // while the interval is greater than eps
        double m1 = l + (r - l) / 3; // divide the interval in 3 parts
        double m2 = r - (r - l) / 3; // divide the interval in 3 parts
        double f1 = f(m1); // evaluate f(x) in m1 and m2
        double f2 = f(m2); // evaluate f(x) in m1 and m2
        if(f1 < f2) r = m2;
        else l = m1;
    }
    return f(l); // return the minimum of f(x) in [l, r]


}


int main()
{
    return 0;
}