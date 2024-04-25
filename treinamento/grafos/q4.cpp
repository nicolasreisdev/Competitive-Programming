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
    int n, l , c, cont = 0; cin >> n;
    for(int i = 0; i < n;i++){
        cin >> l >> c;
        if(l > c){
            cont+=c;
        }
    }
    cout << cont << endl;
    return 0;
}