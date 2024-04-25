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
    int n, k, x = 0, cont = 0, t = 0, j = 0; cin >> n >> k;
    int v[n];
    for(int i = 0; i < n;i++){
        cin >> v[i];
    }
    int i = 0;
    bool b = false;
    while(!b){
        cont+=v[i];
        t++;
        if(cont >= k){
            b = true;
        }
        i+=2;
        if(i >= n){
            i = 0;
        }
    }
    cont  = 0; i = 1;
    bool a = false;
    while(!a){
        cont += v[i];
        j++;
        if (cont >= k) a = true;
        i+=2;
        if(i >= n){
            i = 1;
        }
    }
    if(t<=j)cout << t << endl;
    else cout << j << endl;
    return 0;
}