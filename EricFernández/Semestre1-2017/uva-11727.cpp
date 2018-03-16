//uva-11727
#include <iostream>

using namespace std;

int main(){
	int T,a,b,c;
	cin >> T;
	int ar[T];//guarlos para luego imprimir
	for(int i=0;i<T;i++){
		cin>>a;
		cin>>b;
		cin>>c;
		if(a>=b && b>=c || a<=b && b<=c)ar[i]=b;//b
		if(a>=c && c>=b || a<=c && c<=b)ar[i]=c;//c
		if(b>=a && a>=c || b<=a && a<=c)ar[i]=a;//a
	}
	for(int i=0;i<T;i++){
		cout<< "Case " << i+1 <<": "<< ar[i] << std::endl;
	}
	return 0;
}
