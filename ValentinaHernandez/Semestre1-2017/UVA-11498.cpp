#include <iostream>
using namespace std;

int main(){
	int n,i,x,y,a,b;
	cin >> n;
	while(n != 0){
		cin >> x;
		cin >> y;
		for(i=0 ; i<n ; i++){
			cin >> a;
			cin >> b;
			if(a == x || b == y)
				cout << "divisa" << endl;
			else if(a > x){
				if(b > y)
					cout << "NE" << endl;
				else if(b < y)
					cout << "SE" << endl;
			}
			else if(a < x){
				if(b > y)
					cout << "NO" << endl;
				else if(b < y)
					cout << "SO" << endl;
			}
		}
		cin >> n;
	}
	return 0;
}