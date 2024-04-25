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
    int n, cont = 0, x = 0;
    cin >> n;
    x = n;
    int b[n];
    for(int i = 0;i < n;i++){
        cin >> b[i];
    }
    while(x!=0){
        cont++;
        for(int j = 0;j < n;j++){
            if(x==b[j]){
                x--;
                b[j]=0;
            }
        }
    }
    cout << cont << endl;

    return 0;
}