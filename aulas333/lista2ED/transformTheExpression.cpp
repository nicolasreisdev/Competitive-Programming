#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    
    while(n--){
        string x, ans; cin >> x;
        stack<char> s;
        for(int i = 0; i < x.size();i++){

            if(x[i] == '(')continue;
            if(x[i] >= 'a' and x[i] <= 'z') ans += x[i];
            else if(x[i] == ')'){
                ans += s.top();
                s.pop();
            }
            else s.push(x[i]);
        }
        cout << ans << endl;
    }
    


    return 0;
}