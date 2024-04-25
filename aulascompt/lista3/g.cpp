#include <bits/stdc++.h>
using namespace std;


int main(){
    string x;
    while(getline(cin, x)){    
        vector<int> v,c;
        stringstream ss(x);
        long long n, resp;
        while(ss >> n)v.push_back(n);
        
        getline(cin, x);
        stringstream ss2(x);
        while(ss2 >> n)c.push_back(n);

        for(int i = 0; i < c.size(); i++){
            resp = 0;
            for(int j = 0; j < v.size(); j++){
                resp += v[j];
                if(j<v.size()-1) resp *= c[i];  
            }
            cout << resp;
            if(i < c.size()-1) cout << " ";
        }
        cout << endl;
    }


    return 0;
}