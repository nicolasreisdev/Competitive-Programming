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

void computeLPSArray(string &pat, int M, vector<int> &lps){ // pat é o padrão, M é o tamanho do padrão, lps é o vetor que armazenará o tamanho do maior prefixo que é sufixo
    int len = 0; // tamanho do prefixo que é igual ao sufixo
    lps[0] = 0;  // lps[0] é sempre 0
    int i = 1;   // i é o indice que percorre o vetor
    while (i < M){ // enquanto não percorrer todo o vetor
        if (pat[i] == pat[len]){  // se o caractere atual for igual ao caractere do prefixo que é sufixo
            len++;        // aumenta o tamanho do prefixo que é sufixo
            lps[i] = len; // o tamanho do prefixo que é sufixo é igual a len
            i++;          // avança para o próximo caractere
        }
        else{ // se os caracteres forem diferentes
            if (len != 0){ // se o tamanho do prefixo que é sufixo for diferente de 0
                len = lps[len - 1]; // o tamanho do prefixo que é sufixo é igual ao tamanho do prefixo que é sufixo do caractere anterior
            }
            else{ // se o tamanho do prefixo que é sufixo for 0
                lps[i] = 0; // o tamanho do prefixo que é sufixo é 0
                i++;        // avança para o próximo caractere
            }
        }
    }
    /*for(auto test: lps){
        cout << test << " ";
    }
    cout << endl;*/
}

vector<int> KMP(string &pat, string &txt){
    int m = pat.size();           // tamanho do padrão
    int n = txt.size();           // tamanho do texto
    vector<int> lps(m);           // vetor que armazenará o tamanho do maior prefixo que é sufixo
    vector<int> ans;              // vetor que armazenará as posições do texto onde o padrão foi encontrado
    computeLPSArray(pat, m, lps); // chama a função que calcula o vetor lps

    int i = 0; // indice que percorre o texto
    int j = 0; // indice que percorre o padrão
    while (i < n){ // enquanto não percorrer todo o texto
        if (pat[j] == txt[i] || txt[i] == '?'){// se o caractere do padrão for igual ao caractere do texto ou é uma interrogação
            i++; // avança para o próximo caractere do texto
            j++; // avança para o próximo caractere do padrão
            if (txt[i-1] == '?' && txt[i] == '?'){
                txt[i-1] = pat[j-1];
                txt[i] = pat[j];
            }
            else txt[i-1] = pat[j-1];
            //cout << txt << " " << j <<  endl;
            }
        if (j == m){// se j for igual ao tamanho do padrão
            ans.pb(i - j);  // adiciona a posição do texto onde o padrão foi encontrado
            j = lps[j - 1]; // j é igual ao tamanho do prefixo que é sufixo do caractere anterior
            //cout << j << lps[j-1] << endl;
        }
        else if (i < n && pat[j] != txt[i] && txt[i] != '?'){ // se i for menor que o tamanho do texto e os caracteres forem diferentes
            if (j != 0){ // se j for diferente de 0
                j = lps[j - 1]; // j é igual ao tamanho do prefixo que é sufixo do caractere anterior
            }
            else{ // se j for igual a 0
                i++; // avança para o próximo caractere do texto
            }
        }
    }
    return ans; // retorna o vetor com as posições do texto onde o padrão foi encontrado
}

int main(){
    fastio;

    string pattern, target;
    cin >> pattern >> target;

    vector<int> ans = KMP(target, pattern);
    if(ans.size() > 0) cout << ans.size() << endl;
    else cout << -1 << endl;
    /*for(auto resp: ans){
        cout << resp << endl;
    }*/

    return 0;
}