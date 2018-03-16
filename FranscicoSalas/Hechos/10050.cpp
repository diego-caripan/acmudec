#include <iostream>

using namespace std;

int main(){

	int cases, days, ppartys;

	cin >> cases;

	while(cases--){
		days = 0;
		ppartys = 0;
		int hartal = 0;
		cin >> days >> ppartys;
		int v[ppartys];
		for(int i = 0; i < ppartys; i++){
			cin >> v[i];
		}
		for(int i = 1; i <= days; i++){
			bool found = false;
			if(i%7 != 6 && i%7 != 0){
				for(int j = 0; j < ppartys; j++){
					if(i%v[j] == 0)
						found = true;
				}
			}
			if(found)
				hartal++;
		}
		cout << hartal << endl;

	}

}