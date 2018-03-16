#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n][n];
	for(int i=0; i<n;i++){
		for(int j=0;j<n;j++){
			int aux=0;
			scanf("%d",&aux);
			a[i][j]=aux;
		}
	}
	printf("\n");
	
	for(int i=0; i<n;i++){//la primera mitad
		int x=i, y=0;
		while(x>=0 && x<n){
			printf("%d ",a[x][y]);
			x--;
			y++;
		}
	}

	for(int i=0;i<n;i++){//la segunda mitad, maldito n te
		int x=n-1, y=i+1;  // te pasabas de rango
		while(y>0 && y <n){
			printf("%d ",a[x][y]);
			x--;
			y++;
		}
	}
	printf("\n");
	for(int i=0;i<n;i++){printf("\n");
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
	}

}
