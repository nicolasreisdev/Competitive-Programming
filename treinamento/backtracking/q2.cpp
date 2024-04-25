#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second
#define sz size
#define in insert


typedef pair<int,int>p;
typedef long long ll;
const int MAX = 1e5 + 10;
const int MIN = 0; 

int main(){
    int a,b,c,d; cin >> a >> b >> c;
    d = a%c;
    if(b%c==d){
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}