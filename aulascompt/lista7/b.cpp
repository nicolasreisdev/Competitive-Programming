#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
#define f first
#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

int main(){
    fastio;

    int t, r = 1; cin >> t;
    while(t){
        int n, init = 0, end = 0, aux = 0; cin >> n;
        ll sum = 0, maxSum = 0;
        for(int i = 0; i < n-1;i++){
            int x; cin >> x;
            sum += x;
            if(sum < 0){
                sum = 0;    
                aux = i+1;
            }
            if(sum > maxSum || (sum == maxSum && i-aux > end-init)){
                maxSum = sum;
                init = aux;
                end = i+1;
            }
        }
        if(maxSum == 0){
            cout << "Route " << r << " has no nice parts" << endl;
        }
        else cout << "The nicest part of route " << r << " is between stops " << init+1 << " and " << end+1 << endl;
        r++;
        t--;
    }

    return 0;
}