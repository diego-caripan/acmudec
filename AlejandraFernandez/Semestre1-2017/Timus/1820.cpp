#include <iostream>
using namespace std;

int main(){
	int bistocos,k;
	cin>>bistocos>>k;
	if(k>= bistocos) cout<<2;
	else if((bistocos*2)%k==0) cout<< bistocos*2/k;
	else if((bistocos*2)%k != 0) cout<< bistocos*2/k +1;

	return 0;
	}