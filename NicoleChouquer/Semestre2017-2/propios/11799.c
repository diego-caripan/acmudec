#include <stdio.h>

int main(){

	int n;
	int t = 0;
	int t2 = 0;
	int t3 = 0;
	int k=0;

	scanf("%d",&n);

	int cases[n];

	for(int i=0; i<n; i++){

		scanf("%d",&t);

		for(int j=0; j<t; j++){

			scanf("%d",&t2);

			if(t2>t3){
				t3 = t2;
			}
		}

		cases[k] = t3;
		t = 0;
		t2 = 0;
		t3 = 0;
		k++;

	}

	k=1;

	for(int i=0; i<n; i++){
		printf("Case %d: %d\n",k, cases[i]);
		k++;
	}

	return(0);
}