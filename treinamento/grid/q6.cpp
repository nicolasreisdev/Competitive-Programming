#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    for(int h = 0; h < n;h++){
        cin.ignore();
        string pulo;
        getline(cin,pulo);
        vector<vector<int>> grid;
        for(int i = 0; i < 5;i++){
            for(int j = 0; j < 5;j++){
                int a;
                cin >> a;
                grid[i].push_back(a);
            }
        }
        for(int i = 0; i < 5;i++){
            for(int j = 0; j < 5;j++){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

}