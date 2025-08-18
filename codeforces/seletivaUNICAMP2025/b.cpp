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

int main()
{
    fastio;
    int n; cin >> n;
    int finalSeq = 1, atSeq = 1, x; cin >> x;
    int init = x;
    for(int i = 1; i < n;i++){
        cin >> x;
        if(x-1 == init)atSeq++;
        else atSeq = 1;
        if(atSeq > finalSeq) finalSeq = atSeq;
        init = x;
    }
    cout << finalSeq << endl;

    return 0;
}