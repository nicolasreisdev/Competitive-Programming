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
 

typedef pair<int,int>p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;


int main(){
    vector<int> nums = {-2, 0, -1};
    int prefixSum = nums[0];
        for(int i = 1; i < nums.size();i++){
            prefixSum *= nums[i];
            // cout << prefixSum << endl;
        }
        
        int ans = prefixSum;
        for(int i = nums.size(); i >= 0;i--){
            ans = max(ans, prefixSum);
            nums[i] == 0 ? : prefixSum/=nums[i];
        }
        cout << ans << endl;

        return 0;
}