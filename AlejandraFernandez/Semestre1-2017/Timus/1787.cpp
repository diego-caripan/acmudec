#include <iostream>
using namespace std;

int main(){
	int n,k,aux,sum=0;
	cin>>n>>k;
	while (n<1||n>100) cin>>n;
	while(k<1||k>100) cin>>k;
	for(int i=0;i<k;i++){
		cin>>aux;
		aux= aux + sum;
		if(n>=aux) sum=0;
		else if(aux>n) sum= aux-n;
		if(sum<1) sum = sum*-1; 
		}
		
	cout<<sum<< endl;
	return 0;

}