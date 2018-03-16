#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	while(n!=0){
		vector <int> nums;
		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			nums.push_back(a);
		}
		for(int m=0;m<n;m++){
		//	printf("%d ",nums[m]);
			for(int u=m+1;u<n;u++){
		//		printf("%d ",nums[u]);
				for(int r=u+1;r<n;r++){
		//			printf("%d ",nums[r]);
					for(int c=r+1;c<n;c++){
		//				printf("%d ",nums[c]);
						for(int i=c+1;i<n;i++){
		//					printf("%d ",nums[i]);
							for(int e=i+1;e<n;e++){
								printf("%d %d %d %d %d %d\n",nums[m],nums[u],nums[r],nums[c],nums[i],nums[e]);
							}
						}
					}
				}
			}
		}
		scanf("%d",&n);
		if(n!=0) printf("\n");
	}
}