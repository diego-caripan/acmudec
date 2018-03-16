/*
	codigo propio
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll day(int d, int m, int y){
	y+=8000;
	if(m<3){
		y--;
		m+=12;
	}
	return (y*365)+(y/4)-(y/100)+(y/400)-1200820+(m*153+3)/5-92+d-1;
}

int main(){
	int n;
	while(cin>>n && n){
		int d,y,m,c;
		int da,ca,sum=0,sumc=0;
		cin>>d>>m>>y>>ca;
		da=day(d,m,y);
		for(int i=1;i<n;i++){
			cin>>d>>m>>y>>c;
			d=day(d,m,y);
			if(d==da+1){
				sumc+=c-ca;
				sum++;
			}
			da=d;
			ca=c;
		}
		cout<<sum<<" "<<sumc<<endl;
	}
	return 0;
}
