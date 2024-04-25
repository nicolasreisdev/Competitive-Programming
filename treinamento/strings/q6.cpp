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
    string n, m;
    getline(cin, n);
    getline(cin, m);
    for(int i = 0; i < n.size();i++){
        if(n[i] != m[i]){
            cout << 0 << endl;
            return 0;
        }
    }
    cout << 1 << endl;

    return 0;
}