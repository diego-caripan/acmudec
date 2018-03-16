#include <bits/stdc++.h>
using namespace std;

int main(){
	vector <int> a,aux;
	int n,num;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		a.push_back(num);
	}
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		for(int j=0;j<a.size();j++){
			if(num==a[j]) aux.push_back(num); 
		}
	}
	a.clear();
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		for(int j=0;j<aux.size();j++){
			if(num==aux[j]) a.push_back(num);
		}
	}
	if(a.empty()) cout<<"0"<<endl;
	else{
		cout<<a.size()<<endl;
	}
	return 0;
}