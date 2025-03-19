#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
#define f first
#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int N = 1e6 + 7;

struct node{
    int ch[26]; // vetor de filhos
    bool end; // se é final de palavra
    int cnt; // quantidade de palavras que passam por esse nó
};

node trie[N]; 

int tt=0;


// O(|s|)
void add(string s){
    int cur = 0;
    
    for(char c: s){
        if(trie[cur].ch[c-'a'] == 0){ // se não existe o caractere c na trie
            trie[++tt].end = false; // cria um novo nó
            memset(trie[tt].ch, 0, sizeof(trie[tt].ch)); // inicializa o vetor de filhos do nó
            trie[cur].ch[c-'a'] = tt; // faz a ligação do nó atual com o novo nó
            trie[cur].cnt = 0; // inicializa a quantidade de palavras que passam por esse nó 
        }
        cur = trie[cur].ch[c-'a']; // vai para o próximo nó
    }

    trie[cur].end = true; // marca o nó como final de palavra
}


// O(|s|)
int count(string s){
    int cur = 0; // começa na raiz
    for (char c : s){
        if (trie[cur].ch[c - 'a'] == 0){ // se não existe o caractere c na trie
            return 0; // a palavra não existe
        }
        cur = trie[cur].ch[c - 'a']; // vai para o próximo nó
    }

    return trie[cur].cnt; // retorna a quantidade de palavras que passam por esse nó
}


void pre(int u){

    for(int i = 0; i < 26;i++){
        int v = trie[u].ch[i]; // pega o filho i do nó u
        if(v){ // se existe o filho i
            pre(v); // chama a função recursivamente
            trie[u].cnt += trie[v].cnt; // atualiza a quantidade de palavras que passam por esse nó
        }
    }

    trie[u].cnt += trie[u].end; // se o nó é final de palavra, incrementa a quantidade de palavras que passam por esse nó
}

int main(){
    fastio;

    string s; cin >> s;

    for(int i = 0; i < s.size();i++){
        string suff = s.substr(i); // pega o sufixo da string s que começa na posição i
        add(suff);
    }

    pre(0); 

    int q; cin >> q;
    while(q--){
        string t; cin >> t;
        cout << count(t) << endl;
    }


    return 0;
}