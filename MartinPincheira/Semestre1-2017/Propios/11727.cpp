#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	
	int cases;
	int i=1;
	int sal1, sal2, sal3;

	cin >> cases;

	if(cases < 20){
		while(cases){

			cin >> sal1;
			cin >> sal2;
			cin >> sal3;

			if(sal3 < sal1 && sal1 < sal2 || sal2 < sal1 && sal1 < sal3){
				cout << "Case " << i << ": " << sal1 << endl;
			}
			else if(sal1 < sal2 && sal2 < sal3 || sal3 < sal2 && sal2 < sal1){
				cout << "Case " << i << ": " << sal2 << endl;
			}
			else cout << "Case " << i << ": " << sal3 << endl;
	
			cases--;
			i++;

		}
	}
	
	return 0;
}
