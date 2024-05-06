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
    string x, y;
    cin >> x >> y;
    int j = 0;
    for(int i = 0; i < y.size(); i++){
        if(y[i] == x[j]){
            cout << i+1 << " ";
            if(j != x.size()-1){
                j++;
            }
        }
    }
    cout << endl;

    return 0;
}