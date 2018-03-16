#include <iostream>
using namespace std;

int main(){
	int i,t,n,ma,me,x,y,z;
	cin >> t;
	int a[3], r[t];
	for(i=0 ; i<t ; i++){
		cin >> x >> y >> z;
		if( (x>y && x<z) || (x<y && x>z) )
			r[i] = x;
		else if( (y>x && y<z) || (y<x && y>z) )
			r[i] = y;
		else if( (z>x && z<y) || z<x && z>y )
			r[i] = z;
	}
	for(i=0 ; i<t ; i++)
		cout << "Case " << i+1 << ": " << r[i]<< endl;
	return 0;
}