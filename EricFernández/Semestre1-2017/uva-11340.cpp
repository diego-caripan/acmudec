#include <bits/stdc++.h>
using namespace std;
//que magicos los map
int main(){
	int casos,K,M,L;
	map<char,double> mapa;
	map<char,double>::iterator it;
	char clave;
	string st;
	double valor,total;
	cin>>casos;
	while(casos--){
		total=0;
		cin>>K;
		for(int i=0;i<K;i++){
			cin>>clave>>valor;
			mapa[clave]=valor;
		}
		cin>>M;
		cin.ignore(256,'\n');
		for(int i=0;i<M;i++){
			getline(cin,st);
			L=st.size();
			for(int j=0;j<L;j++){
				it=mapa.find(st[j]);
				//aprovechando que se pone en 0 cuando
				//se inicializa
				if(it !=mapa.end())total+=it->second;
			}
		}
		total=total/100;
		printf("%0.2lf$\n", total);
		mapa.clear();
	}
	return 0;
}