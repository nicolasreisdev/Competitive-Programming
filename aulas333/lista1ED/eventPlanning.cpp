#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, b, h, w, p , a;
    vector<int> v;
    while (cin >> n >> b >> h >> w){
        for(int i = 0; i < h;i++){
            cin >> p;
            for(int j = 0; j < w;j++){
                cin >> a;
                if(a >= n && p*n <= b){
                    v.push_back(p*n);
                }
            }
        
        }
        sort(v.begin(), v.end());

        if(v.empty())cout << "stay home" << endl;
        else cout << v[0] << endl;
        v.clear();

    }

        return 0;
}