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
    int mmc, aux, n, m;
    cin >> n >> m;
    for(int i = 2; i < m; i++){
        aux = n * i;
        if(aux % m == 0){
            mmc = aux;
            i = m + 1;
        }
    }   
    cout << mmc << endl;

    return 0;
}