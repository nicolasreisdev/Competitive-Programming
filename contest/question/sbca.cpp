#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5 + 10;

int main(){
    int n, h, cont =0;
    cin >> n >> h;
    int v[n];
    for(int i = 0; i < n;i++){
        cin >> v[i];
        if(v[i] <= h){
            cont++;
        }
    }
    cout << cont << endl;
    return 0;
}