/*
	CODIGO PROPIO
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	getline(cin,str);
	while(str!="*"){
		transform(str.begin(),str.end(),str.begin(),::tolower);
		istringstream iss(str);
		string aux;
		bool work=true;
		iss>>aux;
		char check=aux[0];
		while(iss>>aux){
			if(check!=aux[0]){
				work=false;
				break;
			}
		}
		cout<<(work?"Y":"N")<<endl;
		getline(cin,str);
	}
	return 0;
}