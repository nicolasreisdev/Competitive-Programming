#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5 + 10;

void Isertion_Sort(string &v, int &op)
{
    char x;
    int i, n = v.size();
    for (int j = 1; j < n; j++)
    {
        x = v[j];
        i = j - 1;
        while (i >= 0 && v[i] > x) // se for verdade que v[i] é maior que o sucessor ou i chegar na posição -1
        {
            v[i+1] = v[i]; // a troca é feita
            i--;
            op++;
        } // fim while
        v[i+1] = x;
        op++;
    } // fim for
}

int main()
{
    int n;
    std::cin >> n;
    int op[n] = {0};
    vector<string> v;
    string aux;
    for (int i = 0; i < n; i++){
       cin >> aux;
        v.pb(aux);
    }
    for(int i = 0; i < n; i++){
        Isertion_Sort(v[i], op[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << op[i] << std::endl;
    }
}