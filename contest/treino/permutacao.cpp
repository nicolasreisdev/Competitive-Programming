#include <bits/stdc++.h>    
using namespace std;


int main(){
    vector<int> v = {1, 2, 3, 4};
    int cont = 0;

    /* permutação do inicio ao fim

    sort(v.begin(), v.end());

    do{
        for(int i = 0; i < 4; i++) cout << v[i] << " ";
        cout << endl;
        cont++;
    }while(next_permutation(v.begin(), v.end()));
    */


    /* permutação de trás para frente

    reverse(v.begin(), v.end());
    do{
        for(int i = 0; i < 4; i++) cout << v[i] << " ";
        cout << endl;
        cont++;
    }while(prev_permutation(v.begin(), v.end()));
    */

   

    for(int i = 0; i < v.size();i++){
        cout << v[i] << " ";
    }
    cout << "\n";
    cout << cont << "\n";




    return 0;
}