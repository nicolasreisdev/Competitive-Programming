#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
#define f first
//#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;


int s[14];
int k;

void solve(int k){
    for(int i = 0; i+5 < k;i++){  // percorre o vetor de 0 a k-5 
        for(int j =i+1; j+4 < k;j++){ // percorre o vetor de i+1 a k-4
            for (int k2 = j + 1; k2+3 < k; k2++){ // percorre o vetor de j+1 a k-3
                for (int l = k2 + 1; l+2 < k; l++){ // percorre o vetor de k2+1 a k-2
                    for (int m = l + 1; m+1 < k; m++){ // percorre o vetor de l+1 a k-1
                        for (int n = m + 1; n < k; n++){ // percorre o vetor de m+1 a k
                            cout << s[i] << " " << s[j] << " " << s[k2] << " " << s[l] << " " << s[m] << " " << s[n] << endl;
                        }
                    }
                }
            }
        }
    }
}


int main(){
    fastio;

    cin >> k;
    while(k != 0){ 
        for(int i = 0; i < k;i++){
            cin >> s[i];
        }
        solve(k);

        cin >> k;
    }   

    return 0;
}