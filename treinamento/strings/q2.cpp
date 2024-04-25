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
    cin>>n;
    for(int i = 1; i < n.size();i++){
        if(n[i] != n[i-1]){
            cout << n[i-1];
        }
    }
    cout << n[n.size()-1];
    cout << endl;

    return 0;
}