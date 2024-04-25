#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, maior, pos; cin >> n;
    while(n!=0){
        maior = 0;
        vector<int> v;
        for(int i = 0; i < n;i++){
            cin >> x;
            if(x > maior){ 
                pos = i;
                maior = x;
            }
            v.push_back(x);
        }
        v[pos] = 0;
        maior = 0;
        for (int i = 0; i < v.size(); i++){
            if (v[i] > maior){
                pos = i;
                maior = v[i];
            }
        }
        cout << pos+1 << endl;
        cin >> n;
    }



    return 0;
}