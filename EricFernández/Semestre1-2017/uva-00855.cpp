#include <bits/stdc++.h>
using namespace std;

int main(){

int C,call,ave,amig,ax,ay;
vector<int> vx,vy;
cin >> C;

while(C--){
	int sumax=0,sumay=0;	
	cin >> call >> ave >> amig;

	for (int i = 0; i < amig ; i++){
		cin >> ax >> ay;
			vx.push_back(ax);
			vy.push_back(ay);
	}
	sort (vx.begin(), vx.end());
	sort (vy.begin(), vy.end());

	if(amig%2!=0){
		//cout<<"(Street: "<<vx[amig/2]<<" Avenue: "<<vy[amig/2]<<")"<<endl;
		printf("(Street: %d, Avenue: %d)\n",vx[amig/2],vy[amig/2]);
	}

	else{
		//cout<<"(Street: "<<vx[amig/2-1]<<" Avenue: "<<vy[amig/2-1]<<")"<<endl;;
		printf("(Street: %d, Avenue: %d)\n",vx[(amig/2)-1],vy[(amig/2)-1]);
	}
	
	vx.clear();
	vy.clear();
}
return 0;
}
