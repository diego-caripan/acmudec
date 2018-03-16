#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a; i< b; i++)
#define D(a) cout << a << "\n"

int main(){

	long int n, m, o, largo;
	double ret, total, p;
	char auxc;
	string aux;
	map<char, double> precios;
	map<char, double>::iterator it;
	cin >> n;
	REP(i,0,n){
		total=0;
		cin >> m;
		REP(j,0,m){
			cin >> auxc >> p;
			precios[auxc]=p;
		}

		cin >> o;
		cin.ignore();
		auxc='a';
		REP(j,0,o){
			aux = "";
			getline(cin, aux);
			largo = aux.size();
			REP(k,0,largo){
				it = precios.find(aux[k]);
				if(it != precios.end()) total += it->second;
			}
		}
		total/=100;
		printf("%0.2lf$\n", total);
		precios.clear();
	}
	return 0;

}