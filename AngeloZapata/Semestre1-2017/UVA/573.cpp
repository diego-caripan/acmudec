#include <bits/stdc++.h>
using namespace std;

int main(){

	float h,u,d,f,day=1,fat,h1;
	
	while(1){
		cin >> h >> u >> d >> f;
		if(h==0) return 0;
		h1=0;
		fat = u*f/100;
		while(1){
			h1+=u;
			u-=fat;
			if(u < 0) u=0;
			if(h1 > h){
				cout << "success on day " << day << endl;
				break;
			}
			h1-=d;
			if(h1<0){
				cout << "failure on day " << day << endl;
				break;
			}
			
			day++;
		}
		h=u=d=f=fat=h1=0;
		day=1;
	}
}