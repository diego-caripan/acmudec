#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	string st,st2;
	map <string , string> map;
	map <string , string> :: iterator it;
	cin >> t;
	getchar();
	while(t--){
		getline(cin ,st);
		getline(cin , st2);
		map[st] = st2;
	}
	cin >> n;
	getchar();
	while(n--){
		getline(cin ,st);
		it = map.begin();
		while(it!=map.end()){
			if(it->first==st){
				cout << it->second << endl;
				break;
			}
			else if(it->second==st){
				cout << it->first << endl;
				break;
			}
			it++;
		}
	}
	return 0;
}