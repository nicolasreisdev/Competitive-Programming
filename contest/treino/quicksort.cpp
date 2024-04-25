#include <bits/stdc++.h>

/*Funções do quickbásico*/
void troca(int v[], int i, int j)
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
int particao(int v[], int esq, int dir)
{
    int i, fim;
    fim = esq;
    for (i = esq + 1; i <= dir; i++){
        std::cout << "valor de v[i]: " << v[i] << std::endl;
        if (v[i] < v[esq])
        {
            fim = fim + 1;
            std::cout << "trocou " << v[i] << " com " << v[fim] << std::endl;
            troca(v, fim, i);
        }
    }
    troca(v, esq, fim);
    std::cout << "trocou 2 " << v[esq] << " com " << v[fim] << std::endl;
    std::cout << fim << std::endl;
    return fim;
}
void quicksort(int v[], int esq, int dir)
{
    int i;
    if (esq >= dir)
        return;
    i = particao(v, esq, dir);
    quicksort(v, esq, i - 1);
    quicksort(v, i + 1, dir);
}

int main(){
    int n;
    std::cin >> n;
    int v[n];
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }
    quicksort(v, 0, n-1);
    for(int i = 0; i < n; i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    return 0;


}