#include <iostream>
#include <algorithm>
using namespace std;

// se possivel, fazer calculos com valores parciais e passar para funcao nas chamadas
// Exemplo: se tem que somar os elementos --> ao marcar true, some e passe recursivamente
// Isso evita ter que varrer o array todo ao chegar em k = n
void geraSub(bool c[], int v[], int k, int n)
{
	// se nao for possivel podar: entrada proxima a 30 --> TLE
	if (false)
	{ // colocar algum teste aqui para podar, se possivel
		return;
	}

	if (k == n)
	{ // se terminou de gerar um subconjunto
		cout << "{ ";
		for (int i = 0; i < n; i++)
			if (c[i])
				cout << v[i] << " ";
		cout << "}\n";
		return;
	}

	c[k] = true; // subconjuntos com o elemento k
	geraSub(c, v, k + 1, n);
	c[k] = false; // subconjuntos sem o elemento k
	geraSub(c, v, k + 1, n);
}

int main()
{
	bool c[1000]; // subconjunto parcial
	int v[1000];  // elementos
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	geraSub(c, v, 0, n); // subconjuntos de {0, 1, 2, 3, ..., n-1}
}