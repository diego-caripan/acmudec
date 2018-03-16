#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	while(cin>>n>>m){
		if(n==0 && m==0) return 0;
		vector <int> knight;
		vector <int> heads;
		if(m == 0 || n==0 || m<n){ 
			int algo; 
			for(int i=0;i<n+m;i++)cin>>algo; 
				cout<<"Loowater is doomed!"<<"\n";
		}
		else{
			int aux;
			for(int i=0;i<n;i++){
				cin>>aux;
				heads.push_back(aux);
			}
			for(int j=0;j<m;j++){
				cin>>aux;
				knight.push_back(aux);
			}
			sort(heads.begin(),heads.end());
			sort(knight.begin(),knight.end());
			int i,j,sum,cont;
			i = j = sum = cont = 0;
			while(1){
				if(j>=m || i>=n) break;
				if(knight[j] >= heads[i]){
					sum+= knight[j];
					i++;
					j++;
					cont++;
				}
				else j++;
			}
			if(cont == n) cout<<sum<<"\n";
			else cout<<"Loowater is doomed!"<<"\n";
		}
	}
}