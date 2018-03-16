#include <stdio.h>

int main(){
	int n,i=0,a, b;
	scanf("%d", &n);
	while(i<n){
		scanf("%d %d",&a, &b);
		if(a<b){
			printf("%c\n", '<');
		}
		else if(a>b){
			printf("%c\n", '>');
		}
		else{
			printf("%c\n", '=');
		}
		i++;
	}
	return 0;
}