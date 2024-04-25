#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5 + 10;

vector<int> transf(string x){
    vector<int> k;
    int j = 0; 
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == ' ')
        {
            k.pb(stoi(x.substr(j, i)));
            j = i + 1;
        }
    }
    k.pb(stoi(x.substr(j,x.size()-1)));
    return k;
}


int main()
{

    vector<string> v;
    string x;
    vector<int> k1;
    vector<int> k2;
    for(int i = 0; i < 2;i++){
        getline(cin, x);
        v.pb(x);    
    }
    k1 = transf(v[0]);
    k2 = transf(v[1]);
    set<int> s1;
    for(auto i : k1){
        s1.insert(i);
    }
    sort(k2.begin(), k2.end());
    for(auto l : k2){
        if(s1.find(l) != s1.end()){
            cout << l << " Está mapeado" << endl;
        }
        else cout << l << " Não está mapeado" << endl;
    }


    return 0;
}