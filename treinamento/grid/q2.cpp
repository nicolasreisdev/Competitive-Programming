#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    vector<int> v;
    while(cin >> x){
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
    
    return 0;
}