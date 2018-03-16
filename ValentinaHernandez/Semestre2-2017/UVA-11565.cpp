#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
typedef pair<int,par> parip;

bool check(int A, int B, int C, int x, int y){
	int z = A-x-y;
	if(x == 0 || y == 0 || x == y || x == z || y == z){
		return false;
	}
	else{
		if( x*y*z == B ){
			if( (x*x+y*y+z*z) == C){
				return true;
			}
			else return false;
		}
		else return false;
	}
}

int main(){
	int A,B,C,x,y,z,N;
	cin >> N;
	for(int n=0 ; n<N ; n++){
		bool r = false;
		cin >> A >> B >> C;
		for(x=-58 ; x<=58 ; x++){
			//if(x != 0)
			for(y=-22 ; y<=22 ; y++){
				if(check(A,B,C,x,y)){
					z = A-x-y;
					if(y > z) swap(y,z);
					if(x > y) swap(x,y);
					cout << x << " " << y << " " << z << "\n";
					r = true;
					break;
				}
			}
			if (r){
				break;
			}
		}
		if(!r) cout << "No solution.\n";
	}
	return 0;
}