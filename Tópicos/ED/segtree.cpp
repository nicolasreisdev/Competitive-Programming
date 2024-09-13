#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5 + 10;
const int INF = 1e15;

struct Seg{

    vector<ll> v;
    ll seg[4*MAX];
    ll n;

    //O(n)
    int build(int p, int l, int r){
        if(l==r) return seg[p] = v[l]; // se for folha
        int m = (l+r)/2;
        return seg[p] = min(build(2*p, l , m), build(2*p+1,m+1,r)); // constroi a arvore com o minimo dos filhos
        // 2*p é o filho da esquerda e 2*p+1 é o filho da direita
        // ex: build(1,0,7) -> build(2,0,3) build(3,4,7) -> build(4,0,1) build(5,2,3) build(6,4,5) build(7,6,7)
    }

    void build(ll n2, vector<ll> &v2){
        n = n2;
        v=v2;
        build(1,0,n-1);
    }

    // O(4 log n)
    ll query(int a, int b, int p, int l, int r){
        if(b<l or a>r) return INF; // se o intervalo estiver fora do range
        if(a<=l and b>=r) return seg[p];
        int m = (l+r)/2;
        return seg[p] = min(query(a,b,p*2,l,m), query(a,b,p*2+1,m+1,r));
    }


    ll query(int a, int b){
        return query(a,b,1,0,n-1);
    }


    //O( 2 log n)
    ll update(int i, int x, int p, int l, int r){
        if(i<l or i>r) return seg[p];
        if(l==r) return seg[p] = x;
        int m = (l+r)/2;
        return seg[p] = min(update(i,x,2*p,l,m), update(i,x,2*p+1,m+1,r));
    }

    ll update(int i , int x){
        update(i,x,1,0,n-1);
    }

};



int main(){

    ll n = 8;
    vector<ll> v = {13, 3, 6, 20, 18, 6, 10, 4};

    Seg seg;
    seg.build(n, v);
    cout << seg.query(0, 7) << endl;
    seg.update(1, 5);
    cout << seg.query(0, 7) << endl;

    return 0;
}