#include <stdio.h>
int main(){
	int a,b,c;
	scanf("%d %d",&a,&b);
	//scanf("%d",&b);
	if(2*a%b==0)c=2*a/b;
	else c=2*a/b+1;
	if(c==1)c++;
	printf("%d\n",c);
	return 0;
}
