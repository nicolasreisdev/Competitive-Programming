#include <bits/stdc++.h>


void Isertion_Sort(int  v[], int n)
{
    int x;
    int i;
    for (int j = 1; j < n; j++)
    {
        x = v[j];
        i = j - 1;
        while (i >= 0 && v[i] > x) // se for verdade que v[i] é maior que o sucessor ou i chegar na posição -1
        {
            v[i + 1] = v[i]; //a troca é feita
            i--;
        } // fim while
        v[i + 1] = x; 
    } // fim for
}

int main(){
    int n;
    std::cin >> n;
    int v[n];
    for (int i = 0; i < n;i++){
        std::cin >> v[i];
    }
    Isertion_Sort(v, n);
    for(int i = 0; i < n;i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;


}