#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define all(v) v.begin(),v.end()

int main() {
	string st;
	int n;
	while(cin >> n && n!=0) {		
		map<vector<int>,int> freq;
		for(int i=0;i<n;i++) {
			vector<int> cursos(5);
			for(int j=0;j<5;j++) cin >> cursos[j];
			sort(all(cursos));
			freq[cursos]++;
		}
		int mx = 0;
		for(auto &a:freq) if(a.second>mx) mx = a.second;
		int ct = 0;
		for(auto &a:freq) if(a.second==mx) ct += mx;
		cout << ct <<"\n";
	}

}