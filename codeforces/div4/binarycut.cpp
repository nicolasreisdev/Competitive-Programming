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
    int n;
    cin >> n;
    while (n--){
        string x; cin >> x; 
        int count = 1, target = 0;
        for(int i = 1; i < x.size();i++){
            if(x[i] == x[i-1]){ // se o caractere atual for igual ao anterior, não incrementa o contador
                continue;
            }
            else count++; // se não, incrementa o contador
            if(x[i-1] == '0' && x[i]=='1') target=1; // se o caractere anterior for 0 e o atual 1, o target é 1
        }
        int ans = count - target;
        cout << ans << endl;
    }
    return 0;
}