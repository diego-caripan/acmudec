#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,i,ceros,j,k,uno,cont,r;
	char a[3][3],x,aux[3][3];
	cin >> N;
	for(k=0 ; k<N; k++){
		for(i=0 ; i<3 ; i++){
			for(j=0 ; j<3 ; j++){
				cin >> x;
				a[i][j] = x;
			}
		}
		uno = 0; cont = 0; r = 0, ceros = 0;
		while(true){
			for(i=0 ; i<3 ; i++){
				for(j=0 ; j<3 ; j++){
					if(i<2 && a[i+1][j]=='1')
						cont++;
					if(i>0 && a[i-1][j]=='1')
						cont++;
					if(j<2 && a[i][j+1]=='1')
						cont++;
					if(j>0 && a[i][j-1]=='1')
						cont++;
					if(a[i][j] == '1')
						uno++;
					else
						ceros++;
					if(cont==0 || cont%2==0)
						aux[i][j] = '0';
					else
						aux[i][j] = '1';
					cont = 0;
					//cout << "a: " << a[i][j] << endl;
				}
			}
		for(i=0 ; i<3 ; i++){
			for(j=0 ; j<3 ; j++){
				a[i][j] = aux[i][j];
			}
		}
			if(ceros == 9)
				break;
			r++;
			cont = 0;
			ceros = 0;
		}
		if(uno > 0)
			cout << r-1 << endl;
		else
			cout << "-1" << endl;
	}
	return 0;
}