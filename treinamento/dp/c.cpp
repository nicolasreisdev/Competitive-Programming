#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    map<int, int> l;
    while(n!=0){
        vector<int> t;
        int v , p, k, r, resp = 0;
        for(int i = 0; i < n;i++){
            cin >> v >> p;
            l.insert({v,p});
        }
        cin >> k;
        for(auto i: l){
            resp = 0;
            resp = i.first;
            for(auto j: l){
                r = i.second + j.second;
                if (r <= k) resp += j.first;
                else r - j.second;
            }
            t.push_back(resp);
        }
        sort(t.begin(), t.end());
        cout << t[t.size()-1] << endl;
        l.clear(); 
        t.clear();
    }



    return 0;
}