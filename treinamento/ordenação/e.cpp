#include<bits/stdc++.h>
using namespace std;

struct tempo
{
    string dia, mes, ano, hora, min, seg, txt;
};

bool comp(tempo a, tempo b)
{
    if(a.ano != b.ano)
        return stoi(a.ano) < stoi(b.ano);
    else if(stoi(a.mes) != stoi(b.mes))
        return stoi(a.mes) < stoi(b.mes);
    else if(stoi(a.dia) != stoi(b.dia))
        return stoi(a.dia) < stoi(b.dia);
    else if(stoi(a.hora) != stoi(b.hora))
        return stoi(a.hora) < stoi(b.hora);
    else if(stoi(a.min) != stoi(b.min))
        return stoi(a.min) < stoi(b.min);
    else
        return stoi(a.seg) < stoi(b.seg);
}


int main()
{
    string s;
    tempo aux;
    vector<tempo> v;

    while (getline(cin, s))
    {
        aux.ano = (s.substr(6, 4));
        aux.mes = (s.substr(3, 2));
        aux.dia = (s.substr(0, 2));
        aux.hora = (s.substr(11, 2));
        aux.min = (s.substr(14, 2));
        aux.seg = (s.substr(17, 2));
        aux.txt = (s.substr(20));
        v.push_back(aux);
    }
    stable_sort(v.begin(), v.end(), comp);

    for(auto e: v)
    {
        cout << e.dia << '/' << e.mes << '/' << e.ano << ' ' << e.hora << ':' << e.min << ':' << e.seg << ' ' << e.txt << endl;
    }
    

    return 0;
}