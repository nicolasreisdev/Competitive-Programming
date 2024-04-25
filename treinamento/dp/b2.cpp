#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, v, r, r2;
    cin >> n >> v;
    bool k = false;
    bool m[1000] = {false}, m2[30] = {false};
    while (n != 0 && v != 0){
        k = false;
        r = n;r2 = v;
        while (v != 0){
            for (int i = 0; i < v; i++){
                cout << n << " " << v << endl;
                if(m[n] && m2[v]){
                    k = true;
                    break;
                }
                n -= v;
                if (n == 0){
                    k = true;
                    break;
                }
            }
            v--;
        }
        if (k){
            m[r] = true;
            m2[r2] = true;
            cout << "1\n";
        }
        else
            cout << "0\n";
        cin >> n >> v;
    }
    return 0;
}