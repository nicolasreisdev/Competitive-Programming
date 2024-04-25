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
    int n, cont = 0, pa = 4, im = 9;
    cin >> n;
    if(n%2==0){
        n-=pa;
        while(cont!=3){
            cont = 0;
            for(int i = 1;i < n;i++){
                if(n%i==0){
                    cont++;
                }
                if(cont>2){
                    break;
                }
            }
            n-=pa;
            pa+=pa;
        }
        cout << n << " " << pa << endl;
    }
    if(n%2==1){
        n-=im;
        while(cont!=3){
            cont = 0;
            for (int i = 1; i < n; i++)
            {
                if (n % i == 0)
                {
                    cont++;
                }
                if (cont > 2)
                {
                    break;
                }
            }
            n-=3;
            im+=3;
        }
        cout << n << " " << im << endl;
    }
    return 0;
}