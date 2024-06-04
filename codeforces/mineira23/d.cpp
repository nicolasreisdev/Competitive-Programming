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

vector<pair<p, int>>peias(500);
vector<p>tam;

ll ans = 0;

bool comp(pair<p, int> a, pair<p, int> b){
    return a.s > b.s;
}

/*
if(i+1 == peias[j].f.s){ // se o tamanho do sapato for igual ao tamanho do pe
                if(tam[i].f >= (peias[j].f.f/2) && tam[i].s >= (peias[j].f.f/2)){ // se tiver a quatidade de sapatos necessaria
                    ans += peias[j].s; // soma  a majestosidade
                    tam[i].f -= (peias[j].f.f/2);
                    tam[i].s -= (peias[j].f.f/2);
                }
}*/

int main(){
    int n, t; cin >> n >> t;
    for(int i = 0; i < n;i++){
        int a, b, c; cin >> a >> b >> c;
        peias.pb({{a, b}, c});// a = quantidade de pes, b = tamanho do pe, c = majestosidade
    }
    for(int i = 0; i < t; i++){
        int e, d; cin >> e >> d; // quantidade de sapatos esquerdos e direitos
        tam.pb({e, d}); // tam[0] = quantidade de sapatos E e D de tamanho 1,     
    }
    sort(peias.begin(), peias.end(), comp);
    /*for(int i = 0; i < n; i++){
        cout << peias[i].f.f << " " << peias[i].f.s << " " << peias[i].s << endl;
    }*/
    for(int i = 0; i < peias.size();i++){ // percorre da mais majestosa ate a menos majestosa
        for(int j = 0; j < tam.size();j++){ // percorre o tamanho dos sapatos 
            if(peias[i].f.s == j+1){
                if(peias[i].f.f/2 <= tam[j].f && peias[i].f.f/2 <= tam[j].s){
                    ans += peias[i].s;
                    tam[j].f -= peias[i].f.f/2;
                    tam[j].s -= peias[i].f.f/2;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}