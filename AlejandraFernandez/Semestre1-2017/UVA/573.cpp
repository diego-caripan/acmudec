#include <bits/stdc++.h>
using namespace std;

int main(){
	
	float H,D,F,U,nico;
	while(cin>>H>>U>>D>>F && H!=0){
		float total=0;
		float resto;
		nico=1;
		resto=U*F/100;
		while(true){
			total = U+total;
			U=U-resto;
			if(U<0) U=0;
			if(total>H){
				cout<<"success on day "<<nico<<endl;
				break;
			}
			total= total -D;
			if(total<0){
				cout<<"failure on day "<<nico<<endl;
				break;
			}
			nico++;
		}
	}
	return 0;
}
