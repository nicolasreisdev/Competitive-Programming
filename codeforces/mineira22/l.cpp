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
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

int main(){
    string x; cin >> x;
    int n; cin >> n;
    string resp = x; 
    int j = 0;

    if(n == 1){
        cout << x << endl;
        return 0;
    }

    for(int i = 0; i < n;i++){
        int k = 2*(n-i-1); // para a distancia entre os elementos de uma mesma piramide
        int k2 = 2*i; // para a distancia entre os elementos de piramides diferentes
        int pos = i;
        resp[pos] = x[j++]; // adiciona o primeiro elemento da piramide
        while(pos < x.size()){
            if(i!=n-1){ // o ulitmo elemento da piramide é único
                pos += k; // adiciona a distancia entre os elementos de uma mesma piramide
                if(pos >= x.size()) break;
                resp[pos] = x[j++]; 
            }
            if(i!=0){ // o primeiro elemento da piramide é único
                pos += k2; // adiciona a distancia entre os elementos de piramides diferentes
                if(pos >= x.size()) break;
                resp[pos] = x[j++];
            }
        }
    }

    cout << resp << endl;

    return 0;
}