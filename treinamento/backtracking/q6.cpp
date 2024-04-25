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
    int x, a, b; cin >> x;
    vector<int> v;
    for(int i = 0; i < x;i++){
        cin >> a;
        for(int j  = 0; j < a;j++){
            for(int k = 0; k < a;k++){
                cin >> b;
                v.pb(b);
            }
        }
    }
    return 0;
}