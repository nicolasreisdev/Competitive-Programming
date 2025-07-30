#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m, p, x; cin >> n;
    for(int i = 0; i < n;i++){
        cin >> m >> p;
        vector<int> v;
        for(int j = 0; j < p;j++){
            cin >> x;
            v.push_back(x);
        }
        cout << m << " " << (p/2)+1 << "\n";
        for(int j = 0; j < v.size();j+=2){
            sort(v.begin(), v.begin() + j + 1);
            cout << v[j/2] << " ";
        }
        cout << endl;
    }


    return 0;
}