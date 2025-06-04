#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n;i++){
        int x; cin >> x;v[i] = x;
    }
    int ans = 0;
    set<int> s; 
    for(int i = 0;i < v.size();i++){
        s.insert(v[i]);
        if(s.size() == m){
            ans = v.size() - i;
            break;
        } 
            
    }
    cout << ans << endl;


    return 0;
}