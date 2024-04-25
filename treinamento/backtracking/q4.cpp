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
    vector<pair<int,int>>v;
    int x;
    bool a = false;
    while(cin>>x){
        a = false;
        for(int i = 0; i < v.size();i++){
            if(v[i].f == x){
                v[i].s++;
                a = true;
                break;
            }
        }
        if(!a){
            v.pb({x,1});
        }
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < v.size();i++){
        cout << v[i].f << " " <<  v[i].s <<  endl;
    }
    return 0;
}