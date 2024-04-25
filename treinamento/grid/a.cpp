#include <bits/stdc++.h>
using namespace std;    

int main(){
    int n, m; cin >> n;
    for(int i = 0;i < n;i++){
        cin >> m;
        char grid[m][m];
        for(int j= 0 ; j < m;j++){
            for(int k = 0; k < m;k++){
                grid[j][k] = '.';
            }
        }
        int numed; cin >> numed;
        for(int j = 0; j < m;j++){
            for(int k = 0; k < m;k++){
                int x, y; cin >> x >> y;
                grid[x][y] = 'o';
            }
        }
        int numbomb; cin >> numbomb;
        vector<pair<pair<int,int>,int>> bomb;
        for(int j = 0; j < numbomb;j++){
            int x, y, r;
            cin >> x >> y >> r;
            bomb.push_back({{x,y},r});
        }
        for(int j = 0; j < numbomb;j++){
            int x = bomb[j].first.first;
            int y = bomb[j].first.second;
            int r = bomb[j].second;
            if (grid[x + 1][y] == 'o' && (x + 1) < m) grid[x + 1][y] = '#';
            if (grid[x - 1][y] == 'o' && (x - 1) > -1) grid[x - 1][y] = '#';
            if (grid[x][y + 1] == 'o' && (y + 1) < m) grid[y + 1][y] = '#';
            if (grid[x][y - 1] == 'o' && (y - 1) > -1) grid[y - 1][y] = '#';
            if (grid[x + 1][y] == '.' && (x + 1) < m)grid[x + 1][y] = '*';
            if (grid[x - 1][y] == '.' && (x - 1) > -1)grid[x - 1][y] = '*';
            if (grid[x][y + 1] == '.' && (y + 1) < m )grid[y + 1][y] = '*';
            if (grid[x][y - 1] == '.' && (y - 1) > -1)grid[y - 1][y] = '*';
        }
        for(int j = 0; j < m;j++){
            for(int k = 0; k < m;k++){
                cout << grid[j][k];
            }
            cout << endl;
        }
    }



    return 0;
}