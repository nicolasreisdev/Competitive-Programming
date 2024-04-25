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
    int n, x;
    bool valid = false;
    cin >> n;
    map<int,int> v;
    for (int i = 0; i < n; i++)
    {
        valid = false;
        cin >> x;
        if(v.find(x) != v.end()) v[x]++;
        else v[x] = 1;
        
    }

    int maior = 0, pos = 0;

    for (auto i : v)
    {
        if (i.s > maior || (i.s >= maior && i.f > pos))
        {
            maior = i.s;
            pos = i.f;
        }
    }
    cout << pos << " " << maior << endl;    

    return 0;
}