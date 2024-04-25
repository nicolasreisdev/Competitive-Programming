#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, x, resp; cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    for(int i = 0; i < v.size();i++){
        resp = 0;
        resp += v[i];
        for(int j = 0; j < v.size();j++){
            if(v[j] == v[i]) j++;
            resp += v[j];
            if(resp == k){
                cout << "1\n";
                return 0;
            }   
            if(resp > k){
                resp -= v[j];
            }
        }
    }
    cout << "0\n";
}