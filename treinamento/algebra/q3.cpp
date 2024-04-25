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
    int n, cont =1, bina = 1;  cin >> n;
    string x;
    for(int i = 0; i < n;i++){
        cin >> x;
        cont = 1;
        bina = 1;
        for (int j = x.size() - 1; j >= 0; j--)
        {
            if(j == x.size() - 1){
                bina = 1;
            }
            else 
                bina *= 2;
            if (x.at(j) == '1')
            {
                cont += bina;
            }
        }
        cout << cont-1 << endl;
    }


    return 0;
}