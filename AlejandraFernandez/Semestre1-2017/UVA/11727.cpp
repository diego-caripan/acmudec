#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n,salary;
	cin>>n;
	vector <int> v;
	for (int i=1; i<=3*n; i++){
		cin>>salary;
		v.push_back(salary);
		if(i%3==0){
		sort(v.begin(),v.end());
		cout<<"Case "<<i/3<<": "<<v[1]<<endl;
		v.clear();
		}
	}	
	return 0;
}