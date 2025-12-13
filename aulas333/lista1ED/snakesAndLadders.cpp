#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, p, s, l, c, f, x, u = 0; cin >> n;
    vector<int> v;
    vector<pair<int,int>> w;
    bool stop;
    for(int i = 0; i < n;i++){
        stop = false;
        u = 0;
        cin >> p >> s >> l;
        v.assign(p,1);
        for(int j = 0; j < s;j++){
            cin >> c >> f;
            w.push_back({c,f});
        }
        for(int k = 0; k < l; k++){
            cin >> x;   
            if(!stop){
                v[u]+=x;
                for(int z = 0; z < w.size();z++){
                    if(v[u] == w[z].first) v[u]=w[z].second;
                }
                if(v[u] >= 100){
                    v[u] = 100;
                    stop = true;
                }
                u++;
                if(u == p) u = 0;
            }
        }
        for (int i = 0; i < v.size(); i++)
        {
            cout << "Position of player " << i + 1 << " is " << v[i] << "." << endl;
        }
        w.clear();
        v.clear();
    }


    return 0;
}