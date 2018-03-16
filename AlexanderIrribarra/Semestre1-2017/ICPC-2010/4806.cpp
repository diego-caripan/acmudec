/*
	codigo propio
*/

#include <bits/stdc++.h>

using namespace std;
int abs(int x){
	return (x>0)?x:-x;
}
int main(){
	int n,b;
	cin>>n>>b;
	while(n!=0){
		vector<int> balls;
		vector<int> pos(n,false);
		for(int i=0;i<b;i++){
			int aux;
			balls.push_back(aux);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j){
					pos[abs(balls[i]-balls[j])]
				}
			}
		}
		cin>>n>>b;
	}
}