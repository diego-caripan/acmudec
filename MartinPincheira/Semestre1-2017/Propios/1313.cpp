#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	
	int n;
	int matriz[100][100];
	int x = 0;
	
	cin >> n;

	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin >> matriz[i][j];
		}
	}

	int k;
	for(i=0;i<2*n-1;i++){
		for(k=0;(k<n) && (k<=i);k++){
	
			x = i - k;
			
			if(x<n && x>=0){
				cout << matriz[x][k] << endl;			
			}

		}
	}
	
	return 0;
}
