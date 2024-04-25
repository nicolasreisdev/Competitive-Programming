#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5 + 10;

int main()
{
    int n, x; cin >> n >> x;
    string v[14] = {"", "Às", "2", "3", "4", "5", "6", "7", "8",
                    "9", "10", "Valete", "Dama", "Rei"};
    string k[4] = {"Paus", "Ouro", "Coração", "Espada"};
    
    cout << v[x] << " de " << k[n] <<endl;
     

    return 0;
}