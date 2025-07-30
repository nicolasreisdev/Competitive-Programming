#include <iostream>
#include <algorithm>
using namespace std;

//se possivel, fazer calculos com valores parciais e passar para funcao nas chamadas
//Isso evita ter que varrer o array todo ao chegar em k = n
void geraPerm(bool usei[], int perm[], int k, int n) {
	//se nao for possivel podar: entrada proxima a 13 --> TLE
	if( false ) { //colocar algum teste aqui para podar, se possivel
		return;
	}

	if (k == n+1) { // se terminou de gerar uma permutacao
		cout << "[ ";
		for(int i=1;i<=n;i++)
			cout << perm[i] << " ";
		cout << "]\n";
		return;
	}

	for(int i=1;i<=n;i++) {
		if(!usei[i]) {
			usei[i] = true;
			perm[k] = i;
			geraPerm(usei,perm,k+1,n);
			usei[i] = false; //ATENCAO!
		}
	}
}


int main() {
	int perm[1000]; 		// permutacao parcial
	bool usei[1000] = {false};
	int n;
	cin >> n;
	geraPerm(usei, perm, 1, n); // permutacoes de [0, 1, 2, 3, ..., n-1]
}
