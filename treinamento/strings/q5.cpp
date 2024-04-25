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
    string n;
    vector<string> v;
    int cont = 0, res = 0, j = 0;
    getline(cin, n);
    n += ' ';
    for(int i = 0; i < n.size();i++){
        if(n[i] == ' '){
            cont++;
            v.push_back(n.substr(j, i-j));
            j = i+1;
        }
    }
    for(int i = 0; i < v.size();i++){
        for(int j = 0; j < v[i].size();j++){
        }
    }
    cout << cont << endl;
    cout << res << endl;

    return 0;
}