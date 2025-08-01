#include <bits/stdc++.h>
using namespace std;


int main(){
    set<int> s;
    s.insert(1); // insere elemento O(log n)
    s.erase(1); // remove elemento O(log n)
    auto it = s.find(1); // busca pelo elemento O(log n)
    s.lower_bound(1); // O(log n)
    s.upper_bound(1); // O(log n)


}