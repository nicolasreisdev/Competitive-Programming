#include <bits/stdc++.h>
using namespace std; 


int main(){
    int n; cin >> n;
    double maior = 0;
    vector<pair<double,double>> v;
    for(int i = 0;i < n;i++){
        double x,y; cin >> x >> y;
        double p = x/y;
        v.push_back({x,y});
        if(p >= maior) maior = p;
    }
    for(int i = 0;i < n;i++){
        if(v[i].first/v[i].second == maior){
            cout << v[i].first << " " << v[i].second << "\n";
            break;
        }
    }


    return 0;
}