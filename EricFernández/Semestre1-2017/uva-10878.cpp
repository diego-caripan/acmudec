#include <bits/stdc++.h>
using namespace std;

int main(){
	string st;
	while(getline(cin,st)){
		if(st[0]=='|'){
			if(st[0]=='_')break;
			int cont=0;
			for(int i=1;i<st.size()-1;i++){
				if(st[i]==' ' || st[i]=='o'){
					cont *=2;
				}
				if(st[i] == 'o'){
					cont++;
				}
			}
			cout << (char)cont;
		}
		//cin.ignore();
	}
	return 0;
}