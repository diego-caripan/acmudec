#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<string> v;
	string s,d = " ";
	int cont = 0;
	while(cin >> s){
		if(s.compare("9") != 0){
			v.push_back(s);
		}
		else{
			cont++;
			d = " ";
			sort(v.rbegin(),v.rend());
			for(int i=0 ; i<v.size() ; i++){
				string aux = v[i];
				for(int j=0 ; j<v.size() ; j++){
					s = v[j];
					if(aux.size() <= s.size() && i != j){
						string asd = s.substr(0,aux.size());
						if(asd.compare(aux)==0){
							d = " not ";
							break;
						}
					}
				}
				if(s.compare(" not ") == 0)
					break;
			}
			cout << "Set " << cont << " is" << d << "immediately decodable" << endl;
			v.clear();
		}
	}
	return 0;
}