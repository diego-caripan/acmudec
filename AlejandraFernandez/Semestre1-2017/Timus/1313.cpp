#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,num,aux=0;
	cin>>n;
	while(n<1 || n>100) cin>>n;
		int ve[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
			cin>>num;
			ve[i][j]=num;
			}
		}
		for(int i =0;i<n;i++){
			for(int j=0;j<=i;j++){
				cout<<ve[i-j][j]<<" ";
			}		
		}
		for(int i=1;i<n;i++){
			for(int j=n-1;j>=i;j--){
				cout<<ve[j][n-1-j+i]<<" ";
			}
		}

		cout<<endl;
		return 0;		
}