#include <bits/stdc++.h>
using namespace std;

int main() {
	while(1){
		int ene=0,eme=0;
		cin>>ene>>eme;
		if(ene==0 && eme==0) break;
		vector <int> cnaito;
		vector <int> jeds;
		if(eme == 0 || ene==0 || eme<ene){ int algo; for(int i=0;i<ene+eme;i++)cin>>algo; cout<<"Loowater is doomed!"<<"\n";}
		else{
			int a;
			for(int i=0;i<ene;i++){
				cin>>a;
				jeds.push_back(a);
			}
			for(int j=0;j<eme;j++){
				cin>>a;
				cnaito.push_back(a);
			}
			sort(jeds.begin(),jeds.end());
			sort(cnaito.begin(),cnaito.end());
			int i=0,j=0;
			int sum = 0;
			int cont=0;
			while(1){
				if(j>=eme || i>=ene) break;
				if(cnaito[j]>= jeds[i]){
					sum+= cnaito[j];
					i++;
					j++;
					cont++;
				}
				else j++;
			}
			if(cont == ene) cout<<sum<<"\n";
			else cout<<"Loowater is doomed!"<<"\n";
		}
		ene=0;eme=0;
	}
}