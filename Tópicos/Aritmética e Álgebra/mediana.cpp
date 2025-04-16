#include <bits/stdc++.h>
using namespace std;

#define optimize                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define endl '\n'
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

#define all(x) x.begin(), x.end()

int main(){
    optimize;

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        v.push_back({aux, i});
    }

    sort(all(v));
    int mposr, mposl = -1;

    deque<pair<int, int>> d;

    for (int i = 0; i < n; i++){
        if (v[i].first == m){
            if (mposl == -1)
                mposl = mposr = i;
            else
                mposr = i;
        }
        d.push_back(v[i]);
    }

    vector<int> res;
    while (true){
        int mediana;
        mediana = (n + 1) / 2 - 1;

        if (mediana >= mposl and mediana <= mposr) // já é mediana
            break;

        // Vale mais tirar da esquerda
        if (mposl > n - mposr - 1){
            mposl--;
            mposr--;
            res.push_back(d.front().second);
            d.pop_front();
        }
        else{
            res.push_back(d.back().second);
            d.pop_back();
        }
        n--;
    }

    cout << res.size() << endl;
    for (auto e : res)
        cout << e + 1 << " ";
    if (res.size())
        cout << endl;

    return 0;
}
