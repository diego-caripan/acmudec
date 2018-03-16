#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin>>n and n){
		int primero=0;
		while(cin>>primero and primero){
			//llenar con lso carros
			vector<int> tren(n,primero);
			for(int i=1;i<n;i++){
				int carro;
				cin>>carro;
				tren[i]=carro;
			}
			stack<int> estacion;
			int contador=1,sig=1;
			for(int i=0;i<n;i++){
				int carro = tren[i];
				while(contador<=carro){
					//cout<<"contador="<<contador<<"en i="<<i<<endl;;
					estacion.push(contador++);
				}
				//cout<<endl;
				if(estacion.top()!=carro){
					sig=0;
					break;
				}
				estacion.pop();
			}
			if(sig!=0) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		cout<<endl;
	}
	return 0;
}