#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    int maior1 = 0, maior2 = 0, pos;
    vector<int> v;
    for(int i = 0; i < n;i++){
        int x; cin >> x;
        if(x > maior1){
            maior1 = x;
            pos = i;
        }
        v.push_back(x);
    }
    v.erase(v.begin()+pos);
    for(int i = 0; i < v.size();i++){
        if(v[i] > maior2)maior2 = v[i];
    }
    int cont = 0, sum = 0;
    while(sum < m){
        if(cont%2 == 0)sum += maior1;
        else sum += maior2;
        cont++;
    }
    cout << cont << "\n";



    return 0;
}