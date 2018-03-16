#include <cstdio>

using namespace std;

int main(){
	int N=0;
	int bets[10001];

	while(scanf("%d",&N) && N > 0){
		for(int i=0;i<N;i++){
			scanf("%d",&bets[i]);
		}
		int max=0;
		int sum=0;
		for(int i=0;i<N;i++){
			sum += bets[i];
			if(sum < 0){
				sum = 0;
			}
			else if(sum > max){
				max = sum;
			}
		}
		if(max > 0){
			printf("The maximum winning streak is %d.\n",max);
		}
		else{
			printf("Losing streak.\n");
		}
	}
	return 0;
}
