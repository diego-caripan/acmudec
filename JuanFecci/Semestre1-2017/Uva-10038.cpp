#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a; i< b; i++)
#define D(a) cout << a << "\n"

int main(){

	int n, aux, aux2;
	bool verif;
	vector <int> vec, vec2;
	while (cin >> n){
		for (int i=0;i<n; i++ ){
			cin >> aux;
			vec.push_back(aux);
			if (i!=0) vec2.push_back(0);
		}

		for (int i=0; i<n-1; i++){
			aux2 = abs(vec[i]-vec[i+1]);
			if (aux2 < n && aux2>0){
				vec2[aux2-1]=1;
			}
		}

		verif = true;
		for (int i=0; i<vec2.size(); i++){
			if (vec2[i]==0){
				verif=false;
				break;
			}
		}

		if (verif) cout << "Jolly\n";
		else cout << "Not jolly\n";

		vec.clear();
		vec2.clear();
	}

}