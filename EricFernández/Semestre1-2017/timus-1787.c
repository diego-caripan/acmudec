#include <stdio.h>
int main(){
	int n,k,at=0;
	scanf("%d %d",&n,&k);
	for(int i=0;i<k;i++){
		int autos=0;
		scanf("%d",&autos);
		if(autos>n)at=at+(autos-n);
		else if(autos<=n && at!=0)at=at-(n-autos);
		if(at<=0)at=0;
		//printf(" %d acumulado en %d \n", at,i);
	}
	printf("%d", at);

}