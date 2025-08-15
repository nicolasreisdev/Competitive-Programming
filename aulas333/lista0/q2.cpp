#include <bits/stdc++.h>
using namespace std;    

void somaquad(long long int x, vector<int>&v){
    v.push_back(x*x);
}

int maior = 0;
int main(){
    long long int x, resp = 0; cin >> x;
    vector<int>v;
    while(x != 0){
        if(x > v.size()){
            for(long long int i = v.size()+1;i <= x;i++){
                somaquad(i,v);
            }
        }
        for(long long int i = 0; i < x;i++){
            resp += v[i];
        }
        cout << resp << endl;
        resp = 0;
        cin >> x;
    }
}