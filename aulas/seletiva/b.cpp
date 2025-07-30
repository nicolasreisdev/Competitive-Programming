#include <bits/stdc++.h>
using namespace std;


int n;
bool check(int x){
    for(int i = 1; i <= 5;i++){
        if(i*x >= n) return true;
    }
    return false;
}

int buscabin(int l, int r){
    if(l>r) return -1;
    int mid = (r-l)/2 + l;
    if(check(mid)){
        int ans = buscabin(l, mid-1);
        if(ans == -1) return mid;
        return ans;
    }
    else return buscabin(mid+1, r);
}


int main(){
    cin >> n;
    cout << buscabin(0, 1000000) << endl;

    return 0;
}