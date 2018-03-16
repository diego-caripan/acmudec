#include <stdio.h>
#include <stdlib.h>

void llenar(int* v,int tam){
	int i;
	for(i=0; i<tam ;i++) scanf("%d",&v[i]);
}

int cfun(const void* a, const void* b){
	return (*(int*)b - *(int*)a);
}

int distancia(int* v,int tam){
	return ((v[0]-v[tam-1])*2);
}

int main(){
	int n,i;
	scanf("%d",&n);
	int** v=(int**)malloc(sizeof(int*)*n);
	int a[n];
	for(i=0; i<n ;i++){
		scanf("%d",&a[i]);
		v[i]=(int*)malloc(sizeof(int)*a[i]);
		llenar(v[i],a[i]);
	}
	for(i=0; i<n ;i++) qsort(v[i],a[i],sizeof(int),cfun);
	// EN A TENGO EL TAM, [A-1] ES EL ULTIMO----luego es la distancia(para ahorrar)
	for(i=0; i<n ;i++) a[i]=distancia(v[i],a[i]);
	for(i=0; i<n ;i++) printf("%d\n",a[i]);
	for(i=0; i<n ;i++) free(v[i]);
	free(v);
	return 0;
}