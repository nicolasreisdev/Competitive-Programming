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
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;



void update(int idx, int val, vector<int> &v, vector<int> &bucket, int bucketsize){
    bucket[idx/bucketsize] += val - v[idx]; // atualizar o valor do bucket
    v[idx] = val; // atualizar o valor do vetor
}

// query USP
ll query(int l, int r, vector<int> &v, vector<int> &bucket, int bucketsize){
    int bl = l / bucketsize; // bucket da esquerda
    int br = r / bucketsize; // bucket da direita

    ll acc = 0;

    for(int i = bl+1; i < br-1;i++)acc += bucket[i]; // somar os buckets inteiros

    // caso especial para esquerda
    for(int i = l; i < (bl+1)*bucketsize; i++){
        acc += v[i]; // somar o valor do vetor
    }

    // caso especial para direita
    if(br != bl){
        for(int i = r; i >= br*bucketsize; i--){
            acc += v[i]; // somar o valor do vetor
        }
    }
    return acc;
}

// query CP-Algorithms
ll query(int l, int r, vector<int> &v, vector<int> &bucket, int bucketsize){
    ll acc = 0;
    for(int i = l; i <= r;){
        if(i % bucketsize == 0 && i + bucketsize - 1 <= r){ // se o intervalo for um bucket inteiro
            acc += bucket[i/bucketsize]; // somar o valor do bucket
            i += bucketsize; // atualizar o índice
        }
        else{ // se não
            acc += v[i]; // somar o valor do vetor
            i++; // atualizar o índice
        }
    }
    return acc;
}

int main(){
    fastio;

    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n;i++) cin >> v[i];

    // criar o vetor de buckets
    const int bucketsize = sqrt(n) + 1;
    const int bucketqntd = (n + bucketsize - 1) / bucketsize; // ceil(n/bucketsize)

    vector<int> bucket(bucketqntd);

    // preencher os buckets
    for(int i = 0; i < n; i++){
        bucket[i/bucketsize] += v[i]; // somar o valor do elemento ao bucket
    }

    // updates e queries
    int q; cin >> q;
    while(q--){
        int op, x, y; cin >> op >> x >> y;
        if(op == 1){ // update
            update(x, y, v, bucket, bucketsize);
        }
        else{ // query , sum(x, y) = sum(l, r)
            cout << query(x, y, v, bucket, bucketsize) << endl;
        }
    }
    return 0;
}