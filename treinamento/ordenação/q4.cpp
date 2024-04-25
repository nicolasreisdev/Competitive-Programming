#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5 + 10;

int main()
{
    int n; cin >> n;
    vector<string> v;
    string aux;
    for(int i = 0; i < n;i++){
        cin >> aux;
        v.pb(aux);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n;i++){
        cout << v[i] << endl;
    }

    return 0;
}