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
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

int main(){
    int n; cin >> n;
    while(n--){
        string x; cin >> x;
        int parts = 1;
        if(x.size() == 1){
            cout << parts << endl;
            continue;
        }
        vector<string> v;
        int k = 0;
        for(int i = 1; i < x.size(); i++){
            if(x[i-1] == '1' && x[i] == '0'){
                parts++;
            }
        }
        if(x[x.size()-1]=='1' && x[x.size()-2]=='0')parts++;
        cout << parts << endl;
    }
    return 0;
}