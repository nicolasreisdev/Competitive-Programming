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
    int l,f, cont = 0;;
    int a,b;
    cin >> l >> f;
    for(int i = 0; i < l;i++){
        cin >> a >> b;  
        if(f>=a && f>=b){
            if(a>=b){
                f+=a;
            }
            else if(b>=a){
                f+=b;
            }
        }
        else if(f>=b || f>=a){
            if(f>=a){
                f+=a;
            }
            else if(f>=b){
                f+=b;
            }
        }
        else{
            cout << "N" << endl;
            return 0;
        }
    }
    cout << "S" << endl;
    return 0;
}