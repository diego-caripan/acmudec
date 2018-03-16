#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,x,i,n,b;
	vector<int> v,jj;
	//cin >> n;
	while(cin >> n){
	//	cin >> n;
	//	if(n == EOF || n<0 || n>3000)
	//		break;
	for(i=0 ; i<n ; i++){
		cin >> x;
		v.push_back(x);
	}
	b = n;
	for(i=0 ; i<v.size()-1 ;i++){
		a = abs( v[i] - v[i+1] ) ;
		jj.push_back(a);
	}
	b = 0;
	sort(jj.begin(),jj.end());
	for(i=0 ; i<jj.size() ; i++){
		if(jj[i] == i+1)
			b++;
	}
	if(b == jj.size() || v.size() == 1)
		cout << "Jolly" << endl;
	else
		cout << "Not jolly" << endl;
	v.clear();
	jj.clear();
	}
	return 0;
}