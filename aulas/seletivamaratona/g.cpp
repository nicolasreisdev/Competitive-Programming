#include <bits/stdc++.h>

using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

typedef long long ll;

int main(){
    fastio;

    int n; cin >> n;
    vector<int> negative;
    vector<int> positive;
    vector<int> zeros;
    for (int i = 0; i < n;i++){
        int x; cin >> x;
        if(x < 0) negative.push_back(x);
        else if(x > 0) positive.push_back(x);
        else zeros.push_back(x);
    }
    if(negative.size()%2 == 0){
        zeros.push_back(negative[negative.size()-1]);
        negative.pop_back();
    }
    if(positive.size() == 0){
        positive.push_back(negative[negative.size() - 1]);
        negative.pop_back();
        positive.push_back(negative[negative.size() - 1]);
        negative.pop_back();
    }
    cout << negative.size() << " ";
    for(auto e: negative) cout << e << " ";
    cout << endl;
    cout << positive.size() << " ";
    for (auto e : positive)cout << e << " ";
    cout << endl;
    cout << zeros.size() << " ";
    for (auto e : zeros)cout << e << " ";
    cout << endl;
    return 0;
}