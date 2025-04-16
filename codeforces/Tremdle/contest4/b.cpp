#include <bits/stdc++.h>
using namespace std;


#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cint.tie(0);

typedef long long ll;


int main(){

    int a, b, c; cin >> a >> b >> c;

    int x = a*b/c, y = a*c/b, z=b*c/a;
    cout << 4*sqrt(x+y+z) << endl;


    return 0;
}