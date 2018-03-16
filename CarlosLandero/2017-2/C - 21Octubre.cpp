#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int expX[100];
int expY[100];
long long int coeff[100];


long long int binomialCoeff(int n, int k){
	long long int C[n+1][k+1];
	int i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=min(i,k);j++){
			if(j==0 || j==i){
				C[i][j] = 1;
			}
			else{
				C[i][j] = C[i-1][j-1] + C[i-1][j];
			}
		}
	}
	return C[n][k];
}


int main(){
	int casos;	
	scanf("%d",&casos);
	int i;
	while(casos--){
		int N;
		scanf("%d",&N);
		if(N==0){
			cout << 1 << endl;
			continue;
		}
		int mx=N;
		int my=0;
		i=0;
		while(mx>=0 && my<=N){
			coeff[i] = binomialCoeff(N,my);
			expX[i] = mx;
			mx--;
			expY[i] = my;
			my++;
			i++;
		}
		for(int k=0;k<i;k++){
				if(coeff[k]!=1){
					cout << coeff[k];
				}		
				if(expX[k]==1){
					cout << "x";
				}
				else if(expX[k]>1){
					cout << "x^"<<expX[k];
				}
				if(expY[k]==1){
					cout << "y";
				}
				else if(expY[k]>1){
					cout << "y^"<<expY[k];
				}
				if(k<i-1){
					cout << "+";
				}
			}
		cout << endl;
	}
	return 0;
}
