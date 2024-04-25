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
    int cont = 0;
    string n;
    getline(cin, n);
    for (int i=0; i < n.size();i++){
        if(n[i] == 'a' || n[i] == 'A' || n[i] == 'e' || n[i] == 'i' || n[i] == 'o' || n[i] == 'u' || n[i] == 'U' || n[i] == 'O' || n[i] == 'I' || n[i] == 'E'){
            cont++;
        }
    }
    std::cout << cont << endl;





    return 0;
}