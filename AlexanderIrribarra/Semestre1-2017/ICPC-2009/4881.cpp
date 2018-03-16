/*
	CODIGO PROPIO

*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	map<char,float> d;
	d['W']=1;
	d['H']=0.5;
	d['Q']=0.25;
	d['E']=0.125;
	d['S']=d['E']*0.5;
	d['T']=d['E']*0.25;
	d['X']=d['E']*0.125;
	string str;
	while(cin >> str && str!="*"){
		int res=0;
		double dur=0;
		for(int i=0;i<str.length();i++){
			if(str[i]=='/'){
				if(dur==1){
					res++;
				}
				dur=0;
			}else{
				dur+=d[str[i]];
			}
		}
		cout<<res<<endl;
	}
	return 0;
}