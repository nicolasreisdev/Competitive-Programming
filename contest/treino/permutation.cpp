#include <bits/stdc++.h>

//permutação do inicio ao fim
void next_permutation(std::vector<int> &v){
    int n = v.size();
    int i = n - 1;
    while(i > 0 && v[i - 1] >= v[i]) i--;
    if(i == 0){
        std::reverse(v.begin(), v.end());
        return;
    }
    int j = n - 1;
    while(v[j] <= v[i - 1]) j--;
    std::swap(v[i - 1], v[j]);
    std::reverse(v.begin() + i, v.end());
}

//permutação do fim ao inicio
void prev_permutation(std::vector<int> &v){
    int n = v.size();
    int i = n - 1;
    while(i > 0 && v[i - 1] <= v[i]) i--;
    if(i == 0){
        std::reverse(v.begin(), v.end());
        return;
    }
    int j = n - 1;
    while(v[j] >= v[i - 1]) j--;
    std::swap(v[i - 1], v[j]);
    std::reverse(v.begin() + i, v.end());
}


int main(){
    int n;
    std::cin >> n;
    std::vector<int> v(n);

    for(int i = 0; i < n; i++) std::cin >> v[i];
        
    std::sort(v.begin(), v.end());

    is_permutation(v.begin(), v.end(), v.begin()); //verifica se é permutação

    return 0;
}