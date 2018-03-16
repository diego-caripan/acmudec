#include <bits/stdc++.h>
using namespace std;

char Ga[500][500],Pe[500][500];

void rotar(int n){
	char tmp[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			tmp[i][j]=Pe[n-j-1][i];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			Pe[i][j]=tmp[i][j];
		}
	}
}
int encontrar(int n,int m){
	//aplicar l0 del jueguito de 0 y 1 para emcomtrar
	//como en progra 1
	int aux=0,aux2;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i+m<=n and j+m<=n){
				aux2=0;
				for(int k=0;k<m;k++){
					for(int l=0;l<m;l++){
						if(Ga[i+k][j+l]==Pe[k][l])aux2++;
					}
				}
				if(aux2==m*m)aux++;
			}
		}
	}
	return aux;
}
	
int main(){
  int n, m, i;
    while(cin>>n>>m) {
        if(n == 0 && m == 0)
            break;
        for(i = 0; i < n; i++){
        	//char aux;
        	//cin>>aux;
        	//Ga[i]=aux;
            scanf("%s", Ga[i]);
        }
        for(i = 0; i < m; i++){
        	//char aux;
        	//cin>>aux;
        	//Pe[i]=aux;
           	scanf("%s", Pe[i]);
        }
        for(i = 0; i < 4; i++) {
            if(i)
            cout<<" ";
        	cout<<encontrar(n,m);
            rotar(m);
        }
        cout<<endl;
    }
return 0; 
}