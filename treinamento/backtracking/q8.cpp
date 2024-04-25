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
int cont = 0;
void floodfill(vector<vector<int>>v ,int a ,int  b){
    if((v[a][b] == 1 || v[a][b] == 3) && a > 0 && b > 0 && a < v.sz() && b < v[0].sz()){
        cont++;
        floodfill(v, a+1, b);
        floodfill(v, a-1, b);
        floodfill(v, a, b+1);
        floodfill(v, a, b-1);
    }
}



int main()
{
    int a, b, c, d, x; cin >> a >> b;
    vector<vector<int>> v;
    for(int i = 0; i < a;i++){
        for(int j = 0; j < b;j++){
            cin >> x;
            v[i].pb(x);
            if(x == 2){
                c = i;
                d = j;
            }
        }
    }
    floodfill(v, c, d);
    cout << cont << endl;

    return 0;
}