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

int main(){
    fastio;

    int n, m; cin >> n >> m;
    vector<int> cities(n);
    vector<int> towers(m);
    for(int i = 0; i < n;i++)cin >> cities[i];
    for(int i = 0; i < m;i++) cin >> towers[i];

    int ans = 0;
    for(int city = 0, tower = 0; city < n;city++){
        while (tower + 1 < m and abs(cities[city] - towers[tower + 1]) <= abs(cities[city] - towers[tower])) tower++;
        ans = max(ans, abs(cities[city] - towers[tower]));
    }

    cout << ans << endl;

    return 0;
}