#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,k,h,a,mes,dia;
	vector<vector<int> > p;
	vector<int> aux;
	vector<string> n;
	string joven,viejo,s;
	cin >> N;
	for(int i=0 ; i<N ; i++){
		cin >> s;
		n.push_back(s);
		for(int j=0 ; j<3 ; j++){
			cin >> a;
			aux.push_back(a);
		}
		p.push_back(aux);
		aux.clear();
	}
	aux = p.at(0);
	a = aux.at(2);
	mes = aux.at(1);
	dia = aux.at(0);
	k = 0; h = 0;
	int M1,M2,M3,m1,m2,m3;
	M1 = dia; m1 = dia; // M: mayor, m: menor
	M2 = mes; m2 = mes;
	M3 = a; m3 = a;
	for(int i=1 ; i<N ; i++){
		aux.clear();
		aux = p.at(i);
		a = aux.at(2);
		mes = aux.at(1);
		dia = aux.at(0);
		if(a < M3){		//MAYOR
			viejo = n.at(i);
			M3 = a;
		}
		else if(a == M3){
			if(mes < M2){
				viejo = n.at(i);
				M2 = mes;
			}
			else if(mes == M2){
				if(dia < M1){
					viejo = n.at(i);
					M1 = dia;
				}
			}
		}
		if(a > m3){		//MENOR
			joven = n.at(i);
			m3 = a;
		}
		else if(a == m3){
			if(mes > m2){
				joven = n.at(i);
				m2 = mes;
			}
			else if(mes == m2){
				if(dia > m1){
					joven = n.at(i);
					m1 = dia;
				}
			}
		}
	}
	cout << joven << endl;
	cout << viejo << endl;
	return 0;
}