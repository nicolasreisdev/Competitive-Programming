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

int main(){
    int n, last = 0; cin >> n;
    while(n--){
        string x; cin >> x;
        if(x == "X++" || x == "++X")last++;
        else last--;
    }
    cout << last << endl;
    return 0;
}