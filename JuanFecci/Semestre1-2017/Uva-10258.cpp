#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a; i< b; i++)
#define D(a) cout << a << "\n"

int main(){

	int n, cont, prob, time;
	char tipo;
	cin >> n;

	string input;
	map <int, pair<int, int> > resultados;

	cin.ignore();
	cin.ignore();
	REP(i,0,n){
		while (1){
			getline(cin, input);
			if (input.compare("\n") != 0){
				stringstream ss(input);
				ss >> cont >> prob >> time >> tipo;
				if (tipo == "C"){
					
				}
				else if (tipo == "I"){
					
				}
			}
			else break;
		}
	}

}