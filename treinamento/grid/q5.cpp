#include <bits/stdc++.h>
using namespace std;

int main(){
    string x;
    while(getline(cin,x)){
        pair<int, int> A, B, C, D;
        vector<pair<int,int>>v;
        int menorx = 1000000, menory = 1000000, maiorx = -1000000, maiory = -1000000;
        for(int i = 0; i < x.size();i++){
            if(x[i]==' ') x.erase(i,1);
        }
        for(int i = 0; i < x.size()-2;i+=2){
            int ax, by;
            string a, b;
            a = x[i];b = x[i+1];
            ax = stoi(a);by = stoi(b);
            if(ax < menorx) menorx = ax;
            if(ax > maiorx) maiorx = ax;
            if(by < menory) menory = by;
            if(by > maiory) maiory = by;
            v.push_back(make_pair(ax,by));
            /*if(i == 0){
                A = make_pair(ax,by);
            }
            if(i == 2){
                B = make_pair(ax,by);
            }
            if(i == 4){
                C = make_pair(ax,by);
            }
            if(i == 6){
                D = make_pair(ax,by);
            }*/
        }

        int ax, by;
        string a, b; a = x[x.size()-2]; b = x[x.size()-1];
        ax = stoi(a);
        by = stoi(b);
        bool dentro = false;
        if(ax <= maiorx && ax >= menorx && by <= maiory && by >= menory) dentro = true;
        //if(ax < B.first && ax < C.first && ax > A.first && ax > D.first && by < C.second && by < D.second && by > A.second && by > B.second) dentro = true;
        if(dentro) cout << 1 << endl;
        else cout << 0 << endl;

    }   



    return 0;
}