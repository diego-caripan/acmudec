/*
	codigo propio
*/

#include <bits/stdc++.h>

using namespace std;

int count(vector<int> &v,int num){
	int pot=1;
	while(num/pot){
		int a=num/(pot*10),b=num%pot;	//numero a forma adb
		int d=(num/pot)%10;

		for(int i=0;i<10;i++){
			v[i]+=a*pot;
			if(i==d){
				v[i]+=b+1;
			}else if(d>i){
				v[i]+=pot;
			}
		}
		pot*=10;	
	}
	v[0]-=(pot-1)/9;
}

int main(){
	int a,b;
	while(scanf("%d %d",&a,&b)&&(a||b)){
		vector<int> c(10,0),d(10,0);
		if(a-1>0)
			count(c,a-1);
		count(d,b);
		cout<<d[0]-c[0];
		for(int i=1;i<10;i++){
			cout<<" "<<d[i]-c[i];
		}
		cout<<endl;
	}
	return 0;
}