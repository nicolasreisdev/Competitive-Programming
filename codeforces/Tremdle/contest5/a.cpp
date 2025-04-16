#include <bits/stdc++.h>
using namespace std;


#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;


int main(){

    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int ans = 0;
    for (int i = 0; i < n; i++){
        //cout << abs(s1[i] - '0' - (s2[i] - '0')) << endl; // (direto) estado que quero chegar - estado que estou
        //cout << 10 - abs(s1[i] - '0' - (s2[i] - '0')) << endl; // (reverso) 10 - estado que quero chegar - estado que estou
        ans += min(abs(s1[i] - '0' - (s2[i] - '0')), 10 - abs(s1[i] - '0' - (s2[i] - '0')));
    }
    cout << ans << endl;

    return 0;
}