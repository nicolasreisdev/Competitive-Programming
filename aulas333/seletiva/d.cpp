#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void generate(int k, bool &found, set<string> &s, string &ans, string prefix = ""){
    if (found)
        return;
    if (k == 0){ // caso base   
        int t = s.size();
        if (prefix != "") // se não for vazio
            s.insert(prefix); // insere na lista
        if (t != s.size()){ // se a lista mudou
            found = true; // achou
            ans = prefix;
        }
        return;
    }

    for (char c = 'a'; c <= 'z'; c++){
        string newPrefix = prefix + c;
        generate(k - 1, found, s, ans, newPrefix);
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string x, ans; cin >> x;
        set<string> s;
        for (ll i = 0; i < n; i++){
            for (ll j = 1; j <= n; j++){
                string aux;
                aux = x.substr(i, j);
                s.insert(aux);
            }
        }

        bool found = false;

        for (int i = 1; i <= 3; i++){
            if (!found)
                generate(i, found, s, ans);
        }

        cout << ans << endl;
    }

    return 0;
}