#include <bits/stdc++.h>
using namespace std;

int main(){
	float U,fatiga,h,H,D,F,dia;
	while(cin>>H>>U>>D>>F;){
		if(H==0)break;
		dia=1;
		h=0;
		fatiga=U*F/100;
		while(1){
			h+=U;
			if(U>0)U-=fatiga;
			if(h>H)break;
			h-=D;
			if(h<0)break;
			dia++;
		}
	if(h>H)cout<<"success on day "<<dia<<endl;
	else cout<<"failure on day "<<dia<<endl;
	}
	return 0;
}