#include <stdio.h>

int main(){
	int n,n2,i=0,j=0, min, max,curr;
	scanf("%d", &n);
	while(i<n){
		min = 100;
		max = -1;
		scanf("%d", &n2);
		while(j<n2){
			scanf("%d", &curr);
			if(curr < min){
				min = curr;
			}
			if(curr > max){
				max = curr;
			}
			j++;
		}
		printf("%d\n", 2*(max-min));
		j=0;
		i++;		
	}
	
	return 0;
}
