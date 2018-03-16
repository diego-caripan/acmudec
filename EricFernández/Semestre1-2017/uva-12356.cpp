#include <bits/stdc++.h>
using namespace std;

int main(){
	int S,B;  // s->soldados por linea de ataque//b->n° de reportes perdidos
	//char a[2];
	while(cin>>S>>B){
		vector <int> lin_D;
		vector <int> lin_I;
		for(int i=0;i<=S;i++){
			lin_D.push_back(i+1);
			lin_I.push_back(i-1);
		}
		int L,R;  // soldados muertos :c
		for(int i=0;i<B;i++){
			cin>>L>>R;
			if(lin_I[L]>=1){
				cout<<lin_I[L]<<" ";
			}
			else{
				cout<<"* ";
			}
			if(lin_D[R]<=S){
				cout<<lin_D[R]<<endl;
			}
			else{
				cout<<"*"<<endl;
			}
			lin_I[lin_D[R]]=lin_I[L];
			lin_D[lin_I[L]]=lin_D[R];
		}
		if(S!=0 && B!=0)cout<<"-"<<endl;
	}
return 0;
	
}