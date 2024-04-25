#include <iostream>
#include <bits/stdc++.h>

int trocas = 0;

void ordSelecao(int v[], int tam)
{
    int minimo = 0, i = 0, j = 0, menor = 0;
    for (i = 0; i < tam-1; i++)
    {
        minimo = i;
        // Encontra o menor elemento do vetor
        for (j = i + 1; j < tam; j++)
        {
            if (v[j] < v[minimo])
                minimo = j;
        }
        // Realiza a troca dos valores
        menor = v[minimo];
        v[minimo] = v[i];
        v[i] = menor;
        trocas++;
    }

    // Note que o número de trocas é O(n)
    return;
}

int main(){
    int n;
    std::cin >> n;
    int v[n];
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }
    ordSelecao(v, n);
    for(int i = 0; i < n; i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    std::cout << trocas << std::endl;
    std::cout << std::endl;
    return 0;
}