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

template <class T>
class BIT
{
private:
    int size;
    vector<T> bit;
    vector<T> arr;

public:
    BIT(int size) : size(size), bit(size + 1), arr(size) {}

    /** Sets the value at index ind to val. */
    void set(int ind, T val) { add(ind, val - arr[ind]); }

    /** Adds val to the element at index ind. */
    void add(int ind, T val)
    {
        arr[ind] += val;
        ind++;
        for (; ind <= size; ind += ind & -ind)
        {
            bit[ind] += val;
        }
    }

    /** @return The sum of all values in [0, ind]. */
    T pref_sum(int ind)
    {
        ind++;
        T total = 0;
        for (; ind > 0; ind -= ind & -ind)
        {
            total += bit[ind];
        }
        return total;
    }
};

ll timer = 0;
void eulerTour(vector<vector<int>> &g, int v, int parent, vector<int> &start, vector<int> &end){
    start[v] = timer;
    timer++;
    for (int &u : g[v]){
        if (u != parent)
            eulerTour(g, u, v, start, end);
    }
    end[v] = timer;
}

int main(){
    fastio;

    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n + 1);
    vector<int> start(n + 1);
    vector<int> end(n + 1);
    for (int i = 1; i < n; i++){
        int parent;
        cin >> parent;
        g[parent - 1].push_back(i);
    }
    eulerTour(g, 0, -1, start, end);
    BIT<ll> bit(n+1);
    vector<vector<int>> conjunto(q);
    for (int i = 0; i < q; i++){
        int mj;
        cin >> mj;
        for (int j = 0; j < mj; j++){
            int funcionario;
            cin >> funcionario;
            conjunto[i].push_back(funcionario - 1);
        }
        sort(conjunto[i].begin(), conjunto[i].end());
        ll sum = 0;
        for (int j = 0; j < mj; j++){
            bool isParent = false;
            for (int k = j; k < mj; k++){
                if (conjunto[i][k] != conjunto[i][j]){
                    if ((start[conjunto[i][j]] < start[conjunto[i][k]] && end[conjunto[i][j]] >= end[conjunto[i][k]])){
                        isParent = true;
                    }
                }
            }
            if (!isParent)
                sum++;
        }
        cout << sum << endl;
    }

    return 0;
}