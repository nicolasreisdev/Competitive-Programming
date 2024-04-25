#include<bits/stdc++.h>
using namespace std;

bool is_prime(long long n, long long primarr[]) 
{
    if(primarr[n] == 1) return true;
    else if(primarr[n] == 2) return false;
    else
    {
        if (n == 1) 
        {
            primarr[1] = 2;
            return false;
        }

        long long i = 2;
        while (i*i <= n) {
            if (n % i == 0) 
            {
                primarr[n] = 2;
                return false;
            }
            i += 1;
        }
        primarr[n] = 1;
        return true;
    }
    
}

int main()
{

    long long n;
    cin >> n;
    long long primarr[n] = {0}; // 0 indef, 1 é primo, 2 nao é

    for(long long i = 1 ; i < (long long)(sqrt(n)+1) ; i++)
    {
        if(is_prime(i, primarr) && n%i == 0 && is_prime(n/i, primarr))
        {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}