#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a; i< b; i++)
#define D(a) cout << a << "\n"

int main(){

	int times, x=1, y=0, z=0; 
	string command;
	char type;

	while(1){
		cin >> times;
		if (times==0) break;
		x=1;y=0;z=0;
		REP(i,0,times-1){
			cin >> command;
			if (command.compare("+z")==0 && y==0){
				if (x!=0){
					z = x*1;
					x = 0;
				}
				else{
					z += 1;
				}
			}
			else if (command.compare("-z")==0 && y==0){
				if (x!=0){
					z = x*-1;
					x = 0;
				}
				else{
					z += -1;
				}
			}
			else if (command.compare("+y")==0 && z==0){
				if (x!=0){
					y = x*1;
					x = 0;
				}
				else{
					y += 1;
				}
			}
			else if (command.compare("-y")==0 && z==0){
				if (x!=0){
					y = x*-1;
					x = 0;
				}
				else{
					y += -1;
				}
			}

			if (x==0 && y==0 && z==0){x=1;y=0;z=0;}
			else if(x==0 && (y==2 || y==-2 || z==2 || z==-2)){x=-1;z=0;y=0;}
		}
		if (x==1) D("+x");
		else if (x==-1) D("-x");
		else if (y==1) D("+y");
		else if (y==-1) D("-y");
		else if (z==1) D("+z");
		else if (z==-1) D("-z");

	}

	return 0;
}