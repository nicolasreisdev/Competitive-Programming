#include <set>
#include <iostream>
#include <map>
using namespace std;


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