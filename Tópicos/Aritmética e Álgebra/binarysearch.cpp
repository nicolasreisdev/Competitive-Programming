#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long int
#define pb push_back
#define pi pair<int, int>
#define pii pair<int, pi>
#define fir first
#define sec second
#define MAXN 200005
#define mod 1000000007

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p;
    cin >> p;
    auto check = [&](int x)
    {
        int ans = x;
        ans -= (x / 3);
        ans -= (x / 5);
        ans += (x / 15);
        return ans;
    };
    int l = 1, r = 2 * 1e18;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        (check(mid) >= p) ? r = mid : l = mid + 1;
    }
    cout << l << endl;
}