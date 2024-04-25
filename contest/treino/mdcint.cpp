#include <bits/stdc++.h>

int MDC(int a, int b)
{
    int menor;
    if (a > b)
        menor = b;
    else
        menor = a;
    for (int i = menor; i >= 1; i--)
        if (a % i == 0 && b % i == 0)
            return i;
}

int main(){



    return 0;
}