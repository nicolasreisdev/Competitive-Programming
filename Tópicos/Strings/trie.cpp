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

struct node{
    int ch[26]; // vetor de filhos
    bool end;   // se é final de palavra
};

node trie[MAX];

int tt = 0;

// O(|s|)
void add(string s){
    int cur = 0;
    for (char c : s){
        if (trie[cur].ch[c - 'a'] == 0){// se não existe o caractere c na trie
            trie[++tt].end = false; // cria um novo nó
            memset(trie[tt].ch, 0, sizeof(trie[tt].ch)); // inicializa o vetor de filhos do nó
            trie[cur].ch[c - 'a'] = tt;                  // faz a ligação do nó atual com o novo nó
        }
        cur = trie[cur].ch[c - 'a']; // vai para o próximo nó
    }
    trie[cur].end = true; // marca o nó como final de palavra
}

// O(|s|)
bool exists(string s){
    int cur = 0;
    for (char c : s){
        if (trie[cur].ch[c - 'a'] == 0){ // se não existe o caractere c na trie
            return false; // a palavra não existe
        }
        cur = trie[cur].ch[c - 'a']; // vai para o próximo nó
    }

    return trie[cur].end; // retorna se o nó é final de palavra
}


int main(){

    return 0;
}