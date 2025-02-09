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

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

ll binarysearch(vector<ll> v, int l, int r, int x){
    int mid;
    while (r - l > 1){
        mid = (l + r) / 2;
        if(v[mid] == x){
            cout << "entrei " << v[mid] << endl;
            r = mid-1;
        }
        else l = mid;
    }
    if(v[mid]==x) return mid;
    return -1;
}

int main(){
    ll n, z, x;
    int result;
    cin >> n;
    vector<ll> v;
    for (int i = 0; i < n; i++){
        cin >> z;
        v.pb(z);
    }
    ll dias;
    cin >> dias;
    sort(v.begin(), v.end());
    vector<ll> qntd;
    for (int j = 0; j < dias; j++){
        cin >> x;

        result = binarysearch(v, -1, n, x);

        if (result == -1) qntd.pb(0); 
        else qntd.pb(result + 1);
    }
    for (int i = 0; i < qntd.size(); i++){
        cout << qntd[i] << endl;
    }

    return 0;
}