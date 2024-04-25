#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second

typedef pair<int, int> p;
typedef long long ll;

int main()
{
    int n, k;
    int en, p, q;
    cin >> n >> k;
    vector<pair<int,int>>fil;
    set<int>sad;
    for(int i = 0; i < (n*2);i++){
        cin >> en;
        if(en==1){
            cin >> p >> q;
            fil.pb({p,q});
        }
        if(en==2){
            cin >> q;
            for(int j = 0; j < fil.size();j++){
                if(fil[j].s==q){
                    fil.erase(fil.begin()+j);
                    break;
                }
                else{
                   sad.insert(fil[j].f);
                   }
                
            }
        }
    }
    cout << sad.size() << endl;
    for(auto i : sad){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}