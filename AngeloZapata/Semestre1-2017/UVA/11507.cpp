#include <bits/stdc++.h>
using namespace std;

int main(){

	int t,x,y,z; 
	string decision;

	while(1){
		cin >> t;
		if (t==0) return 0;
		x=1;
		y=0;
		z=0;
		for(int i=0; i<t-1; i++){
			cin >> decision;
			if (decision.compare("+y")==0 && z==0){
				if (x!=0){
					y = x;
					x = 0;
				}
				else{
					y++;
				}
			}
			else if (decision.compare("-y")==0 && z==0){
				if (x!=0){
					y = -x;
					x = 0;
				}
				else{
					y--;
				}
			}
			else if (decision.compare("+z")==0 && y==0){
				if (x!=0){
					z = x;
					x = 0;
				}
				else{
					z++;
				}
			}
			else if (decision.compare("-z")==0 && y==0){
				if (x!=0){
					z = -x;
					x = 0;
				}
				else{
					z--;
				}
			}
			if (x==0 && y==0 && z==0){
				x=1;
				y=0;
				z=0;
			}
			else if(x==0 && (y==2 || y==-2 || z==2 || z==-2)){
				x=-1;
				z=0;
				y=0;
			}
		}
		if (x==1) cout <<" +x" << endl;

		else if (x==-1) cout << "-x" << endl;

		else if (y==1) cout << "+y" << endl;

		else if (y==-1) cout << "-y" << endl;

		else if (z==1) cout << "+z" << endl;

		else if (z==-1) cout << "-z" << endl;

	}
}