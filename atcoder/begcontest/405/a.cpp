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
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

int main()
{
    int r, x; cin >> r >> x;
    if(r >= 1600 && r <= 2999){
        if(x == 1){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    else if( r >= 1200 && r <= 2399){
        if(x == 2){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    else cout << "No" << endl;
    return 0;
}