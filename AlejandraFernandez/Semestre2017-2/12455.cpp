#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int largo;
		cin>>largo;
		int nums;
		cin>>nums;
		vector <bool> hola(20000,false);
		hola[0] = true;
		vector <int> num;
		for(int j=0;j<nums;j++){
			int valor;
			cin>>valor;
			num.push_back(valor);
			hola[valor] = true;
			for(int aux2 = num.size()-1;aux2>=0;aux2--){
				if(valor == num[aux2]) continue;
				hola[valor+num[aux2]] = true;
				num.push_back(valor+num[aux2]);
			}
		}
		if(hola[largo])cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}

	return 0;
}