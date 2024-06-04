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
        int size; cin >> size;
        set<char> st;
        string s;
        for(int i = 0; i < size; i++){
            char x; cin >> x;
            s += x; 
            st.in(x);
        }
        if(size == 1){
            cout << s << endl;
            continue;
        }
        string x;
        for(auto i : st){
            x += i;
        }
        map<char,char> m;
        for(int i = 0; i < (x.size()/2)+1; i++){
            m[x[i]] = x[x.size()-1-i];
            m[x[x.size()-1-i]] = x[i];
        }
        for(int i = 0; i < size; i++){
            s[i] = m[s[i]];
        }
        cout << s << endl;
    }
    return 0;
}