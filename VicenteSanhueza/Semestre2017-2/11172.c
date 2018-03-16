#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int v[n];
	int i,a,b;
	for(i=0; i<n ;i++){
		scanf("%d",&a);
		scanf("%d",&b);
		if(a<b)	v[i]=-1;
		if(a==b) v[i]=0;
		if(a>b)	v[i]=1;
	}
	for(i=0; i<n ;i++){
		if(v[i]==-1) printf("<\n");
		if(v[i]==0) printf("=\n");
		if(v[i]==1) printf(">\n");
	}
	return 0;
}