#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
    int n, l, q = 0; cin>> n;
    while(n!=0){
        l = 0;q = 0;
        string x;cin >> x;
        set<char> s;
        bool f = false;
        for(int i = 0; i < x.size();i++){
            if(s.find(x[i]) != s.end()){
                s.erase(x[i]);
                l--;
            }
            else if(l < n){
                s.insert(x[i]);
                l++;
            }
            else{
                f = true;q++;
            }
        }
        if(f) cout << (q/2) << " customer(s) walked away.\n"; 
        else  cout << "All customers tanned successfully. \n";

        cin >> n;
    }



    return  0;
}