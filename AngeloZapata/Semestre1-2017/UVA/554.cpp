#include <bits/stdc++.h>
using namespace std;

int main(){
	vector <string> dic;
	string aux, aux2, line;
	while(1){
		cin >> aux;
		if(aux.compare("#") == 0) break;
		aux.push_back(' ');
		dic.push_back(aux);
	}
	cin.ignore();
	getline(cin,line);
	bool flag = false;
	while(1){
		for(int i=0; i<dic.size(); i++){
			size_t found = line.find(dic.at(i));
			if (found!=string::npos) {
			  	flag = true;
			  	break;
			}

		}	
		if(flag) break;
		for(int i=0; i<line.size(); i++){
			if(line[i] == ' ') line[i] = 'Z';
			else if(line[i] == 'A') line[i] = ' ';
			else line[i]--;
		}
	}
	//cout << line << endl;
	istringstream iss(line); 
	iss >> aux;
	int largo = aux.size();
	cout << aux;
	while(iss >> aux) {
		if (largo + aux.size() + 1 > 60)  { 
			largo = aux.size();
			cout << endl;
			cout << aux;
		}
		else {
			largo += aux.size() + 1;
			cout << " " << aux;
		}
	}
	cout << endl;
	return 0;
}