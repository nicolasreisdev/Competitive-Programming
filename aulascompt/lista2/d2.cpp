#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t t{};
    cin >> t;
    for(size_t i = 0; i < t;i++){
        size_t m{};
        cin >> m;

        vector<size_t> v(m);
        for(size_t j = 0; j < m; j++){
            cin >> v[j];
        }
        if(next_permutation(v.begin(), v.end())){
            for(size_t j = 0; j < m; j++){
                cout << v[j];
            }
        }
        else{
            cout << "-1" << endl;
        }
        cout << endl;
    }

}