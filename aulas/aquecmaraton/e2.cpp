    #include <bits/stdc++.h>
    using namespace std;

    // GULOSO 
    int main(){
        int n, t, sum = 0, ans = 0; cin >> n >> t;
        queue<int> pq;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            pq.push(x);
            sum += x;
            if(sum > t){
                sum -= pq.front();
                pq.pop();
            }
            ans = max(ans, (int)pq.size());
        }
        cout << ans << endl;


        return 0;
    }