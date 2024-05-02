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
        int n, m; cin >> n >> m;
        string x, y; // recebe as strings
        cin >> x >> y;// ex: x = "100" y = "110"
        int j = 0;
        for(int i = 0; i < y.size();i++){
            if(y[i] == x[j]){// se o caractere de y for igual ao de x
                j++; // incrementa j
            }
        }
        cout << j << endl; // quantidade de substrings de x em y


        t--;
    }

    /*
    input:
    6
    5 4
    10011
    1110
    3 3
    100
    110
    1 3
    1
    111
    4 4
    1011
    1111
    3 5
    100
    11010
    3 1
    100
    0
    
    output:
    2
    2
    1
    1
    3
    0


    */

    return 0;
}