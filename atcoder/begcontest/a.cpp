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
    int n, x, sc, z; cin >> n >> x >> sc >> z;
    if(x > sc){
        for(int i = x; i >= sc; i--){
            if(i == z){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    else{
        for(int i = x; i <= sc; i++){
            if(i == z){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}