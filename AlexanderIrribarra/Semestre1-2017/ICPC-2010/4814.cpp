/*
	CODIGO PROPIO
*/

#include <bits/stdc++.h>

using namespace std;
	
vector<int> a(3);
vector<int> b(2);
vector<int> x(3);
vector<int> y(3);
bool solve(int n){
	do{
		int wins=0;
		for(int i=0;i<3;i++){
			//cout<<x[i]<<" "<<y[i]<<endl;
			if(x[i]<y[i]){
				wins++;
			}
		}
		//cout<<wins<<endl;
		if(wins<2){
			return false;
		}

	}while(next_permutation(y.begin(),y.end()));
	//cout<<"asdasd"<<endl;
	return true;
}
int main(){
	int aux;
	while(cin>>a[0]>>a[1]>>a[2]>>b[0]>>b[1] &&a[0]&&a[1]&&a[2]&&b[0]&&b[1]){
		vector<bool> used(53,false);
		for(int i=0;i<3;i++){
			used[a[i]]=true;
		}
		for(int i=0;i<2;i++){
			used[b[i]]=true;
		}
		
		bool w=false;
		for(int i=1;i<=52;i++){
			
			if(!used[i]){
				x=a;
				y[0]=b[0],y[1]=b[1],y[2]=i;
				sort(y.begin(),y.end());
				if(solve(i)){
					cout<<i<<endl;
					w=true;
					break;
				}
			}
		}
		if(!w){
			cout<<"-1"<<endl;
		}
	}
	return 0;
}