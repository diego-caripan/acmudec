#include <bits/stdc++.h>
using namespace std;

int main(){
	vector <int> d = {5,10,20,50,100,200,500,1000,2000,5000,10000};
	vector<long long int> depe(30000);
	depe[0] = 1;
	for(int i=0;i<11;i++){
		for(int j=d[i];j<30001;j++){
			depe[j] += depe[j - d[i]];
		}
	}
	float n;
	scanf("%f",&n);
	depe[5] = 1;
	depe[0] = 1;
	while(n!=0){
		int aux = n;
		printf("%6.2f%17lld\n",n,depe[int(n*100 +0.5)]);
	scanf("%f",&n);
	}
}