#include <stdio.h>
int main(){
int cant;
scanf("%d",&cant);
int mat[cant][2];
int i,j;
for(i=0;i<cant;i++){
	for(j=0;j<2;j++){
		scanf("%d",&mat[i][j]);
	}
}
for (i=0;i<cant;i++){
	if(mat[i][0]<mat[i][1]){
		printf("<\n");
	}else if(mat[i][0]>mat[i][1]){
		printf(">\n");
	}else{
		printf("=\n");
	}
}
	return 0;
}