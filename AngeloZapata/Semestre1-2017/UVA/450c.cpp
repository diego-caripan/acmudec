//https://github.com/dseco/acmudec/blob/master/ValentinaHernandez/Semestre1-2017/UVA-00450.cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<vector<string> > holen;
	vector<string> st,a;
	string aux, dep,asd;
	int N,h,j,i,k;
	cin >> N;
	cin.ignore();
	for(k=0 ; k<N ; k++){
		getline(cin,dep);		//lee la lines del departament.
		while(1){
			getline(cin,aux);			//lee la linea de datos.
			if(aux.compare("") == 0)
				break;
			h = 0;
			//cout << aux << endl;
			for(j=0 ; j<aux.size() ; j++){	//saca los datos importantes de la linea.
				if(aux[j] == ','){
					asd = aux.substr(h,j-h);
					a.push_back(asd);			// los almacena en un vector.
					h = j+1;
				}
			}
			asd = aux.substr(h,j-h);
			a.push_back(asd);					//termina almacenando el numero y el dep
			a.push_back(dep);					//en el vector.

			//cout << a.size() << endl;
			for(j=0 ; j<a.size() ; j++){
				//cout << "sfsdf" << endl;		//ordena en vector.
				if(j == 0){
					st.push_back(a.at(2));
				//cout << "ñe" << a.at(2) << endl;
					}
				else if(j == 2)
					st.push_back(a.at(0));
				else
					st.push_back(a.at(j));
			}	
			holen.push_back(st);
			a.clear();
			st.clear();
		}
	}
	sort(holen.begin(),holen.end());		//hace un sort para ordenar los nombres.
	for(i=0 ; i<holen.size() ; i++){		// despliega el output.
		a = holen.at(i);
			cout << "----------------------------------------" << endl;
			cout << a.at(2) << " " << a.at(1) << " " << a.at(0) << endl;
			cout << a.at(3) << endl;
			cout << "Department: " << a.at(7) << endl;
			cout << "Home Phone: " << a.at(4) << endl;
			cout << "Work Phone: " << a.at(5) << endl;
			cout << "Campus Box: " << a.at(6) << endl;
		
	}
}