#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
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

template <typename T>
class SparseTable{
private:
    int n, log2dist;
    vector<vector<T>> st;

public:
    SparseTable(const vector<T> &v){
        n = (int)v.size();
        log2dist = 1 + (int)log2(n);
        st.resize(log2dist);
        st[0] = v;
        for (int i = 1; i < log2dist; i++){
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j + (1 << i) <= n; j++){
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    /** @return minimum on the range [l, r] */
    T query(int l, int r){
        int i = (int)log2(r - l + 1);
        return min(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

int main(){
    fastio;

    int n, q; cin >> n >> q;
    // 2 10 1 100 
    vector<int> value(n);
    for(int i = 0; i < n;i++){
        int x; cin >> x;
        value[i] = x;
    }
    SparseTable sTable(value);
    for(int i = 0; i < q;i++){
        int l, r; cin >> l >> r;
        cout << sTable.query(l, r-1) << endl;
    }

    return 0;
}