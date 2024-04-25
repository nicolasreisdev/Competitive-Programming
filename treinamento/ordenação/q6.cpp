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
    string x;
    vector<string> v;
    while(cin >> x){
        v.pb(x);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size();i++){
        if(v[i] == "1") cout << "A ";
        else if(v[i] == "11") cout << "J ";
        else if(v[i] == "12") cout << "Q ";
        else if(v[i] == "13") cout << "K ";
        else cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}