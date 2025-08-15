#include <set>
#include <iostream>
#include <map>
#include <multiset>
using namespace std;

//K = tipo da prioridade
//V = tipo dos elementos armazenados na fila de prioridade
#template<class K, class V>
class MyPq {
	MyPq(): size(0) {}
	void insert(const K &peso, const V &valor) {

	}

private:
	map<K, set<V> > elementos;
	int size;
};


int main() {
	map<int, set<string> > pq;

	pq[15].insert("teste");
	pq[25].insert("abc");
	pq[15].insert("inf333");

	auto & elemsMenorPriori = (pq.begin()->second);
	for(auto &elem:elemsMenorPriori) cout << elem << endl;

	//mudando prioridade de inf333 de 15 para 1
	pq[15].erase("inf333");
	if(pq[15].size()==0) pq.erase(pq.find(15)); //evita manter um set vazio com prioridade...
	pq[1].insert("inf333");

	cout << endl;
	auto & elemsMenorPriori2 = (pq.begin()->second);
	for(auto &elem:elemsMenorPriori2) cout << elem << endl;
}