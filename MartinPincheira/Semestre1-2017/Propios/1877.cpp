#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	

	int x, y;

	scanf("%d", &x);
	scanf("%d", &y);

	if(x%2 == 0 || y%2 == 1) cout << "yes" << endl;
	
	else cout << "no" << endl;

	return 0;
}
