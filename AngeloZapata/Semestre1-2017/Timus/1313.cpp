#include <bits/stdc++.h>
using namespace std;

int main(){
	int max,aux;
	cin >> max;
	int pixels[max][max];
	for(int i=0; i<max; i++){
		for(int j=0; j<max; j++){
			cin >> pixels[i][j];
		}
	} 
	for(int i=0; i<max; i++){
		for(int j=0; j<=i; j++){
			cout << pixels[i-j][j] << " ";
		}
	}
	for(int i=1; i<max; i++){
		for(int j=max-1; j>=i;j--){
			cout<<pixels[j][max-1-j+i]<<" ";
		}
	}
	cout << endl;
	return 0;
}