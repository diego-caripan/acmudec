
#include <iostream>

using namespace std;


int main(){
	
	int n,array[100][100];

	cin >> n;


for(int i = 0; i <n; i++){
	for(int j = 0; j< n;j++){
			cin >> array[i][j];
	}
}

int f = 0;


for(int k = 1; k < n ; k++){

	int f=k-1;
	for(int j= 0; j <= k, f >=0; j++, f-- )

		cout << array[f][j] << " ";
		
}

	f=0;
	for(int j= n-1; f <= n, j >=0; j--, f++ )
		cout << array[j][f] << " ";
		

	for(int v = n-1 ; v>=0; v--){

	f = n -v;
	for (int w = n-1; w >= 0,f <= n-1; w--,f++){
	
		cout << array[w][f] << " ";
		
	}
	}

cout << "\n";

 return 0;
}
