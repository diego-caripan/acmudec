#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	cin>>n;
	vector <int> v;
	while(n!=0){
	for(int i =0;i<2*(n+1);i++){
			cin>>k;
			v.push_back(k);
	}
	for(int i=2;i<2*(n+1);i=i+2){
		if(v[0]<v[i]){
			if(v[1]<v[i+1]){
				cout<<"NE"<<endl;
			}
			else if(v[1]>v[i+1]){
				cout<<"SE"<<endl;
			}
			else cout<<"divisa"<<endl;
		}
		else if(v[0]>v[i]){
			if(v[1]<v[i+1]){
				cout<<"NO"<<endl;
			}
			else if(v[1]>v[i+1]){
				cout<<"SO"<<endl;
			}
			else cout<<"divisa"<<endl;
		}
		else cout<<"divisa"<<endl;
	}
	v.clear();
	cin>>n;
	}
	return 0;
}