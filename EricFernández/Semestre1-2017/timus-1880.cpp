#include <bits/stdc++.h>
using namespace std;


int main(){
	vector <int> A,B;
	int cont=0,aux,n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&aux);
		A.push_back(aux);
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&aux);
		B.push_back(aux);
	}
	//ahora hay que reconocer si estan el pinche numero cagon
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&aux);
		for(int j=0;j<A.size();j++){
			if(aux==A[j]){
				for(int k=0;k<B.size();k++){
					if(aux==B[k]){
						cont++;
						break;
					}
				}
			}

		}
	}
	
	cout <<cont<<endl;
	return 0;
}