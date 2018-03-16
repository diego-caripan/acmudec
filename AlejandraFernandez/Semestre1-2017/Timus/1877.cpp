#include <iostream>
using namespace std;

int main (){
	int a,b,l;
	l=0;
	cin>>a;
	cin>>b;
		if((b%2)!= 0) l=1;
		if((a%2)== 0)l=1;
			if(l==1) cout<< "yes";
			else cout<< "no";

}