#include <bits/stdc++.h>
using namespace std;

bool verif(int i, int j){
	vector<bool> comp(10,false);
	bool flag = true;
	for(int k=0; k<5; k++){
		//if(i%10 == 0) continue;
		if(!comp[(i%10)]){
			comp[(i%10)] = true;
			i/=10;
		}
		else return false;
	}
	for(int k=0; k<5; k++){
		//if(j%10 == 0) continue;
		if(!comp[(j%10)]){
			comp[(j%10)] = true;
			j/=10;
		}
		else return false;
	}
	for(int k=0; k<comp.size(); k++){
		if(!comp[k]) flag = false;
	}
	if(flag) return true;
	else return false;
}
int main(){
	int n;
	scanf("%d",&n);
	while(1){
		bool flag = false;
		for(int j=1; j<99999; j++){
			int i = n*j;
			if(i > 98765) break;
			if(verif(i,j)){
				printf("%.5d / %.5d = %d\n", i,j,n);
				flag = true;
			
			}
		}
		if(!flag) printf("There are no solutions for %d.\n",n);
		scanf("%d",&n);
		if(n == 0) return 0;
		printf("\n");
	}
}