#include <iostream>

using namespace std;


int main(){
	
	int n,k;
	int tiempo=0;

	cin >> n;
	cin >> k;


if(n<k)
  tiempo = 2;
	
else  if (n % k != 0) 
            tiempo = 2 * (n / k + 1);
        
else   tiempo 7 = 2 * n / k;
     
 	
	

cout << tiempo;	

 return 0;
}
