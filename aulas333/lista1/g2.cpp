#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; 
    while(cin >> n)
    {
        vector<int> x;
        int y, z, resp, k;
        bool stop = false;
        
        for(int i = 0; i < n;i++){
            cin >> k;
            x.push_back(k);
        }
        bool j[x.size()] = {false};
        z = x[0];
        for (int i = 1; i < x.size(); i++){
            y = x[i];
            resp = y - z;
            if (resp < 0){
                resp = -resp;
            }
            if (resp > (x.size() - 1) || j[resp] || resp == 0){
                stop = true;    
                break;
            }
            z = y;
            j[resp] = true;
        }
        if (stop)
            cout << "Not jolly\n";
        else
            cout << "Jolly\n";
    }

    return 0;
}
