#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v(256, 0);
    string line;
    int diff = 'a' - 'A';

    while (getline(cin, line)){
        for (int i = 0; i < line.size();i++)
            v[line[i]]++;

        int maior = 0;
        for (int i = 'A'; i <= 'Z'; i++){
            if (v[i] > maior)maior = v[i];

            if (v[i + diff] > maior)maior = v[i + diff];
        }

        for (int i = 'A'; i <= 'Z';i++)if (v[i] == maior) cout << (char)i;

        for (int i = 'a'; i <= 'z';i++)if (v[i] == maior)cout << (char)i;

        cout << ' ' << maior << '\n';
        v.assign(256, 0);
    }
}