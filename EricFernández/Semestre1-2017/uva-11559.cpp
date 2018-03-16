#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int nP,Pre,nH,nF,minCost,vaH,camas;

	while(cin>>nP>>Pre>>nH>>nF){
		minCost=Pre+100;
		while(nH--){
		cin>>vaH;
		for(int i=0;i<nF;i++){
				cin>>camas;
				if(camas>=nP){
					minCost = min(minCost,nP*vaH);
					//string s;
					//getline(cin, s);
					break;
				}
			}	
		}
		if(minCost<=Pre)cout<<minCost<<endl;		
		else cout<<"stay home"<<endl;
	}
	return 0;

}