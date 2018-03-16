#include <stdio.h>
#include <stdlib.h>

void llenar(int* v, int tam){
	int i;
	for(i=0; i<tam ;i++) scanf("%d",&v[i]);
}

int cfun(const void* a, const void* b){
	return (*(int*)b - *(int*)a);
}

int main(){
	int n;
	scanf("%d",&n);
	int** v=(int**)malloc(sizeof(int*)*n);
	int i,a;
	for(i=0; i<n ;i++){
		scanf("%d",&a);
		v[i]=(int*)malloc(sizeof(int)*a);
		llenar(v[i],a);
		qsort(v[i],a,sizeof(int),cfun);
	}
	for(i=0; i<n ;i++) printf("Case %d: %d\n",i+1,v[i][0]);
	for(i=0; i<n ;i++) free(v[i]);
	free(v);
	return 0;
}