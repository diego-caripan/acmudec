/*
	CODIGO PROPIO

*/
#include <bits/stdc++.h>

using namespace std;

int mat[105][105];
int n,r,c,k;
int y[4]={1,-1,0,0};
int x[4]={0,0,1,-1};
void battle(){
	int m2[105][105];
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			m2[i][j]=mat[i][j];
			int enemigo=mat[i][j]-1;
			if(enemigo==-1)
				enemigo=n-1;
			for(int k=0;k<4;k++){
				if(mat[i+x[k]][j+y[k]]==enemigo){
					m2[i][j]=enemigo;
				}
			}
		}
	}
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			mat[i][j]=m2[i][j];
		}
	}
}

int main(){	
	while(cin >> n >> r >> c >> k && n+r+c+k){
		for(int i=0;i<105;i++){
			for(int j=0;j<105;j++){
				mat[i][j]=-5;
			}
		}
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				cin>>mat[i][j];
			}
		}
		for(int i=0;i<k;i++){
			battle();
		}
		for(int i=1;i<=r;i++){
			cout<<mat[i][1];
			for(int j=2;j<=c;j++){
				cout<<" "<<mat[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}