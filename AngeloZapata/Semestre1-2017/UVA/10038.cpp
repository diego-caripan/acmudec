#include <bits/stdc++.h>
#define D(a) cout << a << "\n"
#define REP(i,a,b) for(int i = a; i < b; i++)
using namespace std;

int main(){
	vector <int> num,absol;
	int n,nu;
	while(cin >> n){
		REP(i,0,n){
			cin >> nu;
			num.push_back(nu);
		}
		REP(i,0,n-1){
			absol.push_back(abs(num[i]-num[i+1]));
		}
		sort(absol.begin(),absol.end());
		bool flag = true;
		REP(i,0,n-1){
			if(absol[i] != i+1) flag = false;
		}
		D((flag?"Jolly":"Not jolly"));
		num.clear();
		absol.clear();
	}
	return 0;
}