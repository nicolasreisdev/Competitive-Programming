#include <bits/stdc++.h>
using namespace std;

int main(){
    string x, k;
    while(getline(cin, x)){
        bool j[x.size()] = {false};
        for(int i = 0; i < x.size(); i++){
            if(x[i] == ' ') x.erase(i, 1);
            
        }
        int y, z, resp;
        bool stop = false;
        k = x[0];
        z = stoi(k);
        for (int i = 1; i < x.size(); i++){
            k = x[i];
            if(k == "-"){
                string o;
                o = x[i+1];
                k = k + o;
                i++;
            }
            y = stoi(k);
            resp = y - z;
            if (resp < 0){
                resp = -resp;
            }
            if (resp > x.size()-1 || j[resp] || resp == 0){
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
