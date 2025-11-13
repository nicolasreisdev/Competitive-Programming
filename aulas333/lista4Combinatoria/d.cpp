#include <iostream>
#include <bits/stdc++.h>
using namespace std;   

vector<int> catalan(vector<int> v, int n){
    vector<int> res;
    int carry = 0;
    for(int i = 0;i < v.size();i++){
        carry += v[i] * n;
        res.push_back(carry%10);  
        carry /= 10;
    }
    while(carry > 0){ 
        res.push_back(carry%10);
        carry /= 10;
    }
    return res;
}


int main(){
    int n; cin >> n;
    while(n!=0){
        vector<int> v;
        v.push_back(1);
        for(int i = n+2;i <= n*2;i++) v = catalan(v, i); // (n+2)*(n+3)*...*(2n)
        for(int i = v.size()-1;i >= 0;i--) cout << v[i]; 
        cout << endl;
        cin >> n;
    }


    return 0;
}