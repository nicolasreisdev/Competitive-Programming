#include <bits/stdc++.h>
using namespace std;


int main(){
    string x, resp;
    while(getline(cin,x)){
        for(int i = 0; i < x.size();i++){
            if(x[i]==' ')x.erase(i,1);
        }
        sort(x.begin(),x.end());
        long int cont = 0, maior = 0;
        for(int i = 1; i < x.size();i++){
            if(x[i-1]==x[i])cont++;
            else{
                if(cont > maior){
                    maior = cont;
                    resp = x[i-1];
                }
                cont = 0;
            }
        }
        cout << resp << " " << maior << endl;
    }


    return 0;
}