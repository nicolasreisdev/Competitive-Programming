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
    int n, x, maior = 0, menor = 61; cin >> n;
    for(int i = 0; i < n;i++){
        cin >> x;
        if(x > maior) maior = x;
        else if(x < menor) menor = x;
    }
    cout << maior - menor << endl;

    return 0;
}
