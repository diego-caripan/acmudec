#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,l;
	string numero;
	cin>>n;
	while(n--){
		cin>>numero;
		l=numero.length();
		if(numero=="1" || numero=="4" || numero=="78"){
			cout<<"+"<<endl;
		}
		else if(numero[l-2]=='3' && numero[l-1]=='5'){
			cout<<"-"<<endl;
		}
		else if (numero[0] == '9' && numero[l - 1] == '4'){
			cout<<"*"<<endl;
		}
		else if (numero[0] == '1' && numero[1] == '9' && numero[2] == '0'){
			cout<<"?"<<endl;
		}
		else{
			cout<<"+"<<endl;
		}
	}
	return 0;
}
