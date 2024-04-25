#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second

typedef pair<int, int> p;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    if(n%3==0){
        cout << n/3 << endl;
    }
    else 
        cout << (n+3-1)/3 << endl;


    return 0;
}