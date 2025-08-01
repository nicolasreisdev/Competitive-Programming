#include <bits/stdc++.h>
using namespace std;

int main(){

    map<int,int> m;
    m[0] = 1; // inserção de elemento O(log n)
    m.insert({0,1}); // inserção de elemento como pair O(log n)
    m.erase(0); // remoção de elemento por chave O(log n)
    auto it = m.find(0); // busca por elemento O(log n)
    it->first; // retorna a chave O(1) 
    it->second;// retorna o valor O

}