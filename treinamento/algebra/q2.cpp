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
    int n; cin >> n;
    int t, i, a, cont, k = 0, j, ant = 0;
    for(int k =0; k < n;k++){
        cont = 0;
        cin >> t >> i >> a;
        j = 0;
        ant  = 0;
        while(ant < t){
            if(j == 0){
                ant += i;
                j += i;
            }
            else {
                j += a;
                ant += j;
                }
            cont++;
        }
        cout << cont << endl;
    }

    return 0;
}