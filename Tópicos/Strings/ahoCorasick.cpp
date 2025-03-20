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
    map<char,int> ch;
    int cnt, suf, par;
};

node aho[MAX];

int tt = 0;

// O(|s|)
void add(string s){
    int cur = 0;
    for (char c : s){
        if (aho[cur].ch.count(c) == 0){// se não existe o caractere c na aho
            aho[++tt].end = false;// cria um novo nó
            aho[tt].ch.clear();// inicializa o vetor de filhos do nó
            aho[tt].ch[c - 'a'] = tt;// faz a ligação do nó atual com o novo nó
            aho[tt].par = cur;
            aho[tt].suf = 0;
            aho[cur].ch[c - 'a'] = tt;
        }
        cur = aho[cur].ch[c - 'a']; // vai para o próximo nó
    }
    aho[cur].cnt++; // marca o nó como final de palavra
}

// O(|s|)
bool buildAho(string s){
    queue<pair<int, char>>q;

    for(auto & [v, c]: aho[0].ch){
        q.emplace(v,c);
    }

    while(q.size()){
        auto[u, c] = q.front();
        q.pop();

        // calcular o suffix link
        if(aho[u].par == 0){ // se o nó é a raiz
            int & j = aho[u].suf; // suffix link do nó u
            j = aho[aho[u].par].suf;  // suffix link do pai de u

            while(j != 0 && aho[j].ch.count(c) == 0){ // enquanto não chegar na raiz e não tiver o caractere c
                j = aho[j].suf; // vai para o suffix link do nó j
            }

            if(aho[j].ch.count(c)){
                j = aho[j].ch[c]; // vai para o nó que tem o caractere c
            }
        }

        for (auto &[v, c] : aho[0].ch){
            q.emplace(v, c);
        }
    }
}

int main(){

    string s; cin >> s;

    int n = s.size();
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        string t; cin >> t;
        add(t);
    }

    buildAho(s);

    int cur = 0;
    for(int i = 0; i < n;i++){

    }

    return 0;
}