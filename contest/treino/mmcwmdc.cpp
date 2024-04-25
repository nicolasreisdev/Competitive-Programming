#include <bits/stdc++.h>

int mdc(int a, int b)
{
    if (b == 0)
        return a;
    return mdc(b, a % b);
}

int MMC(int a, int b)
{
    return a * b / mdc(a, b);
}

int main(){

    
    return 0;
}