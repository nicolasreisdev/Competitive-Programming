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
const int MAX = 1e5 + 10;
const int MIN = 0;

int main(){
    int n;
    cin >> n;
    while (n != 0){
        int k, l;
        cin >> k >> l;
        if (log2(k) < l) cout << k + 1 << endl;
        else cout << (int)pow(2, l) << endl;

        n--;
    }

    /*
    input:
    5
    1 2
    2 1
    2 2
    10 2
    179 100

    output:
    2
    2
    3
    4
    180

    */
    return 0;
}