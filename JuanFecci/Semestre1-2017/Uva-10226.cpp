#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a; i< b; i++)
#define D(a) cout << a << "\n"

int main(){

	int n;
	double tot;
	string inp;

	map <string, double> num;

	cin >> n;
	cin.ignore();
	cin.ignore();
	REP(i,0,n){
		if (i!=0) cout << endl;
		tot = 0;
		while (1){
			if(getline(cin, inp)){
				if (inp.compare("") != 0){
					num[inp] += 1;
					tot += 1;
				}
				else break;
			}
			else break;
		}
		for (map<string, double>::iterator it = num.begin(); it != num.end(); it++){
			cout << it->first;
			printf(" %.4lf\n", it->first, (it->second / tot)*100);
		}
		num.clear();
	}

}