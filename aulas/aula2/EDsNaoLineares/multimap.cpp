#include <map>
#include <iostream>
using namespace std;


int main() {
	multimap<int,string> m;
	m.insert(make_pair(2,"teste"));
	m.insert(make_pair(1,"abc"));
	m.insert(make_pair(2,"dois"));
	m.insert(make_pair(2,"DOIS"));
	m.insert(make_pair(5,"zu"));

	auto it = m.lower_bound(2);
	auto itFim = m.upper_bound(2);

	//distancia entre dois iteradores (funciona ate para iteradores que nao sao de acesso aleatorio...)
	//ATENCAO!!!! TEMPO O(N)!!!!!!!!!!!!!
	cout << "Num elementos com mesma chave: " <<distance(it,itFim) << endl;
	while(it!=itFim) {
		cout << it->second << endl;
		it++;
	}
	cout << endl;
	auto parIts = m.equal_range(2); //alternativamente (mais rapido que chamar lower_bound e upper_bound juntos)
	while(parIts.first!=parIts.second) {
		cout << parIts.first->second << endl;
		parIts.first++;
	}
}