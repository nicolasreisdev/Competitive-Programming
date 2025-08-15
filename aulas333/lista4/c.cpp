#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    while(n!=0){
        vector<int> v;
        for(int i = 1; i <= n; i++){
            v.push_back(i);
        }
        int cont = 0;
        while(v.size() > 1){
            v.erase(v.begin());
            v.push_back(v[0]);
            v.erase(v.begin());
        }
        cout << v[0] << "\n";
        cin >> n;
    }

    return 0;
}