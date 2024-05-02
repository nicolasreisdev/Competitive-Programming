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

int main(){
    int n; cin >> n;
    for(int i = 0; i < n;i++){
        int a, sum = 0; cin >> a;
        for(int j = 0; j < a; j++){
            int b; cin >> b;
            sum++;
        }
        if(sum%2==1 || sum==2) cout << 2 << endl;
        else cout << 3 << endl;
    }
    return 0;
}