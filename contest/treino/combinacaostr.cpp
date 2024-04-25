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
const int MAX = 1e5 + 10;
const int MIN = 0;

string multiplica(string num1, string num2)
{
    if (num1 == "0" || num2 == "0")
    {
        return "0";
    }
    string produto(num1.size() + num2.size(), 0);
    for (int i = num1.size() - 1; i >= 0; i--)
    {
        for (int j = num2.size() - 1; j >= 0; j--)
        {
            int n = (num1[i] - '0') * (num2[j] - '0') + produto[i + j + 1];
            produto[i + j + 1] = n % 10;
            produto[i + j] += n / 10;
        }
    }
    for (int i = 0; i < produto.size(); i++)
    {
        produto[i] += '0';
    }
    if (produto[0] == '0')
    {
        return produto.substr(1);
    }
    return produto;
}

int main()
{
    //fórmula de combinação = n! / (n-k)! * k!
    string n, k;
    ll result = 0, sub = 0, resultaux = 0;

    cin >> n >> k;

        string z, aux = n, aux2 = k;
        for (string w = n; w > "1"; w = to_string(stoi(w) - 1))  // for para fazer o fatorial de n
        {
            z = to_string(stoi(w) - 1);
            aux = multiplica(aux, z);
        }
        for (string w = k; w > "1"; w = to_string(stoi(w) - 1)) // for para fazer o fatorial de k
        {
            z = to_string(stoi(w) - 1);
            aux2 = multiplica(aux2, z);
        }
        ll a = stoi(n), b = stoi(k);
        sub = a - b; // n - k
        string aux3 = to_string(sub);
        for (string w = to_string(sub); w > "1"; w = to_string(stoi(w) - 1)) // for para fazer o fatorial de n - k
        {
            z = to_string(stoi(w) - 1);
            aux3 = multiplica(aux3, z);
        }
        resultaux = stoi(aux3) * stoi(aux2); // (n-k)! * k!
        result = stoi(aux) / resultaux;      // n! / (n-k)! * k!
        cout << result << "\n";


    return 0;
}