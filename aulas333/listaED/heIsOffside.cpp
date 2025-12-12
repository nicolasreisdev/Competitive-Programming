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

    int a, d;
    while (cin >> a >> d and a != 0 and d != 0){
        vector<int> atack(a), defend(d);
        for(int i = 0; i < a;i++) cin >> atack[i];
        for(int i = 0; i < d;i++) cin >> defend[i];

        sort(atack.begin(), atack.end());
        sort(defend.begin(), defend.end());
        if(defend[1] <= atack[0]) cout << "N" << endl;
        else cout << "Y" << endl; 
    }

    return 0;
}