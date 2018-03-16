#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,f,n;
	char c;
	vector<int> v;
	cin >> n;
	for(int k=0 ; k<n ; k++){
		if(k!=0)
			cout << endl;
		cin >> a;
		cin >> f;
		for(int x=0 ; x<f ; x++){
			int i=1,cont=1;
			while(i > 0){
				for(int j=0 ; j<i ; j++)
					cout << i;
				cout << endl;
				if(cont < a)
					i++;
				else
					i--;
				cont++;
			}
			if(x < f-1)
				cout << endl;
		}
	}
	return 0;
}