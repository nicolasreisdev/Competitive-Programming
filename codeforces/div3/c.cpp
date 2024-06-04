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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cin.ignore();
        string s; getline(cin, s);
        for(int i = 0; i < s.sz();i++){
            if(s[i] == ' ') s.erase(i, 1);
        }
        vector<string> v;
        for(int i = 0; i < s.sz()-2;i++){
            string aux = s.substr(i, 3);
            v.pb(aux);
        }
        int ans = 0;
        for(int i=0;i<v.sz();i++){
            for(int j=0;j<v.sz();j++){
                if(v[i][0] != v[j][0] && v[i][1] == v[j][1] && v[i][2] == v[j][2]){
                    ans++;
                }
                else if (v[i][0] == v[j][0] && v[i][1] != v[j][1] && v[i][2] == v[j][2]){
                    ans++;
                }
                else if (v[i][0] == v[j][0] && v[i][1] == v[j][1] && v[i][2] != v[j][2]){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}