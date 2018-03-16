#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int H,U,D,F,f;
	int dia,h;
	cin >> H >> U >> D >> F;
	while(H!= 0){
		H = H*100;
		U = U*100;
		D = D*100;
		if(H == 0)
			break;
		dia = 0;
		h = 0;
		f = U/100 *F;
		do{
			h += max(U -(f*dia),0);
			dia++;
			if(h > H){
				cout << "success on day " << dia << endl;
				break;
			}
			h -= D;
			if(h < 0){
				cout << "failure on day " << dia << endl;
				break;
			}
		}while(1);
		cin >> H >> U >> D >> F;
	}
}