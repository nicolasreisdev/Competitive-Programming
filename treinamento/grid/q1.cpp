#include <bits/stdc++.h>
using namespace std;


int main(){
    int m; cin >> m;
    for(int h = 0;h < m;h++){
        int n; cin >> n;
        string s[n][n];
        vector<string,int> visited;
        bool visited[n][n] = {false};
        bool stop = false;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                cin >> s[i][j];
                if(){
                    stop = true;
                }
                else ;
            }
        }
        if(stop)cout << "nao" << endl;
        else cout << "sim" << endl;
    }

    return 0;
}