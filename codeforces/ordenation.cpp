#include <bits/stdc++.h>   
#include <iostream>
using namespace std;

int main(){
    int n, big = 0, small = 101, x, cont = 0;
    set<int>s;
    cin >> n;
    for (int i = 0 ; i < n; i++){
        cin >> x;
        s.insert(x); 
        if(x > big) big = x;
        if(x < small) small = x;
    }
    
    vector<int>v = vector<int>(s.begin(), s.end());

    bool ord = false, ord2 = true;
    for(int i = 0; i < n;i++){
        if(v[i] == big){
            ord = false;
        }
        if(v[i] == small){
            ord2 = true;
        }
        if(ord){
            cont++;
        }
        if(ord2){
            cont++;
        }
    }

    cout << (cont-1) << endl;

    return 0;
}