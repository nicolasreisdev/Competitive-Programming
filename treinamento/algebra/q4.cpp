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
    string n; cin >> n;
    string j = n;
    int k, l, m;
    for(int i = 0; i < 5;i++){
        j = n;
        reverse(n.begin(), n.end());
        if(stoi(n) == stoi(j)){
            cout << j << endl;
            return 0;
        }
        else{
            k = stoi(n);
            l = stoi(j);
            m = k + l;
            n = to_string(m);
        }
    }
    cout << 0 << endl;

    return 0;
}