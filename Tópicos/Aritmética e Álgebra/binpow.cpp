#include <bits/stdc++.h>
using namespace std;


long long binpowRecursivo(long long x, long long y){
    if(y == 0) return 1; // caso base
    long long ans = binpowRecursivo(x, y/2);  // chamada recursiva
    if(y % 2 == 0)return ans * ans;  // caso par
    return ans * ans * x; // caso impar
}

long long binpowIterativo(long long x, long long y){
    long long ans = 1;
    while(y > 0){ // y != 0
        if(y % 2 == 1){ // y & 1
            ans = ans * x; // ans *= x;
        }
        x = x * x; // x *= x;
        y = y / 2; // y >>= 1;
    }
    return ans;
}

long long binpowBinario(long long x, long long y){
    long long ans = 1;
    while(y > 0){ // y != 0
        if(y & 1){ // y % 2 == 1
            ans = ans * x; // ans *= x;
        }
        x = x * x; // x *= x;
        y >>=  1; // y /= 2;
    }
    return ans;
}

int main(){




    return 0;
}