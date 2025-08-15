#include <bits/stdc++.h>
using namespace std;



int main(){
    int n, m; cin >> n;
    for(int i = 0; i < n;i++){
        cin >> m;
        vector<int> v;
        for(int i = 1; i <= m;i++){
            int x; cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        int sum = 0;
        int meio = v[m/2];
        for(int i = 0;i<v.size();i++) sum += abs(v[i] - meio);
        cout << sum << endl; 
    }


    return 0;
}