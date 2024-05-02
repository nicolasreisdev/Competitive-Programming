#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5 + 10;
const int MIN = 0;

int main(){
    int n; cin >> n;
    while(n!=0){
        string s; cin >> s;
        ll ans = 0, rem = 0;
        for(int i = 0; i < s.size();i++){
            if(s[i]=='1')rem++; // Counting the number of 1's
            else{ // If we find a 0
                if(rem>0)ans+=rem+1; // If we have 1's before the 0, we add the number of 1's + 1 to the answer
            }
        }
        cout << ans << endl;
        n--;
    }

    /*
    input:
    5
    10
    0000
    11000
    101011
    01101001

    output:
    2
    0
    9
    5
    11




    */

    return 0;
}