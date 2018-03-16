#include <bits/stdc++.h>
using namespace std;

int main(){
	map<string,double> t;
	map<string,double>::iterator it;
	int N,cont;
	double r;
	string aux;
	cin >> N;
	cin.ignore();
	cin.ignore();
	for(int i=0 ; i<N ; i++){
		cont = 0;
		//cin.ignore();
		while(getline(cin,aux)){	
			if(aux.compare("") == 0)
				break;
			t[aux]++;
			cont++;
		}
		for(it=t.begin() ; it!=t.end() ; it++){
			r = it->second;
			r = (r/cont)*100;
			cout << it->first;
			printf(" %.4lf\n",r);
		}
		if(i!=N-1)
			cout << endl;
		t.clear();
	}
	return 0;
}