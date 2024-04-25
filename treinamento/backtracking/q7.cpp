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

int maior = 0;
void dpCont(int a, int b, map<int,int> &v){
    for(int i = a; i <= b;i++){
        v.insert({i,0});
        v[i]++;
        if (v[i] > maior)maior = v[i];
        
    }
}


int main()
{
    int x,a ,b ; cin >> x;
    map<int, int> v;
    for(int i = 0; i < x;i++){
        cin >> a >> b;
        dpCont(a,b,v);
    }
    cout << maior << endl;
    return 0;
}