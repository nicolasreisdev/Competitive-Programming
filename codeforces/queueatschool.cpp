#include <bits/stdc++.h>   
using namespace std;

void swap(char &a, char &b){
    char temp = a;
    a = b;
    b = temp;
}


int main(){
    int n, t;
    cin >> n >> t;
    vector<char>child;
    for(int i = 0; i < n;i++){
        char s; cin >> s;
        child.push_back(s);
    }
    for(int i = 0; i < t;i++){
        for(int j = n-1; j > -1;j--){
            if(child[j] == 'G' && child[j-1] == 'B' && (j-1 > -1)){
                swap(child[j], child[j-1]);
                j--;
            }
        }
    }

    for(auto i: child){
        cout << i;
    }
    cout << endl;



    return 0;
}