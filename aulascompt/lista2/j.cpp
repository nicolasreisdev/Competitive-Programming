#include <bits/stdc++.h>
using namespace std;

int bubblesort(vector<int>v){
    int sum = 0;
    for(int i = 0; i < v.size();i++){
        for(int j =0; j < v.size()-1;j++){
            if(v[j] > v[j+1]){
                swap(v[j],v[j+1]);
                sum++;
            }
        }
    }
    return sum;
}


int main(){
    int n, m; cin >> n;
    for(int i = 0; i < n;i++){
        cin >> m;
        vector<int> v;
        for(int j = 0; j < m;j++){
            int x; cin >> x;
            v.push_back(x);
        }
        int sum = bubblesort(v);
        cout << "Optimal train swapping takes " << sum << " swaps." << endl;
    }


}