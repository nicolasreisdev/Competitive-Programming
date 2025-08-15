#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
//#define f first
//#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long double ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

void solve(ll m, ll f)
{
    ll prox1 = m - (1.0), prox2 = f - (1.0);
    ll probb1, probb2;
    if (prox1 <= 0 || m <= 0)
    {
        cout << ":-\\" << endl;
        return;
    }
    probb1 = f / m;
    probb2 = prox2 / prox1;
    if (probb1 > 1.0)
        probb1 = 1.0;
    if (probb2 > 1.0)
        probb2 = 1.0;
    if (probb1 < probb2)
        cout << ":-)" << endl;
    else if (probb1 == probb2)
        cout << ":-|" << endl;
    else if (probb1 > probb2)
        cout << ":-(" << endl;
}

int main()
{
    ll m, f;
    int i = 1;
    cin >> m >> f;
    while (m != 0 || f != 0)
    {
        cout << "Case " << i << ": ";
        solve(m, f);
        cin >> m >> f;
        i++;
    }

    return 0;
}