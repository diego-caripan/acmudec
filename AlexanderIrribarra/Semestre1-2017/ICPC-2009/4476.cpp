/*
	CODIGO PROPIO

*/
#include <bits/stdc++.h>

using namespace std;

int tomon(int watt){
	int res=0;
	if(watt<=100){
		res+=watt*2;
	}else{
		watt-=100;
		res+=200;
		if(watt<=9900){
			res+=watt*3;
		}else{
			watt-=9900;
			res+=9900*3;
			if(watt<=990000){
				res+=watt*5;
			}else{
				watt-=990000;
				res+=990000*5;
				res+=watt*7;
			}
		}
	}
	return res;
}

int towatt(int mon){
	int res=0;
	if(mon<=200){
		res+=mon/2;
	}else{
		res+=100;
		mon-=200;
		if(mon<=29700){
			res+=mon/3;
		}else{
			res+=9900;
			mon-=29700;
			if(mon<=4950000){
				res+=mon/5;
			}else{
				res+=990000;
				mon-=4950000;
				res+=mon/7;
			}
		}
	}
	return res;
}

int main(){
	int a,b;
	while(cin>>a>>b && a+b){
		// a=tomon(vecino+yo);
		// b= tomon(vecino)-tomon(yo)
		int watts=towatt(a);
		int l=0,r=watts/2,m;
		while(1){
			m=(l+r)/2;
			//cout<<m<<endl;
			//cout<<m<<": "<<tomon(m)<<endl;
			if(abs(tomon(watts-m)-tomon(m))<b){
				r=m;
			}else if(abs(tomon(watts-m)-tomon(m))>b){
				l=m+1;
			}else{
				//cout<<"aaaaaaa"<<endl;
				break;
			}
		}
		cout<<min(tomon(m),tomon(watts-m))<<endl;
	}
	return 0;
} 