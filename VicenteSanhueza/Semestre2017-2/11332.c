#include <stdio.h>

int fun(int n){
	if((n%10)==n) return n;
	else{
		int a,b;
		a=n%10;
		b=n/10;
		return ((fun(b))+a);
	}
}

int main(){
	int n,x;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		x=fun(n);
		while(x%10 != x) x=fun(x);
		printf("%d\n",x);
	}
	return 0;
}