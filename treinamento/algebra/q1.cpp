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


/*int fibonacci(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);

}*/

int main(){
    int n, ult = 0, pen = 1, f; cin >> n;

    for(int i = 0; i < n; i++){
        f = pen;
        pen = ult;
        ult = ult + f;
    }
    cout << (ult) << endl;

    return 0;
}