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
        int k; cin >> k;
        string s, ans; cin >> s;
        char c = s[0];
        for(int i = 1; i < s.size();i++){
            //cout << c << " " << s[i] << endl;
            if(s[i] == c){
                ans += s[i];
                if(i+1 < s.size()){
                    c = s[i+1];
                    i++;
                }
            }
        }
        cout << ans << endl;

        n--;
    }

    /*
    input:
    3
    8
    abacabac
    5
    qzxcq
    20
    ccooddeeffoorrcceess

    output:
    ac
    q
    codeforces
    */

    return 0;
}