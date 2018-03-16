#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	
	int cases;
	int k;
	int n, m;


	while(cin >> cases && cases!=0){

		cin >> n;
		cin >> m;

		int i, x, y;
		while(cases){
			
			cin >> x;
			cin >> y;

			if(x == n || y == m){
				cout << "divisa" << endl;
			}
			
			else if(x>n && y>m){
				cout << "NE" << endl;
			}
			
			else if(x<n && y>m){
				cout << "NO" << endl;
			}

			else if(x<n && y<m){
				cout << "SO" << endl;	
			}
		
			else cout << "SE" << endl;

			cases--;
		}


	}
	
	return 0;
}
