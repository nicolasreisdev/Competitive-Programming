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
// #define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;


class SuffixArray {
    private:
    vector<int> ra;

    void countingSort(int k){
        int maxi = max(300, n);
        vector<int> c(maxi, 0);

        for(int i = 0; i < n;++i) ++c[i+k < n ? ra[i+k] : 0];

        for(int i = 0, sum = 0; i < maxi; ++i){
            int aux = c[i]; c[i] = sum; sum+= aux;
        }

        vector<int> tempSA(n);

        for(int i = 0; i < n;++i){
            tempSA[c[sa[i]+k < n ? ra[sa[i]+k] : 0]++] = sa[i];
        }
        swap(sa, tempSA);
    }

    void constructSA(){
        sa.resize(n);

        iota(sa.begin(), sa.end(), 0);

        ra.resize(n);
        for(int i = 0; i < n; ++i) ra[i] = s[i];

        for(int k = 1; k < n;k <<= 1){
            countingSort(k);
            countingSort(0);
            vector<int> tempRA(n);
            int r = 0;
            tempRA[sa[0]] = r;
            for(int i = 1; i < n; ++i){
                tempRA[sa[i]] = ((ra[sa[i]] == ra[sa[i - 1]]) && (ra[sa[i] + k] == ra[sa[i - 1] + k])) ? r : ++r;
            }
            swap(ra, tempRA);
            if(ra[sa[n-1]] == n-1) break;
        }
    }

public:
    string s;
    const int n;
    vector<int> sa;
    vector<int> lcp;

    SuffixArray(const string _s) : s(_s), n(_s.size()){
        constructSA();
    }

};


int main(){
    fastio;

    string s;
    while(getline(cin, s)){
        int n; cin >> n; 
        SuffixArray sf(s);
        for(int i = 0; i < n;i++){
            int pos; cin >> pos;
            cout << sf.sa[pos] << " ";
        }
        cout << endl;
        cin.ignore();
    }

    
    return 0;
}