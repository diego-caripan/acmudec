#include <stdio.h>

int main(){
	int nCases, nStud, max=0, curr, i=0, j=0;
	scanf("%d",&nCases);
	while(i<nCases){
		scanf("%d", &nStud);
		while(j<nStud){
			scanf("%d", &curr);
			if(curr > max){
				max = curr;
			}
			j++;
		}
		printf("Case %d: %d\n",i+1, max);
		j=0;
		max=0;
		i++;
	}
	return 0;

}