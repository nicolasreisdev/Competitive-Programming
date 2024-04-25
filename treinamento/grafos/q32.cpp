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
const int MAX = 1e5 + 10;
const int MIN = 0;

int main()
{
    int n, k, x, j, k, cont = 0, l = 0;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++){
        cin >> x;
        v.pb(x);
    }
    sort(v.begin(), v.end());
    j = v[n-1]; k = v[n-2];
    bool a = true;
    while(!a)
    {
        cont += j;
        l++;
        if (cont >= k)
            a = true;
        cont += k;
        l++;
        if (cont >= j)
            a = true;
    }
    cout << l << endl;
    return 0;
}