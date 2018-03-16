#include <bits/stdc++.h>
using namespace std;
//antes de mandar so funciona
int main(){
	int c,dia,mes,a;
	int me=99999999,ma=0;
	string menor,mayor,l;
	cin>>c;
	while(c--){
		cin>>l>>dia>>mes>>a;
		dia=dia+mes*100+a*10000;
		if(dia<me){
			me=dia;
			menor=l;
		}
		else if(dia>ma){
			ma=dia;
			mayor=l;
		}
	}
	cout<<mayor<<endl;
	cout<<menor<<endl;
return 0;
}