#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n,m,total=0;
	cin>>n;
	while(n){
		priority_queue <int> vec;
		for(int i=0;i<n;i++){
			cin>>m;
			vec.push(m*-1);
		}
		while(vec.size()>1){
			int a=vec.top()*-1;
			vec.pop();
			int b=vec.top()*-1;
			vec.pop();
			vec.push((a+b)*-1);
			total+=a+b;
		}
		cout<<total<<endl;
		total=0;
		cin>>n;
	}
	return 0;
}