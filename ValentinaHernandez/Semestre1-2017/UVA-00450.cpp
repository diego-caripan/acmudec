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
		getline(cin,dep);
		while(1){
			getline(cin,aux);
			if(aux.compare("") == 0)
				break;
			h = 0;
			//cout << aux << endl;
			for(j=0 ; j<aux.size() ; j++){
				if(aux[j] == ','){
					asd = aux.substr(h,j-h);
					a.push_back(asd);
					h = j+1;
				}
			}
			asd = aux.substr(h,j-h);
			a.push_back(asd);
			a.push_back(dep);

			//cout << a.size() << endl;
			for(j=0 ; j<a.size() ; j++){
				//cout << "sfsdf" << endl;
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
	sort(holen.begin(),holen.end());
	for(i=0 ; i<holen.size() ; i++){
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