#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5 + 10;
const int MIN = 0;

int main()
{
    int a, b, c = 0;cin >> a;
    string x, y;
    for(int i = 0; i < a;i++){
        cin >> x;
        b = 128;
        c = 0;
        for(int j = 0;j < 32;j++){
            if (j == 8 || j == 16 || j == 24)
            {
                y += to_string(c);
                y += ".";
                b = 128;
                c = 0;
            }
            if(x[j] == '1'){
               c += b;
            }
            b = b / 2;
        }
        y += to_string(c);
        cout << y << endl;
        y = "";
    }
    return 0;
}