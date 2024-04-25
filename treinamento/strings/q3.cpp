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
    string n;
    getline(cin, n);
    for(int i = 0; i < n.size();i++){
        if(isupper(n[i])){
            cout << 0 << endl;
            return 0;
        }
    }
    return 0;
}