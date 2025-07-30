#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
using namespace std;

#define all(v) v.begin(),v.end()

int main() {
	set<string> words;
	string st;
	while(getline(cin,st)) {
		for(char &c:st) {
			if(c>='A' && c<='Z') c= c-'A'+'a';
			if(c<'a' || c>'z') c = ' ';			
		}
		stringstream ss(st);
		string word;
		while(ss>>word) words.insert(word);
	}
	for(auto &s:words) cout  << s << "\n";
}