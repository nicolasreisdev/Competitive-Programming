#include <bits/stdc++.h>

bool primo(int n)
{
    int cont = 0;
    for(int i = 0; i < sqrt(n);i++)
        if(n % i == 0) cont++;
            
    if(cont == 2 || n == 1) return true;
        
    return false;

}


int main(){

    return 0;
}