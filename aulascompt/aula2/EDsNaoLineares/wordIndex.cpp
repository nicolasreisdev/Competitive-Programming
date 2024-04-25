#include <map>
#include <iostream>
using namespace std;



int main() {
	int ct = 0;

	map<string,int> m;
	for(char a='a';a<='z';a++) {
		string s;
		s+=a;
		m[s] = ++ct;
	}

	for(char a='a';a<='z';a++) 
		for(char b=a+1;b<='z';b++) {
			string s;
			s+=a;
			s+=b;
			m[s] = ++ct;
		}

	for(char a='a';a<='z';a++) 
	for(char b=a+1;b<='z';b++) 
		for(char c=b+1;c<='z';c++){
			string s;
			s+=a;
			s+=b;
			s+=c;
			m[s] = ++ct;
		}	

	for(char a='a';a<='z';a++) 
	for(char b=a+1;b<='z';b++) 
		for(char c=b+1;c<='z';c++)
			for(char d=c+1;d<='z';d++){
			string s;
			s+=a;
			s+=b;
			s+=c;
			s+=d;
			m[s] = ++ct;
		}

	for(char a='a';a<='z';a++) 
	for(char b=a+1;b<='z';b++) 
		for(char c=b+1;c<='z';c++)
		for(char d=c+1;d<='z';d++)
			for(char e=d+1;e<='z';e++){
			string s;
			s+=a;
			s+=b;
			s+=c;
			s+=d;
			s+=e;
			m[s] = ++ct;
		}

	string q;
	while(cin >> q) {
		if(m.count(q)==0) cout << 0 << "\n";
		else cout << m[q] << "\n";
	}

}