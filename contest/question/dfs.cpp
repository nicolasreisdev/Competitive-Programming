#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second

typedef pair<int, int> p;
typedef long long ll;
bool 
int main(){
    int x, y, n;
    cin >> n;
    vector<int>a[n];
    for(int i = 0; i < n;i++){
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }


    return 0;
}