#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second
#define sz size
#define in insert


typedef pair<int,int>p;
typedef long long ll;
const int MAX = 1e5 + 10;
const int MIN = 0; 

int main(){
    int a; cin >> a;
    string x;
    for(int i = 0; i < a;i++){
        if(i == 0){
            cin.ignore();
        }
        getline(cin,x);
        for(int j = 0; j < x.size();j++){
            if(x[j] == 'a'){
                x[j] = '@';
            }
            if (x[j] == 'e')
            {
                x[j] = '&';
            }
            if (x[j] == 'i')
            {
                x[j] = '!';
            }
            if (x[j] == 'o')
            {
                x[j] = '*';
            }
            if (x[j] == 'u')
            {
                x[j] = '%';
            }
        }
        cout << x << endl;
    }
    

    return 0;
}