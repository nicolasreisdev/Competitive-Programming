#include <bits/stdc++.h>
using namespace std;

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* FUNCTIONS */
#define f(i, s, e) for (long long int i = s; i < e; i++)
#define cf(i, s, e) for (long long int i = s; i <= e; i++)
#define rf(i, e, s) for (long long int i = e - 1; i >= s; i--)
#define pb push_back

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

/* PRINT */
template <class T>
void print_v(vector<T> &v)
{
    cout << "{";
    for (auto x : v)
        cout << x << ",";
    cout << "\b}";
}

void solve();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

vector<long long> getSieve(long long n)
{
    // Inicializa tudo com 0. Ao final, quem
    // ainda tiver 0 vai ser primo.
    vector<long long> sieve(n + 1, 0);
    // Em geral 0 e 1 não são usados.
    sieve[0] = 1;
    sieve[1] = 2;
    for (long long x = 2; x <= n; x++)
    {
        if (sieve[x])
            continue;
        for (long long u = 2 * x; u <= n; u += x)
        {
            if (!sieve[u])
                sieve[u] = x;
        }
    }
    return sieve;
}

void solve()
{
    long long n;
    cin >> n;
    vector<long long> sieve = getSieve(sqrt(n));
    //cout << sqrt(n) << endl;
    ll root = sqrt(n);
    for (long long i = 2; i <= root; i++)
    {
        if (sieve[i] == 0)
        {
            if (n % i == 0)
            {
                //cout << n / i << endl;
                if (sieve[n / i] == 0)
                {
                    cout << 1 << endl;
                    return;
                }
            }
        }
    }
    cout << 0 << endl;
}