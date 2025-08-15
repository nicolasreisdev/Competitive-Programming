#include <bits/stdc++.h>
using namespace std;   

int main(){
    int c ,d; cin >> c >> d;
    vector<int> v;
    vector<int> v2;
    while(c!=0 && d!=0){
        int x;
        for(int i = 0; i < c;i++){
            cin >> x;
            v.push_back(x);
        }
        for(int i = 0; i < d;i++){
            cin >> x;
            v2.push_back(x);
        }
        sort(v.begin(),v.end());
        sort(v2.begin(),v2.end());
        if(v2[1] <= v[0]){
            cout << "N\n";
        }
        else{
            cout << "Y\n";
        }
        cin >> c >> d;
        v.clear();
        v2.clear();
    }


    return 0;
}