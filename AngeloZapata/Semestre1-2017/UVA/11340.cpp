#include <bits/stdc++.h>
using namespace std;

int main(){
	map <char,int> car;
	int n,k,m,val,total;
	string line;
	char c;
	cin >> n;
	while(n){
		total = 0;
		car.clear();
		cin >> k;
		for(int i=0; i<k; i++){
			cin >> c >> val;
			car[c] = val;
		}
		cin >> m;
		for(int i=0; i<m+1; i++){
			getline(cin,line);
			for(int j=0; j<line.size(); j++){
				total+=car[line[j]];
			}
			line.clear();
		}
		printf("%d.%.2d$\n",total/100,(total%100));
		n--;
	}
	return 0;
}