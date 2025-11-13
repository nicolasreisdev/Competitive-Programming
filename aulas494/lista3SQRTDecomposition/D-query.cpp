#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
#define f first
#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

// Fonte: código adaptado de: https://usaco.guide/plat/sqrt?lang=cpp

    // Complexidade será O( N sqrt N ) * complexidade de add,remove,valorConsulta
    // adapte essa classe!
class JanelaMo{
public:
    JanelaMo(vector<int> &v_, int num ) : v(v_){ // tamanho do array
        freq.resize(num, 0);
        n = 0;
    }
    int valorConsulta(){ // adaptar: retorna o valor da consulta da janela atual
        return n; // retorna a quantidade de cores no intervalo
    }
    void add(int idx){ // adaptar:adiciona o elemento da posicao idx a janela
        if (freq[v[idx]] == 0){ // nova cor - O(1) para consulta
            n++;
        }
        freq[v[idx]]++;
    }
    void remove(int idx){ // adaptar:remove o elemento da posicao idx da janela
        freq[v[idx]]--;
        if (freq[v[idx]] == 0){ // não possui mais essa cor - O(1) para consulta
            n--;
        }
    }

private:
    vector<int> &v; // array de entrada (estático!) . Adaptar para outros tipos...
    vector<int> freq;
    int n; // quantidade de cores no intervalo
};

struct Query{
    int l, r, idx;
};

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    map<int, int> comp;
    int next = 0; // quantidade de cores
    for (int i = 0; i < n; i++){
        if (comp.find(v[i]) == comp.end()){
            comp[v[i]] = next++;
        }
    }
    for (int i = 0; i < n; i++){
        v[i] = comp[v[i]]; // id de cada cor
    }
    int q;
    cin >> q;
    vector<Query> queries;
    for (int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        queries.push_back({--x, --y, i});
    }

    int block_size = (int)sqrt(n);
    auto mo_cmp = [&](Query a, Query b){
        int block_a = a.l / block_size;
        int block_b = b.l / block_size;
        if (block_a == block_b){
            return a.r < b.r;
        }
        return block_a < block_b;
    };
    sort(queries.begin(), queries.end(), mo_cmp);

    JanelaMo janela(v, next);

    int mo_left = -1;
    int mo_right = -1;
    vector<int> ans(q); // respostas das consultas (adaptar)
    for (int i = 0; i < q; i++){
        int left = queries[i].l;
        int right = queries[i].r;

        if (mo_left == -1){ // primeira consulta...
            for (int i = left; i <= right; i++)
                janela.add(i);
            mo_left = left;
            mo_right = right;
        }
        else{
            while (mo_left < left){
                janela.remove(mo_left++);
            }
            while (mo_left > left){
                janela.add(--mo_left);
            }
            while (mo_right < right){
                janela.add(++mo_right);
            }
            while (mo_right > right){
                janela.remove(mo_right--);
            }
        }
        // cout << "consulta " << queries[i].idx  << endl;
        ans[queries[i].idx] = janela.valorConsulta();
    }

    for (int i = 0; i < q; i++){
        cout << ans[i] << '\n';
    }
}