#include <bits/stdc++.h>
#include <map>
using namespace std;

int main(){
	int N,cont=0;
	string s,a,pass;
	map<string,int> m;
	while(cin >> N){
		cin >> s;
		for(int i=0 ; i<s.size()-N+1 ; i++){
			a = s.substr(i,N);
			m[a]++;
		}
		for(map<string,int>::iterator it=m.begin() ; it!=m.end() ; it++){
			if(it->second > cont){
				pass = it->first;
				cont = it->second;
			}
		}
		cout << pass << endl;
		m.clear();
		cont = 0;
	}
	return 0;
}