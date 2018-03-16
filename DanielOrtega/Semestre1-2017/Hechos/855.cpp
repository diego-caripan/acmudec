#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

int casos,bloques,calles,avenidas,amigos,auxx,auxy;
vector<int> x,y;
cin >> casos;

while(casos--){
int sumax=0,sumay=0;	
cin >> calles >> avenidas >> amigos;

	for (int i = 0; i < amigos ; i++){
		cin >> auxx >> auxy;
			x.push_back(auxx);
			y.push_back(auxy);
}
sort (x.begin(), x.end());
sort (y.begin(), y.end());


	
	if(amigos%2!=0)
printf("(Street: %d, Avenue: %d)\n",x[amigos/2],y[amigos/2]);

else{
printf("(Street: %d, Avenue: %d)\n",x[(amigos/2)-1],y[(amigos/2)-1]);


}
	
x.clear();
y.clear();

}

return 0;
}
