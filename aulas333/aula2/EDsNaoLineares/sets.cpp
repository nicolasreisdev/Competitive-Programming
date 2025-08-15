#include <set>
#include <iostream>
using namespace std;

struct S {
	string nome;
	int matr;
};

int main() {

	auto comp = [](const S &a, const S &b) { return a.nome < b.nome; };

	//sobre decltype:	
	int x = 0;
	decltype(x) i = 1;

	set<S, decltype(comp) > conjunto(comp); //cria um set com operador de comparacao customizado. Exemplo de utilidade: ter um set em ordem crescente e outro decrescente
	conjunto.insert({"bc",123});
	conjunto.insert({"z",1});
	for(const auto& elem: conjunto) cout << elem.nome << " " << elem.matr << endl;
}