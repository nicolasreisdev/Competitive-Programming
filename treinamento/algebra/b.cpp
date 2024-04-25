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

void solve()
{
  int n;
  cin >> n;
  double t, i, a;
  double A, B, C, delta, x1, x2;
  while (n--)
  {
    cin >> t >> i >> a;
    A = a;
    B = 2 * i - a;
    C = -2 * t;
    delta = B * B - 4 * A * C;
    x1 = (-B + sqrt(delta)) / (2 * A);
    x2 = (-B - sqrt(delta)) / (2 * A);
    if (x1 > 0)
      cout << ceil(x1) << endl;
    else
      cout << ceil(x2) << endl;
  }
}