#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a; i< b; i++)
#define D(a) cout << a << "\n"

int main(){
	int n, maxi;
	char lol;
	string pal, aux, max;
	map<string, int> dic;

	while(cin >> n){
		scanf("%c",&lol);
		getline(cin,pal);
		REP(i,0,pal.size()-n+1){
			aux = pal.substr(i,n);
			dic[aux]++;
		}
		maxi = 0;
		for (map<string,int>::iterator it = dic.begin(); it != dic.end(); it++ ){
			if (it->second >= maxi){
				maxi = it->second;
				max = it->first;
			}
		}
		D(max);
		dic.clear();
		pal.clear();
	}
}