#include <bits/stdc++.h>
using namespace std;

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

#define LSOne(S) ((S) & -(S))

class BIT{
    private:
    vector<ll> ft;
    
    public:

    // O(n)
    // cria uma ft vazia 
    BIT(int n){ft.assign(n+1,0); } // inicializa a BIT de 1 a n com 0

    // O(n)
    // cria uma FT baseada em f (lembre que f[0] = 0)
    BIT(const vector<ll> &f){
        int n = (int)f.size() - 1;
        ft.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i){
            ft[i] += f[i];
            if (i + LSOne(i) <= n){
                ft[i + LSOne(i)] += ft[i];
            }
        }
    }

    // O(log n)
    // mesmo que RSQ(1,j)
    ll rsq(int j){
        ll sum = 0;
        for(;j;j-=LSOne(j))sum+= ft[j];
        return sum;
    }

    // O(log n)
    //principio de inclusão/exclusao RSQ no intervalo [i,j]
    ll rsq(int i, int j){return rsq(j) - rsq(i-1); }


    //O(log n)
    // soma v no i-esimo elemento (v pode ser positivo ou negativo)
    void update(int i, ll v){
        for(; i < (int)ft.size();i += LSOne(i)){
            ft[i] += v;
        }
    }


    // O(log n)
    //retorna o indice  do primeiro elemento  que o PrefixSum é >= k
    // EX: em um array  [0,1,3,5,7] o PrefixSum array é [0,1,4,9,16]
    // se k = 9, select(k) = 3, que é o primeiro indice onde PrefixSum >= k
    int select(ll k){
        int p = 1;
        while(p*2 < (int)ft.size()) p*= 2;
        int i = 0;
        while(p){
            if(k > ft[i+p]){
                k -= ft[i+p];
                i += p;
            }
            p /= 2;
        }
        return i+1;
    } 

};

// Variante Range Update Point Query
class RUPQ{
private:
    BIT ft;

public:
    // O(n)
    RUPQ(int n) : ft(BIT(n)) {}

    // O(log n)
    void range_update(int ui, int uj, ll v){
        ft.update(ui, v);
        ft.update(uj + 1, -v);
    }

    // O(log n)
    ll point_query(int i) { return ft.rsq(i); }
};

// Variante Range Update Range Query
class RURQ{
private:
    RUPQ rupq;
    BIT purq;

public:
    // O(n)
    RURQ(int n) : rupq(RUPQ(n)), purq(BIT(n)) {}

    // O(log n)
    void range_update(int ui, int uj, ll v){
        rupq.range_update(ui, uj, v);
        purq.update(ui, v * (ui - 1));
        purq.update(uj + 1, -v * uj);
    }

    // O(log n)
    ll rsq(int j){
        return rupq.point_query(j) * j - purq.rsq(j);
    }

    // O(log n)
    ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); }
};

int main(){
    cout << "===== PURQ Padrão =====" << endl;
    vector<ll> f = {0, 0, 1, 0, 1, 2, 3, 2, 1, 1, 0}; // indice 0 eh sempre 0

    BIT ft(f);
    cout << ft.rsq(1, 6) << endl; // 7
    cout << ft.select(7) << endl; // 6, porque rsq(1, 6) == 7, que eh >= 7
    ft.update(5, 1);              // adicionar 1 ao indice 5
    cout << ft.rsq(1, 6) << endl; // agora 8

    cout << endl
         << "===== RUPQ =====" << endl;
    RUPQ rupq(10);
    rupq.range_update(2, 9, 7); // indices em [2, 3, .., 9] atualizados por +7
    rupq.range_update(6, 7, 3); // indices 6&7 atualizados por +3 (10)
    for (int i = 1; i <= 10; i++)
    {
        cout << i << " -> " << rupq.point_query(i) << endl;
    }

    cout << endl
         << "===== RURQ =====" << endl;
    RURQ rurq(10);
    rurq.range_update(2, 9, 7);                         // indices em [2, 3, .., 9] atualizados por +7
    rurq.range_update(6, 7, 3);                         // indices 6&7 atualizados por +3 (10)
    cout << "RSQ(1, 10) = " << rurq.rsq(1, 10) << endl; // 62
    cout << "RSQ(6, 7) = " << rurq.rsq(6, 7) << endl;   // 20

    return 0;
}