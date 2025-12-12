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

ll cont = 0, maior = 0;

void collatz(long long int n)
{
    if (n == 1)
    {
        cont++;
        return;
    }
    cont++;
    if (n % 2 == 1)
    {
        collatz((3 * n) + 1);
    }
    else
    {
        collatz(n / 2);
    }
}

int main()
{
    fastio;
    ll  c, d, a, b;
    bool troc = true;
    while (cin >> c >> d)
    {
        troc = false;
        maior = 0;
        if (c > d)
        {
            swap(c, d);
            troc = true;
        }
        for (ll  i = c; i <= d; i++)
        {
            collatz(i);
            if (cont > maior)
                maior = cont;
            cont = 0;
        }
        if (troc)
            swap(c, d);
        cout << c << " " << d << " " << maior << endl;
    }

    return 0;
}
