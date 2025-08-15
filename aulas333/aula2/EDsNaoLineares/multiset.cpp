#include <set>
#include <iostream>
using namespace std;


int main() {
	multiset<int> m;
	m.insert(1);
	m.insert(10);
	m.insert(5);
	m.insert(5);
	m.insert(5);

	for(auto &a:m) cout << a << " "; cout << endl;
	cout << "Num elems: " << m.size() << endl;
  	cout << "Quanos 5? " << m.count(5) << endl; // O(log n + count)

	auto m2 = m;
	m2.erase(5);
	for(auto &a:m2) cout << a << " "; cout << endl;


	auto m3 = m;
	m3.erase(m3.find(5));
	for(auto &a:m3) cout << a << " "; cout << endl;
}