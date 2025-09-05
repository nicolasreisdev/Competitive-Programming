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

void update(int idx, int val, vector<ll> &v, vector<ll> &bucket, int bucketsize){
    bucket[idx / bucketsize] += val - v[idx]; // atualizar o valor do bucket
    v[idx] = val;                             // atualizar o valor do vetor
}

ll query(int l, int r, vector<ll> &v, vector<ll> &bucket, int bucketsize){
    int bl = l / bucketsize; // bucket da esquerda
    int br = r / bucketsize; // bucket da direita

    ll acc = 0;

    for (int i = bl + 1; i < br - 1; i++)
        acc += bucket[i]; // somar os buckets inteiros

    // caso especial para esquerda
    for (int i = l; i < (bl + 1) * bucketsize; i++){
        acc += v[i]; // somar o valor do vetor
    }

    // caso especial para direita
    if (br != bl){
        for (int i = r; i >= br * bucketsize; i--){
            acc += v[i]; // somar o valor do vetor
        }
    }
    return acc;
}


int main(){
    fastio;

    int n, q; cin >> n >> q;
    vector<ll> v(n);
    for(int i = 0; i < n;i++){
        cin >> v[i];
    }

    const int bucketsize = sqrt(n) + 1;
    const int bucketqntd = (n + bucketsize - 1) / bucketsize;

    vector<ll> bucket(bucketqntd);

    for (int i = 0; i < n; i++){
        bucket[i / bucketsize] += v[i]; // somar o valor do elemento ao bucket
    }
    while(q--){
        int op; cin >> op;
        if(op == 1){
            ll k, u; cin >> k >> u;
            update(k-1, u, v, bucket, bucketsize);
        }
        else{
            ll l, r; cin >> l >> r;
            cout << query(l-1, r, v, bucket, bucketsize) << endl;
        }
    }

    return 0;
}