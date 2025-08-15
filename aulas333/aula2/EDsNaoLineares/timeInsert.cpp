#include <set>
#include <vector>
#include <list>
#include <unordered_set>
#include <cstdlib>
#include <iostream>
using namespace std;


const int N = 20000000;
template <class T>
void testaSets() {
	T s;
	for(int i=0;i<N;i++) 
		s.insert(i);
	cout << s.size() << "\n";
}

template <class T>
void testaListas() {
	T s;
	for(int i=0;i<N;i++) 
		s.push_back(i);
	cout << s.size() << "\n";
}

template <class T>
void testaListas2() {
	T s;
	s.reserve(N);
	for(int i=0;i<N;i++) 
		s.push_back(i);
	cout << s.size() << "\n";
}

int main(int argc, char **argv) {
	if(argv[1][0]=='l') {
		testaListas<list<int> >();
	}
	if(argv[1][0]=='v') {
		testaListas2<vector<int> >();
	}
	if(argv[1][0]=='s') {
		testaSets<set<int> >();
	}
	if(argv[1][0]=='u') {
		testaSets<unordered_set<int> >();
	}
}