#include <bits/stdc++.h>

using namespace std;

int n, c, t;
vector<int> v;

bool check(int x){
    int p = 1, cont = 0;
    for(int i = 0; i < n;i++){
        
    }
    if(p <= c)return true;
    return false;
}

int binarySearch(int l, int r){
    if(l > r) return -1;
    int mid = (r-l)/2 + l;
    if(check(mid)){
        int ans = binarySearch(l, mid-1);
        if(ans == -1) return mid;
        return ans;
    }
    else return binarySearch(mid+1, r);
}


int main(){
    cin >> n >> c >> t;
    v.resize(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int l = 0, r = 1e9;
    cout << binarySearch(l, r) << endl;



    return 0;
}