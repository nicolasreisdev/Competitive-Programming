#include <bits/stdc++.h>

void shellsort(int v[], int n)
{
    int i, j, k, h = 1;
    int aux;
    do
    {
        h = h * 3 + 1;
    } while (h < n);
    do
    {
        h /= 3;
        for (i = h; i < n; i++)
        {
            aux = v[i];
            j = i;
            while (v[j - h] > aux)
            {
                v[j] = v[j - h];
                j -= h;
                if (j < h)
                    break;
            }
            v[j] = aux;
        }
    } while (h != 1);
}

int main(){
    return 0;
}