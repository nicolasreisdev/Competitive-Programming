#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

#define all(v) v.begin(),v.end()

int main() {
	int n;
	cin >> n;

	for(int k=0;k<n;k++) {
		int a,g;
		cin >> a >> g;
		vector<int> adds(a),getsv;
		queue<int> 	gets;
		for(int j=0;j<a;j++) cin >> adds[j];
		for(int j=0;j<g;j++) {
			int t;
			cin >> t;
			//gets.push(t);
			getsv.push_back(t);
		}
		sort(all(getsv));
		for(int i:getsv) gets.push(i);
		gets.push(-100); //evitar testar se vazio...

		if(g==0) continue;
		multiset<int> elems;	
		auto it = elems.begin();
		int posIt=0;
		for(int i=1;i<=a;i++) {
			int toAdd = adds[i-1];
			elems.insert(toAdd);


			if(posIt!=0) {
				if(toAdd < *it) {it--;}
			}

			if(gets.front()==i && posIt==0) {
				int z =0;
				it = elems.begin();
				cout << *it << "\n";
				posIt = i;

				gets.pop();
			} 
			
			while(gets.front()==i) {
				posIt++; it++;
				cout << *it << "\n";
				gets.pop();

			}

		}
		if(k!=n-1)
			cout << "\n";
	}
}