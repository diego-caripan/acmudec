#include <bits/stdc++.h>
using namespace std;

bool derif(int A, int B){
	int num = 0;

	int cont1, cont2=5;
	if (A < 10000) {
		cont1=4;
		num |= 1;
	}
	
	else cont1=5;

	if (B < 10000) return false;
	//cout << 1 << endl;

	int aux;
	for (int i = 0; i < cont1; ++i)
	{
		aux = A%10;
		//cout << A << " " << aux << " " << (num & (1<<aux)) << " " << 3 << endl;
		if ((num & (1<<aux)) == 0) num |= 1 << aux;
		else return false;
		A /= 10;
	}

	for (int i = 0; i < cont2; ++i)
	{
		aux = B%10;
		//cout << B << " " << aux << " " << (num & (1<<aux)) << " " << 3 << endl;
		if ((num & (1<<aux)) == 0) num |= 1 << aux;
		else return false;

		B /= 10;
	}

	//cout << 4 << endl;
	return true;

}

int main(){
	int N, nuev;
	bool verif;
	scanf("%d", &N);
	bool cosa = false;
	while(N!=0){
		if (cosa) printf("\n");
		verif = false;
		for (int i = 1234; i < 99999 ; ++i)
		{
			nuev = i*N;
			if (nuev > 99999) break;
			//printf("%d\n", i);

			if (derif(i,nuev)){
				if (i < 10000) printf("%d / 0%d = %d\n",nuev, i, N );
				else printf("%d / %d = %d\n", nuev, i, N );
				verif = true;
			}
		}

		if (!verif) printf("There are no solutions for %d.\n", N );

		scanf("%d", &N);
		cosa = true;
	}
}