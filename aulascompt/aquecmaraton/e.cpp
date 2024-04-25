    #include <bits/stdc++.h>
    using namespace std;

    // GULOSO 
    int main(){
        int n, t; cin >> n >> t;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        int ans = 0, sum = 0, maior = 0;
        for(int i = 0; i < n; i++){
            sum += v[i];
            if(sum <= t){
                ans++;
                if (v[i] > maior)maior = i;
            }
            else sum -= v[maior];
        }
        cout << ans << endl;


        return 0;
    }