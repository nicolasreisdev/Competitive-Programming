#include <iostream>
using namespace std;

int main(){
    int n,d, x; cin >> n >> d;
    while(n != 0 && d != 0){
        int v[n];
        for(int i = 0; i < n;i++){
            v[i] = 0;
        }
        bool a = false;
        for(int i = 0; i < d;i++){
            for(int j = 0; j < n;j++){
                cin >> x;
                if(x == 1){
                    v[j]++;
                }
            }
        }
        for(int i = 0; i < n;i++){
            if(v[i] == d){
                cout << "yes\n";
                a = true;
                break;
            }
        }
        if (!a) cout << "no\n";
        cin >> n >> d;
    }

    return 0;


}