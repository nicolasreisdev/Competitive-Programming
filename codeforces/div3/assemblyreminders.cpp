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
    int t; cin >> t;
    while(t!=0){
        int n;cin >> n;
        vector<int> v;
        int ans[n];
        for(int i = 0; i < n-1; i++){
            int x; cin >> x;
            v.pb(x); // vetor com os valores de resto da divisão
        }
        ans[0] = 501; // valor inicial (qualquer valor maior que 500) pois o resto da divisão de 500 por qualquer valor é menor que 500
        for(int i = 0; i < n;i++){
            ans[i+1] = ans[i] + v[i]; // soma o valor anterior com o valor atual
        }
        for(int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;

        t--;
    }

    /*
        input:
        5
        4
        2 4 1
        3
        1 1
        6
        4 2 5 1 2
        2
        500
        3
        1 5

        output:
        3 5 4 9
        2 5 11
        5 14 16 5 11 24
        501 500
        2 7 5


    */
    return 0;
}